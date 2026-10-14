// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_0026ad10 @ 0x0026ad10
// FUN_0026ad10 converts a string of 16-bit code units to bytes, one decoded unit at a time
typedef unsigned short wchar16_26ad10;
extern "C" char __cdecl FUN_00271dd0(const wchar16_26ad10 *, unsigned *, unsigned *, void *);
extern "C" int __cdecl FUN_002722b0(unsigned, char *, int, int, unsigned *, void *);

// equiv-conv: FUN_0026ad10 eax ecx stack stack stack
int __cdecl FUN_0026ad10(const wchar16_26ad10 *source, char *destination, int input, int capacity, void *options) {
    if ((const void *)source == (void *)destination) return -5;
    int used = 0;
    while (*source) {
        struct { unsigned auxiliary, consumed, written; } t;
        if (!FUN_00271dd0(source, &t.consumed, &t.auxiliary, options)) return -2;
        int result = FUN_002722b0(t.auxiliary, destination, capacity - used - 1, input, &t.written, options);
        if (result != 0) {
            if (result == -1) *destination = 0;
            return result;
        }
        source = (const wchar16_26ad10 *)((const char *)source + t.consumed);
        destination += t.written;
        used += t.written;
    }
    *destination = 0;
    return 0;
}
