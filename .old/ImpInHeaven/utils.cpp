#include "utils.h"

char WORKINGDIR_PATH[MAX_PATH];

void SetUpProgram()
{
	GetCurrentDir(WORKINGDIR_PATH, sizeof(WORKINGDIR_PATH));
}