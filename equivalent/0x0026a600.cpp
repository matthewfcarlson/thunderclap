// STATUS: equivalent (tools/equiv.py level 3: 75 inputs, branch coverage 12/12)
// FUN_0026a600 @ 0x0026a600
typedef unsigned short wchar16_26a600;
extern "C" char __cdecl FUN_00271820(const char *, unsigned *, unsigned *, void *);
extern "C" int __cdecl FUN_00271e40(unsigned int, unsigned short *, unsigned int, unsigned int, unsigned int *, unsigned int *);

// equiv-conv: FUN_0026a600 eax ecx stack stack stack
extern "C" int __cdecl FUN_0026a600(const char *source, unsigned short *destination, int input, int capacity, void *options) {
    if (source == (const char *)destination) return -5;
    int used = 0;
    while (*source) {
        struct { unsigned auxiliary, consumed, written; } l;
        if (!FUN_00271820(source, &l.consumed, &l.auxiliary, options)) return -2;
        int result = FUN_00271e40((unsigned)(l.auxiliary), destination, (int)(capacity - used - 2), (int)input, (unsigned int *)(unsigned *)(&l.written), (unsigned int *)(void *)options);
        if (result != 0) {
            if (result == -1) *destination = 0;
            return result;
        }
        source += l.consumed;
        destination = (wchar16_26a600 *)((char *)destination + l.written);
        used += l.written;
    }
    *destination = 0;
    return 0;
}
