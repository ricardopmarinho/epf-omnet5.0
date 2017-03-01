//
// Copyright (C) 2014 OpenSim Ltd.
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
//

package inet.node.epf;

import inet.node.inet.WirelessHost;
import inet.routing.epf.EPFRouting;
import inet.trickle.Trickletimer;

//
// It models a ~WirelessHost extended with ~EPFRouting submodule.
//
// EPF is an on-demand MANET routing protocol. Each node
// works similar to a 'router': they manage their own routing
// tables, send request for routes and consult the IP layer via
// Netfilter hooks for data forwarding.
//
// Scenerios where EPF routing is desired use this module as a
// host module.
//
// For more info about EPFRouting, see the corresponding module:
// ~EPFRouting and its C++ implementation with the same name.
//
// The EPF v.2 (known as DYMO) is also implemented: ~DYMO,
// ~DYMORouter.
//
module EPFRouter extends WirelessHost
{
    parameters:
        @display("i=device/cellphone");
        forwarding = true;
        wlan[*].mgmtType = default("Ieee80211MgmtAdhoc");
    submodules:
        epf: EPFRouting {
            @display("p=558,307");
        }
        trickle: Trickletimer {
            @display("p=121,277");
        }
    connections:
        epf.ipOut --> networkLayer.transportIn++;
        epf.ipIn <-- networkLayer.transportOut++;
}
