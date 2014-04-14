#ifndef MAIN_H_
#define MAIN_H_

#define S_TO_NS_MULTIPLIER 1000000000

#include "ros/ros.h"
#include "PrioritySwitcher.h"

extern ros::NodeHandle* nodeHandle;
extern PrioritySwitcher* testnodePrioritySwitcher;
extern int loops;
extern int timeout_us;
extern bool testnodeRT;
extern bool fifoScheduling;

#endif //MAIN_H_
