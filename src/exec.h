/**
 * @file exec.h
 * @author Mateusz Dukat
 * @date 2022
 *
 * @brief Functions and structures for handling command execution.
 *
 */

#ifndef EXEC_H
#define EXEC_H

// Buffer line size for reading config file
#define EXECBUFFERLINESIZE 256

// Buffer size for PID array
#define PIDBUFFERSIZE 16

extern int PIDArray[PIDBUFFERSIZE];
extern int PIDIndex;

void SetupPIDData();
void ForkExecuteAndExit(char* command);
void KillExecutedPIDs();

#endif
