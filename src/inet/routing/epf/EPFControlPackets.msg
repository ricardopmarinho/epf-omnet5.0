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

cplusplus {{
#include "inet/networklayer/common/L3Address.h"
#include "inet/routing/aodv/AODVControlPackets_m.h"
}}

namespace inet;

class noncobject L3Address;
struct UnreachableNode;

packet AODVControlPacket;


//
// Helper struct to represent (L3Address, sequence number) pairs in a RERR message
//
//struct UnreachableNode
//{
//    L3Address addr;
//    unsigned int seqNum;
//};

enum EPFControlPacketType
{
//	RREQ = 1;
//	RREP = 2;
//	RERR = 3;
//	RREPACK = 4;
//	ContactInfo=5;
	Enquire = 6;
	Response = 7;
	Data = 8;
	ContactInfoMsg = 9;
};

//
// Base packet for EPF Control Packets
//
packet EPFControlPacket extends AODVControlPacket
{
}

//
// Represents an EPF Route Request
//
class EPFRREQ extends EPFControlPacket
{
    unsigned int packetType = RREQ;
    bool joinFlag;
    bool repairFlag;
    bool gratuitousRREPFlag;
    bool destOnlyFlag;
    bool unknownSeqNumFlag;
    unsigned int hopCount;
    unsigned int rreqId;
    L3Address destAddr;
    unsigned int destSeqNum;
    L3Address originatorAddr;
    unsigned int originatorSeqNum;
}

//
// Represents an EPF Route Reply
//
class EPFRREP extends EPFControlPacket
{
    unsigned int packetType = RREP;
    bool repairFlag;
    bool ackRequiredFlag;
    unsigned int prefixSize;
    unsigned int hopCount;
    L3Address destAddr;
    unsigned int destSeqNum;
    L3Address originatorAddr;
    unsigned int originatorSeqNum;
    simtime_t lifeTime;
}

//
// Represents an EPF Route Error
//
class EPFRERR extends EPFControlPacket
{
    unsigned int packetType = RERR;
    UnreachableNode unreachableNodes[];
    bool noDeleteFlag;
    unsigned int destCount;
}

//
// Represents an EPF Route Reply ACK
//
class EPFRREPACK extends EPFControlPacket
{
    unsigned int packetType = RREPACK;
}

class CONTACTINFOMSG extends EPFControlPacket{
    unsigned int packetType = ContactInfoMsg;
    unsigned int hostIndex;
    L3Address sourceAddr;
}

class EnquireMessage extends EPFControlPacket{
    unsigned int packetType = Enquire;
    unsigned int hostIndex;
    unsigned int destIndex;
    unsigned int seqNum;
    unsigned int ownerIndex;
    L3Address sourceAddr;
    L3Address ownerAddr;
    L3Address destAddr;
    simtime_t destContactDuration;
}

class EnquireResponse extends EPFControlPacket{
    unsigned int packetType = Response;
    unsigned int hostIndex;
    unsigned int destIndex;
    unsigned int ownerIndex;
    unsigned int seqNum;
    L3Address sourceAddr;
    L3Address ownerAddr;
    L3Address respondTo;
    L3Address destAddr;
    bool okToSend;
    bool destReached;
}

class DataMessage extends EPFControlPacket{
    unsigned int packetType = Data;
    unsigned int hostIndex;
    unsigned int destIndex;
    unsigned int ownerIndex;
    unsigned int seqNum;
    L3Address sourceAddr;
    L3Address destAddr;
    L3Address respondTo;
    L3Address ownerAddr;
    char data[20];
}

//
// Represents a timer for a Route Reply packet
//
//message WaitForRREP
//{
//    L3Address destAddr;
//    unsigned int lastTTL;
//    bool fromInvalidEntry;
//}
