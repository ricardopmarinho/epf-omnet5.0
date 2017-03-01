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

#include "Trickletimer.h"

namespace inet {

Define_Module(Trickletimer);

/*int Trickletimer::interval_size = 0;
int Trickletimer::curr_interval=0;
int Trickletimer::counter=0;*/

Trickletimer::Trickletimer() {
}

Trickletimer::~Trickletimer() {
    // TODO Auto-generated destructor stub
}

void Trickletimer::doubleIntervalSize(){
    if(interval_size*2 >= par("Imax").doubleValue())
        interval_size=par("Imax");
    else
        interval_size*=2;
}

void Trickletimer::initialize(){

    interval_size=intuniform(par("Imin"),par("Imax"));
    counter = 0;
    curr_interval = intuniform(interval_size/2,interval_size);
    expected_id = 0;
    last_time = simTime();
    EV << "Interval size = " << interval_size << endl;
}
void Trickletimer::handleMessage(cMessage* msg){
    // Does nothing
}

} /* namespace inet */
