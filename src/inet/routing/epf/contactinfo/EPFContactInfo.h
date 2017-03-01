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

#ifndef INET_ROUTING_EPF_CONTACTINFO_EPFCONTACTINFO_H_
#define INET_ROUTING_EPF_CONTACTINFO_EPFCONTACTINFO_H_

#include <omnetpp.h>
#include <map>
#include <list>
#include "inet/networklayer/common/L3Address.h"

using namespace omnetpp;

namespace inet {

class EPFContactInfo {

    std::map<int, simtime_t> contactDuration;
    std::map<int, L3Address> addressList;
    std::map<int, std::list<simtime_t>> contactHistory;

public:
    EPFContactInfo();
    virtual ~EPFContactInfo();

    void updateContactDuration(int device, simtime_t contactTime);
    simtime_t getContactDuration(int device);
    L3Address getAddress(int device);
    void setAddress(int device, L3Address addr);

    void toString();


};

} /* namespace inet */

#endif /* INET_ROUTING_EPF_CONTACTINFO_EPFCONTACTINFO_H_ */
