// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_0026b1c0 @ 0x0026b1c0
// FUN_0026b1c0 converts a string of 32-bit code units to bytes, one decoded unit at a time
typedef unsigned short wchar16;
extern "C" char __cdecl FUN_00272070(const unsigned *, unsigned *, unsigned *, void *);
extern "C" int __cdecl FUN_00271870(unsigned, char *, int, int, unsigned *, void *);

// equiv-conv: FUN_0026b1c0 eax ecx stack stack stack
int __cdecl FUN_0026b1c0(const unsigned *source, char *destination, int input, int capacity, void *options) {
    if ((const void *)source == (void *)destination) return -5;
    int used = 0;
    while (*source) {
        struct { unsigned auxiliary, consumed, written; } t;
        if (!FUN_00272070(source, &t.consumed, &t.auxiliary, options)) return -2;
        int result = FUN_00271870(t.auxiliary, destination, capacity - used - 1, input, &t.written, options);
        if (result != 0) {
            if (result == -1) *destination = 0;
            return result;
        }
        source = (const unsigned *)((const char *)source + t.consumed);
        destination += t.written;
        used += t.written;
    }
    *destination = 0;
    return 0;
}
