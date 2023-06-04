#pragma once
#define PLATFORM_WINDOWS_C 'w'
#define PLATFORM_LINUX_C   'l'
#define PLATFORM_UNKNOWN_C 'u'

struct NecessaryData {
    char platform;
    unsigned int resolution[2]; /* 0 -> height, 1 -> width */
    _Bool isRunning;
};

void getPlatform(struct NecessaryData *data);
void getScreenResolution(struct NecessaryData *data);
void printData(struct NecessaryData *data);