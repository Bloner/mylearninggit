#ifndef STEP12C_H
#define STEP12C_H

#include "step12a.h"
void Reset(int tower[NumPins][NumDisks]);
void MoveDisk(int tower[NumPins][NumDisks], int fm, int to);
void Autosolve(int tower[NumPins][NumDisks]);
void AutoMove(int tower[NumPins][NumDisks], int num, int fm, int to);
#endif
