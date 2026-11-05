#include "compat/ptr.h"
typedef unsigned int uint_23fa40;
typedef unsigned short ushort;
extern "C" void* FUN_00247610(const char*, const char*, int, int);
extern const char str1_23fa40[];
extern const char str2_23fa40[];
extern "C" void* memcpy(void*, const void*, unsigned int);
extern "C" void FUN_0023fa40(char** out, char* src, unsigned int n, int len) {
    char* p = (char*)FUN_00247610(str1_23fa40, str2_23fa40, len + 9, 4);
    *out = p + 8;
    *(ushort*)(*out - 2) = (ushort)len;
    *(ushort*)(*out - 4) = 1;
    memcpy(*out, src, n);
    (*out)[n] = 0;
}
