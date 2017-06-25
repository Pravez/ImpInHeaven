#pragma once

#include <stdio.h>  /* defines FILENAME_MAX */
#include <string>
#include <windows.h>
#include <libloaderapi.h>
#ifdef WIN32
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

extern char WORKINGDIR_PATH[MAX_PATH];


void SetUpProgram();