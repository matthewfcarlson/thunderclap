// STATUS: equivalent (tools/equiv.py level 3: 82 inputs, branch coverage 7/8, incomplete)
// core::XboxDrive::vfunc_21 @ 0x0026f210
extern void __cdecl FUN_002697c0(const char*, char*, int, char**, int);
namespace core {
struct XboxDrive {
    char padding[0xd5];
    char pathBuffer[0x103];
    char* path;
    unsigned int pathLength;
    void vfunc_21(const char* source);
};
void XboxDrive::vfunc_21(const char* source) {
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