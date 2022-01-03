/*
 * Name:     GarageLib.h
 *
 *
 * Class:    GarageLib
 * Created : Mar 5, 2011
 * Author :  Charles B. Owen
 */
#pragma once
#ifndef GARAGELIB_H_
#define GARAGELIB_H_

#include <stdbool.h>
#include <unistd.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Constants
 */

#define DoorHeight 2.13
#define DoorTolerance 0.02

/*
 * Management
 */

extern bool IsGarageRunning();
extern void GarageStartup();
extern void GarageShutdown();

/*
 * Button and beam management
 */

extern void SetButtonHandler(void (*handler)());
extern bool WasButtonPressed();
extern bool IsBeamBroken();

/*
 * Motor control
 */

extern void SetMotorPower(double power);
extern void SetDoorSpeed(double speed);
extern double GetDoorPosition();

/*
 * Timer
 */

extern void ResetTimer();
extern double GetTimer();

#ifdef __cplusplus
}
#endif

#endif /* ELEVATORLIB_H_ */
