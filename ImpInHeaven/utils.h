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

#define IMP_WIDTH 55
#define IMP_HEIGHT 80


void SetUpProgram();

template <typename M, typename V>
void MapToVector(const  M & m, V & v) {
	for (typename M::const_iterator it = m.begin(); it != m.end(); ++it) {
		v.push_back(it->second);
	}
}