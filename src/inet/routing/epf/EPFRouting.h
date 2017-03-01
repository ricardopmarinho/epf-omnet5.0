//
// Copyright (C) 2014 OpenSim Ltd.
// Author: Benjamin Seregi
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICUEPF PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
//

#ifndef __INET_EPFROUTING_H
#define __INET_EPFROUTING_H

#include "inet/common/INETDefs.h"
#include "inet/networklayer/contract/IInterfaceTable.h"
#include "inet/networklayer/contract/IL3AddressType.h"
#include "inet/networklayer/contract/IRoutingTable.h"
#include "inet/networklayer/contract/INetfilter.h"
#include "inet/common/lifecycle/ILifecycle.h"
#include "inet/common/lifecycle/NodeStatus.h"
#include "inet/transportlayer/contract/udp/UDPSocket.h"
#include "inet/routing/epf/EPFRouteData.h"
#include "inet/transportlayer/udp/UDPPacket.h"
#include "inet/routing/epf/EPFControlPackets_m.h"
#include "inet/routing/csb/CSBControlPackets_m.h"

#include "inet/common/geometry/common/Coord.h"
//#include "inet/routing/epf/SocialNetwork.h"
#include "inet/routing/epf/contactinfo/EPFContactInfo.h"

namespace inet {

/*
 * This class implements EPF routing protocol and Netfilter hooks
 * in the IP-layer required by this protocol.
 */

class INET_API EPFRouting : public cSimpleModule, public ILifecycle, public INetfilter::IHook, public cListener
{
private:
  protected:
    /*
     * It implements a unique identifier for an arbitrary RREQ message
     * in the network. See: rreqsArrivalTime.
     */
    class RREQIdentifier
    {
      public:
        L3Address originatorAddr;
        unsigned int rreqID;
        RREQIdentifier(const L3Address& originatorAddr, unsigned int rreqID) : originatorAddr(originatorAddr), rreqID(rreqID) {};
        bool operator==(const RREQIdentifier& other) const
        {
            return this->originatorAddr == other.originatorAddr && this->rreqID == other.rreqID;
        }
    };

    class RREQIdentifierCompare
    {
      public:
        bool operator()(const RREQIdentifier& lhs, const RREQIdentifier& rhs) const
        {
            return lhs.rreqID < rhs.rreqID;
        }
    };

    //added
    unsigned int numHosts;
    unsigned int numSocialNetworks;
//    std::vector<SocialNetwork*> SN;
    EPFContactInfo* contactInfo;

    // context
    IL3AddressType *addressType = nullptr;    // to support both IPv4 and v6 addresses.

    // environment
    cModule *host = nullptr;
    IRoutingTable *routingTable = nullptr;
    IInterfaceTable *interfaceTable = nullptr;
    INetfilter *networkProtocol = nullptr;

    // EPF parameters: the following parameters are configurable, see the NED file for more info.
    unsigned int rerrRatelimit = 0;
    unsigned int epfUDPPort = 0;
    bool askGratuitousRREP = false;
    bool useHelloMessages = false;
    simtime_t maxJitter;
    simtime_t activeRouteTimeout;
    simtime_t helloInterval;
    unsigned int netDiameter = 0;
    unsigned int rreqRetries = 0;
    unsigned int rreqRatelimit = 0;
    unsigned int timeoutBuffer = 0;
    unsigned int ttlStart = 0;
    unsigned int ttlIncrement = 0;
    unsigned int ttlThreshold = 0;
    unsigned int localAddTTL = 0;
    unsigned int allowedHelloLoss = 0;
//    unsigned int enqSeqNum  = 0;
    simtime_t nodeTraversalTime;
    cPar *jitterPar = nullptr;
    cPar *periodicJitter = nullptr;

    // the following parameters are calculated from the parameters defined above
    // see the NED file for more info
    simtime_t deletePeriod;
    simtime_t myRouteTimeout;
    simtime_t blacklistTimeout;
    simtime_t netTraversalTime;
    simtime_t nextHopWait;
    simtime_t pathDiscoveryTime;

    // state
    unsigned int rreqId = 0;    // when sending a new RREQ packet, rreqID incremented by one from the last id used by this node
    unsigned int sequenceNum = 0;    // it helps to prevent loops in the routes (RFC 3561 6.1 p11.)
    std::map<L3Address, WaitForRREP *> waitForRREPTimers;    // timeout for Route Replies
    std::map<RREQIdentifier, simtime_t, RREQIdentifierCompare> rreqsArrivalTime;    // maps RREQ id to its arriving time
    L3Address failedNextHop;    // next hop to the destination who failed to send us RREP-ACK
    std::map<L3Address, simtime_t> blacklist;    // we don't accept RREQs from blacklisted nodes
    unsigned int rerrCount = 0;    // num of originated RERR in the last second
    unsigned int rreqCount = 0;    // num of originated RREQ in the last second
    simtime_t lastBroadcastTime;    // the last time when any control packet was broadcasted
    std::map<L3Address, unsigned int> addressToRreqRetries;    // number of re-discovery attempts per address

    // self messages
    cMessage *helloMsgTimer = nullptr;    // timer to send hello messages (only if the feature is enabled)
    cMessage *expungeTimer = nullptr;    // timer to clean the routing table out
    cMessage *counterTimer = nullptr;    // timer to set rrerCount = rreqCount = 0 in each second
    cMessage *rrepAckTimer = nullptr;    // timer to wait for RREP-ACKs (RREP-ACK timeout)
    cMessage *blacklistTimer = nullptr;    // timer to clean the blacklist out
    cMessage *enquire = nullptr;

    std::map<L3Address, DataMessage*> dataMsg;

    //statistics
    simsignal_t rreqSentSignal;
    simsignal_t rrepSentSignal;
    simsignal_t rreqRecSignal;
    simsignal_t rreq1RecSignal;
    simsignal_t rrepRecSignal;
    simsignal_t rrep1RecSignal;
    simsignal_t rrep2RecSignal;

    simsignal_t enquireSentSignal;
    simsignal_t enquireRecSignal;
    simsignal_t respSentSignal;
    simsignal_t respRecSignal;
    simsignal_t respOkSentSignal;
    simsignal_t respNOkSentSignal;
    simsignal_t respOkRecSignal;
    simsignal_t respNOkRecSignal;
    simsignal_t destEnqSignal;
    simsignal_t destRespSignal;
    simsignal_t dataSentSignal;
    simsignal_t dataRecSignal;
    simsignal_t dataDestSignal;
    simsignal_t dataFwdSignal;

    long rreqSent = 0;
    long rrepSent = 0;
    long rreqRec = 0;
    long rreq1Rec = 0;
    long rrepRec = 0;
    long rrep1Rec = 0;
    long rrep2Rec = 0;

    long enquireSent = 0;
    long enquireRec = 0;
    long respSent = 0;
    long respRec = 0;
    long respOkSent = 0;
    long respOkRec = 0;
    long respNOkSent = 0;
    long respNOkRec = 0;
    long destEnq = 0;
    long destResp = 0;
    long dataSent = 0;
    long dataRec = 0;
    long dataDest = 0;
    long dataFwd = 0;

    // lifecycle
    simtime_t rebootTime;    // the last time when the node rebooted
    bool isOperational = false;

    // internal
    std::multimap<L3Address, INetworkDatagram *> targetAddressToDelayedPackets;    // queue for the datagrams we have no route for

  protected:
    void handleMessage(cMessage *msg) override;
    void initialize(int stage) override;
    virtual int numInitStages() const override { return NUM_INIT_STAGES; }

    void initializeSocianNetworks();

    /* Route Discovery */
    void startRouteDiscovery(const L3Address& target, unsigned int timeToLive = 0);
    void completeRouteDiscovery(const L3Address& target);
    bool hasOngoingRouteDiscovery(const L3Address& destAddr);
    void cancelRouteDiscovery(const L3Address& destAddr);

    /* Routing Table management */
    void updateRoutingTable(IRoute *route, const L3Address& nextHop, unsigned int hopCount, bool hasValidDestNum, unsigned int destSeqNum, bool isActive, simtime_t lifeTime);
    IRoute *createRoute(const L3Address& destAddr, const L3Address& nextHop, unsigned int hopCount, bool hasValidDestNum, unsigned int destSeqNum, bool isActive, simtime_t lifeTime);
    bool updateValidRouteLifeTime(const L3Address& destAddr, simtime_t lifetime);
    void scheduleExpungeRoutes();
    void expungeRoutes();

    /* Control packet creators */
    EPFRREPACK *createRREPACK();
    EPFRREP *createHelloMessage();
    EPFRREQ *createRREQ(const L3Address& destAddr);
    EPFRREP *createRREP(EPFRREQ *rreq, IRoute *destRoute, IRoute *originatorRoute, const L3Address& sourceAddr);
    EPFRREP *createGratuitousRREP(EPFRREQ *rreq, IRoute *originatorRoute);
    EPFRERR *createRERR(const std::vector<UnreachableNode>& unreachableNodes);
    CONTACTINFOMSG *createCONTACTINFOMSG();
    EnquireMessage *createEnquireMessage();
    DataMessage* createDataMessage();

    /*Create possible position of receiver*/
    Coord createReceiverCoord(double x,double y,long speed,simtime_t time,unsigned int type);

    /* Control Packet handlers */
    void handleRREP(EPFRREP *rrep, const L3Address& sourceAddr);
    void handleRREQ(EPFRREQ *rreq, const L3Address& sourceAddr, unsigned int timeToLive);
    void handleRERR(EPFRERR *rerr, const L3Address& sourceAddr);
    void handleHelloMessage(EPFRREP *helloMessage);
    void handleRREPACK(EPFRREPACK *rrepACK, const L3Address& neighborAddr);
    void handleCONTACTINFOMSG(CONTACTINFOMSG *contactInfoMsg);
    void handleEnquireMessage(EnquireMessage* enqMsg);
    void handleResponseMessage(EnquireResponse* enqMsg);
    void handleDataMessage(DataMessage* dataMsg);
    /*Contact*/
    //void initializeContactTable();
    void initializeContactInfo();
    //void updateContactInfo(EPFContactInfo *cInfo, L3Address& sourceAddr);
    double calcRouteWeight(const L3Address& nextHop);
    double calcContactWeight(const L3Address& nextHop);

    /* Control Packet sender methods */
    void sendRREQ(EPFRREQ *rreq, const L3Address& destAddr, unsigned int timeToLive);
    void sendRREPACK(EPFRREPACK *rrepACK, const L3Address& destAddr);
    void sendRREP(EPFRREP *rrep, const L3Address& destAddr, unsigned int timeToLive);
    void sendGRREP(EPFRREP *grrep, const L3Address& destAddr, unsigned int timeToLive);
    void sendEnquireMessage(cMessage* msg);
    /* Control Packet forwarders */
    void forwardRREP(EPFRREP *rrep, const L3Address& destAddr, unsigned int timeToLive);
    void forwardRREQ(EPFRREQ *rreq, unsigned int timeToLive);

    /* Self message handlers */
    void handleRREPACKTimer();
    void handleBlackListTimer();
    void sendHelloMessagesIfNeeded();
    void handleWaitForRREP(WaitForRREP *rrepTimer);

    /* General functions to handle route errors */
    void sendRERRWhenNoRouteToForward(const L3Address& unreachableAddr);
    void handleLinkBreakSendRERR(const L3Address& unreachableAddr);
    virtual void receiveSignal(cComponent *source, simsignal_t signalID, cObject *obj DETAILS_ARG) override;

    /* Netfilter hooks */
    Result ensureRouteForDatagram(INetworkDatagram *datagram);
    virtual Result datagramPreRoutingHook(INetworkDatagram *datagram, const InterfaceEntry *inputInterfaceEntry, const InterfaceEntry *& outputInterfaceEntry, L3Address& nextHopAddress) override { Enter_Method("datagramPreRoutingHook"); return ensureRouteForDatagram(datagram); }
    virtual Result datagramForwardHook(INetworkDatagram *datagram, const InterfaceEntry *inputInterfaceEntry, const InterfaceEntry *& outputInterfaceEntry, L3Address& nextHopAddress) override;
    virtual Result datagramPostRoutingHook(INetworkDatagram *datagram, const InterfaceEntry *inputInterfaceEntry, const InterfaceEntry *& outputInterfaceEntry, L3Address& nextHopAddress) override { return ACCEPT; }
    virtual Result datagramLocalInHook(INetworkDatagram *datagram, const InterfaceEntry *inputInterfaceEntry) override { return ACCEPT; }
    virtual Result datagramLocalOutHook(INetworkDatagram *datagram, const InterfaceEntry *& outputInterfaceEntry, L3Address& nextHopAddress) override { Enter_Method("datagramLocalOutHook"); return ensureRouteForDatagram(datagram); }
    void delayDatagram(INetworkDatagram *datagram);

    /* Helper functions */
    L3Address getSelfIPAddress() const;
    void sendEPFPacket(EPFControlPacket *packet, const L3Address& destAddr, unsigned int timeToLive, double delay);
    void clearState();

    /* Lifecycle */
    virtual bool handleOperationStage(LifecycleOperation *operation, int stage, IDoneCallback *doneCallback) override;

  public:
    EPFRouting();
    virtual ~EPFRouting();
};

} // namespace inet

#endif    // ifndef EPFROUTING_H_

