/**
 * @file exec.c
 * @author Mateusz Dukat
 * @date 2022
 *
 * @brief Functions and structures for handling command execution.
 *
 */

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>

#include "exec.h"

int PIDArray[PIDBUFFERSIZE];
int PIDIndex;

void SetupPIDData(){
	PIDIndex = 0;
	for(int i = 0; i<PIDBUFFERSIZE; ++i)
		PIDArray[i] = 0;
}

void ForkExecuteAndExit(char* command){
	if (PIDIndex == PIDBUFFERSIZE)
		return;

	int pid = fork();

	if (pid == -1)
		return;

	if (pid == 0){
		execl(command, NULL);
		exit(0);
	}

	PIDArray[PIDIndex] = pid;
	++PIDIndex;

	return;
}

void KillExecutedPIDs(){
	for(int i = 0; i<PIDIndex; ++i)
		kill(PIDArray[i], SIGKILL);
}
