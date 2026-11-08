// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 6/6)
// FUN_0026f330 @ 0x0026f330
extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);
#include "decls/data/records.h"
// core::XboxDrive (records.h CoreXboxDrive): a file's path on the device: the drive's name, a backslash, the
// source directory (vfunc_21), the file's name
struct XboxDrive_26f330 : CoreXboxDrive {
    void FUN_0026f330(const char* name, char* result, int capacity);
};
void XboxDrive_26f330::FUN_0026f330(const char* name, char* result, int capacity)
{
    int directoryLength = 0;
    while (this->name[directoryLength] != '\0') ++directoryLength;
    int position = directoryLength + 1;
    strncpy(result, this->name, capacity - 1);
    strncpy(result + directoryLength, "\\", capacity - position);
    if (path) {
        strncpy(result + position, path, capacity - position - 1);
        position += pathLength;
    }
    if (*name == '\\') ++name;
    strncpy(result + position, name, capacity - position - 1);
    result[capacity - 1] = '\0';
}