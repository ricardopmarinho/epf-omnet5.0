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

#include "inet/routing/epf/contactinfo/EPFContactInfo.h"
#include <vector>

namespace inet {

EPFContactInfo::EPFContactInfo() {
    // TODO Auto-generated constructor stub
}

EPFContactInfo::~EPFContactInfo() {
    // TODO Auto-generated destructor stub
}

void EPFContactInfo::toString(){

    for(std::map<int, std::list<simtime_t>>::iterator it = contactHistory.begin(); it !=contactHistory.end(); it++){
        EV << "Contact history with: " << it->first << endl;
        std::list<simtime_t> historyList = contactHistory[it->first];
        for(std::list<simtime_t>::iterator l_it =  historyList.begin(); l_it != historyList.end(); l_it++)
            EV << l_it->dbl() << endl;
    }
}

void EPFContactInfo::updateContactDuration(int device, simtime_t contactTime){

    simtime_t duration = SIMTIME_ZERO;
    std::list<simtime_t> contactList = contactHistory[device];

    EV << "Contact occurred on: " << contactTime.dbl() << " seconds." << endl;
    EV << "Sender device index: " << device << endl;

    if(contactHistory[device].empty()){//first contact
        contactHistory[device].push_back(contactTime);
    }else{
        int index=-1;
        int i=0;
        /*check if there is an expired contact (> 120s)*/
        for(std::list<simtime_t>::iterator it = contactHistory[device].begin(); it !=contactHistory[device].end(); it++,i++){
            EV << "i: " << i << ", time: " <<  it->dbl() << endl;
            if((contactTime.dbl()-it->dbl())>=5){
                index=i;
            }
        }
        /*delete expired contacts*/
        if(index == 0){
            contactHistory[device].pop_front();
        }
        else{
            for(i=0;i<index;i++)
                contactHistory[device].pop_front();
        }

        contactHistory[device].push_back(contactTime);

        for(std::list<simtime_t>::iterator it = contactHistory[device].begin(); it !=contactHistory[device].end(); it++)
            duration+=*it;
    }
    contactDuration[device]=duration;
    //contactHistory[device] = contactList;

}
simtime_t EPFContactInfo::getContactDuration(int device){
    return contactDuration[device];
}

L3Address EPFContactInfo::getAddress(int device){
    while(addressList[device].NONE){
        device++;
    }
    return addressList[device];
}

void EPFContactInfo::setAddress(int device, L3Address addr){
        addressList[device]=addr;
}

} /* namespace inet */
