// STATUS: equivalent (tools/equiv.py level 3: 75 inputs, branch coverage 12/12)
// FUN_0026a600 @ 0x0026a600
typedef unsigned short wchar16;
extern "C" char __cdecl FUN_00271820(const char *, unsigned *, unsigned *, void *);
extern "C" int __cdecl FUN_00271e40(unsigned, wchar16 *, int, int, unsigned *, void *);

// equiv-conv: FUN_0026a600 eax ecx stack stack stack
int __cdecl FUN_0026a600(const char *source, wchar16 *destination, int input, int capacity, void *options) {
    if (source == (const char *)destination) return -5;
    int used = 0;
    while (*source) {
        struct { unsigned auxiliary, consumed, written; } l;
        if (!FUN_00271820(source, &l.consumed, &l.auxiliary, options)) return -2;
        int result = FUN_00271e40(l.auxiliary, destination, capacity - used - 2, input, &l.written, options);
        if (result != 0) {
            if (result == -1) *destination = 0;
            return result;
        }
        source += l.consumed;
        destination = (wchar16 *)((char *)destination + l.written);
        used += l.written;
    }
    *destination = 0;
    return 0;
}
