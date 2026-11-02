// STATUS: equivalent (tools/equiv.py level 3: 75 inputs, branch coverage 12/12)
// FUN_0026a2a0 @ 0x0026a2a0
// equiv-conv: FUN_0026a2a0 eax ecx stack stack stack
#include "compat/ptr.h"
extern "C" bool __cdecl FUN_002716c0(const char *source, int *srcBytes, int *units, int options);
extern "C" int __cdecl FUN_00271e40(unsigned int, unsigned short *, unsigned int, unsigned int, unsigned int *, unsigned int *);

extern "C" int __cdecl FUN_0026a2a0(const char *source, char *destination, int mode, int capacity, int options)
{
    if (source == destination)
        return -5;
    struct { int units; int srcBytes; int written; } r;
    int used = 0;
    while (*source) {
        if (!FUN_002716c0(source, &r.srcBytes, &r.units, options))
            return -2;
        int result = FUN_00271e40((int)(r.units), (unsigned short *)(char *)destination, (int)(capacity - used - 2), (int)mode, (unsigned int *)(int *)(&r.written), (unsigned int *)(hulk_uintptr)(int)options);
        if (result) {
            if (result == -1)
                *(short *)destination = 0;
            return result;
        }
        source += r.srcBytes;
        destination += r.written;
        used += r.written;
    }
    *(short *)destination = 0;
    return 0;
}
