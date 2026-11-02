// STATUS: equivalent (tools/equiv.py level 3: 68 inputs, branch coverage 10/10)
// FUN_0026a400 @ 0x0026a400
typedef unsigned short wchar16_26a400;
extern "C" char __cdecl FUN_00271dd0(const wchar16_26a400 *, unsigned *, unsigned *, void *);
extern "C" int __cdecl FUN_00271e40(unsigned int, unsigned short *, unsigned int, unsigned int, unsigned int *, unsigned int *);

// equiv-conv: FUN_0026a400 eax ecx stack stack stack
extern "C" int __cdecl FUN_0026a400(const unsigned short *source, unsigned short *destination, int input, int capacity, void *options) {
    int used = 0;
    while (*source) {
        unsigned consumed;
        unsigned auxiliary;
        unsigned written;
        if (!FUN_00271dd0(source, &consumed, &auxiliary, options)) return -2;
        int result = FUN_00271e40((unsigned)auxiliary, destination, (int)(capacity - used - 2), (int)input, (unsigned int *)(unsigned *)(&written), (unsigned int *)(void *)options);
        if (result != 0) {
            if (result == -1) *destination = 0;
            return result;
        }
        source = (const wchar16_26a400 *)((const char *)source + consumed);
        destination = (wchar16_26a400 *)((char *)destination + written);
        used += written;
    }
    *destination = 0;
    return 0;
}
