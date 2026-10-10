// STATUS: equivalent (tools/equiv.py level 3: 73 inputs, branch coverage 12/12)
// FUN_0026aa00 @ 0x0026aa00
extern "C" char __cdecl FUN_00272240(const char *, unsigned *, unsigned *, void *);
extern "C" int __cdecl FUN_002720b0(unsigned, unsigned *, int, int, unsigned *, void *);

// equiv-conv: FUN_0026aa00 eax ecx stack stack stack
int __cdecl FUN_0026aa00(const char *source, unsigned *destination, int input, int capacity, void *options) {
    if (source == (const char *)destination) return -5;
    int used = 0;
    while (*source) {
        struct { unsigned auxiliary, consumed, written; } l;
        if (!FUN_00272240(source, &l.consumed, &l.auxiliary, options)) return -2;
        int result = FUN_002720b0(l.auxiliary, destination, capacity - used - 4, input, &l.written, options);
        if (result != 0) {
            if (result == -1) *destination = 0;
            return result;
        }
        source += l.consumed;
        destination = (unsigned *)((char *)destination + l.written);
        used += l.written;
    }
    *destination = 0;
    return 0;
}
