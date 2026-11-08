// STATUS: equivalent (tools/equiv.py level 3: 82 inputs, branch coverage 7/8, incomplete)
// core::XboxDrive::vfunc_21 @ 0x0026f210
extern "C" void __cdecl FUN_002697c0(const char*, char*, int, char**, int);
#include "decls/data/records.h"
namespace core {
// core::XboxDrive::vfunc_21 (records.h CoreXboxDrive): the drive's source directory, ending in a backslash
struct XboxDrive_26f210 : CoreXboxDrive {
    void vfunc_21(const char* source);
};
void XboxDrive_26f210::vfunc_21(const char* source) {
    if (source && *source) {
        FUN_002697c0(source, pathBuffer, 0, &path, 0);
        char* p = path;
        unsigned int length = 0;
        while (p[length]) ++length;
        pathLength = length;
        if (p[length] != '\\') {
            p[length] = '\\';
            path[pathLength + 1] = 0;
            ++pathLength;
        }
    } else {
        path = 0;
        pathLength = 0;
    }
}
}