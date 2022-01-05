#pragma once
#ifndef STEP14_ROBOTLIB_H_
#define STEP14_ROBOTLIB_H_

#include <stdbool.h>
#include <unistd.h>

#ifdef __cplusplus
extern "C" {
#endif
/*
* Constants
*/
/*
* Management
*/
extern bool IsSimulatorRunning(void);
extern void SimulatorStartup(void);
extern void SimulatorShutdown(void);
extern void RobotGoTo(int machine);
extern void SetMachineRequestHandler(void (*handler)(int machine));
extern bool IsRobotBusy(void);
/*
* Timer
*/
extern void ResetTimer(void);
extern double GetTimer(void);
#ifdef __cplusplus
}
#endif
#endif /* ROBOTLIB_H_ */
