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

#ifndef INET_TRICKLE_TRICKLETIMER_H_
#define INET_TRICKLE_TRICKLETIMER_H_

#include <omnetpp.h>

using namespace omnetpp;

namespace inet {

class Trickletimer : public cSimpleModule {
private:
    int interval_size;
    double curr_interval;
    int counter;
    int expected_id;
    simtime_t last_time;
public:
    Trickletimer();
    virtual ~Trickletimer();
    int getCounter() {
        return counter;
    }

    void resetCounter(){
        counter = 0;
    }
    void updateCounter() {
        counter++;
    }

    double getCurrInterval() {
        return curr_interval;
    }

    void updateCurrInterval() {
        curr_interval = intuniform(interval_size/2,interval_size);
    }

    void doubleIntervalSize();

    int getIntervalSize() {
        return interval_size;
    }

    void setIntervalSize(int intervalSize) {
        interval_size = intervalSize;
    }

    const simtime_t& getLastTime() const {
        return last_time;
    }

    void setLastTime(const simtime_t& lastTime) {
        last_time = lastTime;
    }

    int getExpectedId() const {
        return expected_id;
    }

    void updateExpectedId() {
        expected_id++;
    }

protected:
    virtual void initialize() ;
    virtual void handleMessage(cMessage* msg);
};


} /* namespace inet */

#endif /* INET_TRICKLE_TRICKLETIMER_H_ */
