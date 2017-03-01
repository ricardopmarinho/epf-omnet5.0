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

package inet.routing.epf;

//
// Ad hoc On-Demand Distance Vector Routing Protocol module.
//
// The Content and Social Behavour (EPF) routing protocol is
// intended for use by mobile nodes in an ad hoc network. It offers
// quick adaptation to dynamic link conditions, low processing and
// memory overhead, low network utilization, and determines unicast
// routes to destinations within the ad hoc network.
//
// This routing protocol communicates over UDP and used in ~EPFRouter
// nodes as a routing submodule. ~EPFRouter is just a ~WirelessHost
// extended with ~EPFRouting submodule.
//
// This implementation is based on RFC 3561. For more information, you may
// refer to the following link: https://tools.ietf.org/html/rfc3561.html.
//
simple EPFRouting
{
    parameters: 
        
        @signal[rreqSent](type="long");
        @signal[rrepSent](type="long");
        @signal[rreqRec](type="long");
        @signal[rreq1Rec](type="long");
        @signal[rrepRec](type="long");
        @signal[rrep1Rec](type="long");
        @signal[rrep2Rec](type="long");
        @statistic[rreqSent](title="Sent RREQ"; source="rreqSent"; record=vector,count; interpolationmode=none);
        @statistic[rrepSent](title="Sent RREP"; source="rrepSent"; record=vector,count; interpolationmode=none);
        @statistic[rreqRec](title="Received RREQ"; source="rreqRec"; record=vector,count; interpolationmode=none);
        @statistic[rreq1Rec](title="Received type 1 RREQ"; source="rreq1Rec"; record=vector,count; interpolationmode=none);
        @statistic[rrepRec](title="Received RREP"; source="rrepRec"; record=vector,count; interpolationmode=none);
        @statistic[rrep1Rec](title="Received type 1 RREP"; source="rrep1Rec"; record=vector,count; interpolationmode=none);
        @statistic[rrep2Rec](title="Received type 2 RREP"; source="rrep2Rec"; record=vector,count; interpolationmode=none);
        
        @signal[enquireSent](type="long");
        @signal[enquireRec](type="long");
        @signal[respSent](type="long");
        @signal[respRec](type="long");
        @signal[respOkSent](type="long");
        @signal[respOkRec](type="long");
        @signal[respNOkSent](type="long");
        @signal[respNOkRec](type="long");
        @signal[destEnq](type="long");
        @signal[destResp](type="long");
        @signal[dataSent](type="long");
        @signal[dataDest](type="long");
        @signal[dataRec](type="long");
        @signal[dataFwd](type="long");
        @statistic[enquireSent](title="Sent Enquire message"; source="enquireSent"; record=vector,count; interpolationmode=none);
        @statistic[enquireRec](title="Received Enquire message"; source="enquireRec"; record=vector,count; interpolationmode=none);
        @statistic[respSent](title="Sent Response message"; source="respSent"; record=vector,count; interpolationmode=none);
        @statistic[respRec](title="Received Response message"; source="respRec"; record=vector,count; interpolationmode=none);
        @statistic[respOkSent](title="Sent Ok Response message"; source="respOkSent"; record=vector,count; interpolationmode=none);
        @statistic[respOkRec](title="Received Ok Response message"; source="respOkRec"; record=vector,count; interpolationmode=none);
        @statistic[respNOkSent](title="Sent Not Ok Response message"; source="respNOkSent"; record=vector,count; interpolationmode=none);
        @statistic[respNOkRec](title="Received Not Ok Response message"; source="respNOkRec"; record=vector,count; interpolationmode=none);
        @statistic[destEnq](title="Enquire to Destination"; source="destEnq"; record=vector,count; interpolationmode=none);
        @statistic[destResp](title="Response from destination"; source="destResp"; record=vector,count; interpolationmode=none);
        @statistic[dataSent](title="Sent Data message"; source="dataSent"; record=vector,count; interpolationmode=none);
        @statistic[dataRec](title="Received Data message"; source="dataRec"; record=vector,count; interpolationmode=none);
        @statistic[dataDest](title="Received Data message on Destination"; source="dataDest"; record=vector,count; interpolationmode=none);
        @statistic[dataFwd](title="Forward Data message"; source="dataFwd"; record=vector,count; interpolationmode=none);
        
        int numSocialNetworks = default(2);
        @display("i=block/network2");
        string routingTableModule = default("^.routingTable");
        string interfaceTableModule = default("^.interfaceTable");
        string networkProtocolModule = default("^.networkLayer.ip");

        bool askGratuitousRREP = default(false); // see RFC 3561: 6.6.3
        bool useHelloMessages = default(false); // see RFC 3561: 6.9
        bool useLocalRepair = default(false); // see RFC 3561: 6.12 *not implemented yet*
        int udpPort = default(654);

        double maxPeriodicJitter @unit("s") = default(helloInterval / 4); // it MUST NOT be negative; it MUST NOT be greater than MESSAGE_INTERVAL/2; it SHOULD NOT be greater than MESSAGE_INTERVAL/4.
        volatile double periodicJitter @unit("s") = default(uniform(0s, maxPeriodicJitter)); // jitter for externally triggered message generation and message forwarding

        // RFC 5148:
        // need more revise: As well as the decision as to whether
        // to use jitter being dependent on the medium access control and
        // lower layers, the selection of the MAXJITTER parameter SHOULD
        // be appropriate to those mechanisms.
        double maxJitter @unit("s") = default(5ms);
        volatile double jitter @unit("s") = default(uniform(0ms, maxJitter)); // jitter for broadcasts

        double helloInterval @unit("s") = default(1s); // every helloInterval seconds a node broadcasts Hello messages (if it is necessary)
        int allowedHelloLoss = default(2); // allowedHelloLoss * helloInterval is the lifetime value for Hello messages
        double activeRouteTimeout @unit("s") = default(3s); // the timeout value for cached routes If Hello messages are used, then the
                                                            // ACTIVE_ROUTE_TIMEOUT parameter value MUST be more than the value
                                                            // (ALLOWED_HELLO_LOSS * HELLO_INTERVAL).
        int netDiameter = default(35); // the maximum possible number of hops between two nodes in the network
        double nodeTraversalTime @unit("s") = default(0.04s); // an estimation of the average one-hop traversal time
        int rerrRatelimit = default(10); // maximum number of RERR messages that the EPF may originate in 1s.
        int rreqRetries = default(2); // specifies the number of times EPF will repeat an expanded ring search for a destination
        int rreqRatelimit = default(10); // maximum number of RREQ messages that the EPF may originate in 1s.
        int timeoutBuffer = default(2); // plus time to wait for a delayed RREP (due to congestion) (to omit this buffer set it to 0)
        int ttlStart = default(2); // specifies the TTL value when initiating a route request
        int ttlIncrement = default(2); // specifies the value by which the TTL will be incremented each time a RREQ is retransmitted
        int ttlThreshold = default(7); // the maximum value of TTL over which NET_DIAMETER value will be used to broadcast any RREQ
        int localAddTTL = default(2); // it is used by the formula which calculates the initial TTL of the RREQ for a local repair

        double myRouteTimeout @unit("s") = default(2 * activeRouteTimeout); // the value of the lifetime field that a destination node places in RREPs
        double deletePeriod @unit("s") = default(5 * max(activeRouteTimeout, helloInterval)); // the time after which an expired route is deleted
        double blacklistTimeout @unit("s") = default(rreqRetries * netTraversalTime); // the time after which a blacklisted node is removed from the blacklist
        double netTraversalTime @unit("s") = default(2 * nodeTraversalTime * netDiameter); // an estimation of the traversal time for the complete network
        double nextHopWait @unit("s") = default(nodeTraversalTime + 0.01s); // timeout for a RREP-ACK
        double pathDiscoveryTime @unit("s") = default(2 * netTraversalTime); // buffer timeout for each broadcasted RREQ message
    gates:
        input ipIn;
        output ipOut;
}
