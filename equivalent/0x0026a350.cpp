// STATUS: equivalent (tools/equiv.py level 3: 75 inputs, branch coverage 12/12)
// FUN_0026a350 @ 0x0026a350
#include "compat/ptr.h"
extern "C" unsigned char __cdecl FUN_00271b70(const char* input, int* consumed, int* parsed, int flags);
extern "C" int __cdecl FUN_00271e40(unsigned int, unsigned short *, unsigned int, unsigned int, unsigned int *, unsigned int *);

// equiv-conv: FUN_0026a350 eax ecx stack stack stack
extern "C" int __cdecl FUN_0026a350(const char* source, char* dest, int mode, int capacity, int flags) {
    if (source == dest)
        return -5;
    int written = 0;
    while (*source) {
        struct { int parsed; int consumed; int produced; } v;
        if (!FUN_00271b70(source, &v.consumed, &v.parsed, flags))
            return -2;
        int result = FUN_00271e40((int)(v.parsed), (unsigned short *)(char *)dest, (int)(capacity - written - 2), (int)mode, (unsigned int *)(int *)(&v.produced), (unsigned int *)(hulk_uintptr)(int)flags);
        if (result != 0) {
            if (result == -1)
                *(short*)dest = 0;
            return result;
        }
        source += v.consumed;
        dest += v.produced;
        written += v.produced;
    }
    *(short*)dest = 0;
    return 0;
}
