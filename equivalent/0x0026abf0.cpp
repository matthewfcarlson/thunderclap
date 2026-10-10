// STATUS: equivalent (tools/equiv.py level 3: 65 inputs, branch coverage 10/10)
// FUN_0026abf0 @ 0x0026abf0
extern "C" char __cdecl FUN_002716c0(const char *, unsigned *, unsigned *, void *);
extern "C" int __cdecl FUN_002722b0(unsigned, char *, int, int, unsigned *, void *);

// equiv-conv: FUN_0026abf0 eax ecx stack stack stack
int __cdecl FUN_0026abf0(const char *text, char *output, int options, int capacity, void *state)
{
    int total = 0;
    while (*text != 0) {
        struct { unsigned value, consumed, produced; } l;
        if (!FUN_002716c0(text, &l.consumed, &l.value, state))
            return -2;
        int result = FUN_002722b0(l.value, output, capacity - total - 1,
                                  options, &l.produced, state);
        if (result != 0) {
            if (result == -1)
                *output = 0;
            return result;
        }
        text += l.consumed;
        output += l.produced;
        total += l.produced;
    }
    *output = 0;
    return 0;
}
