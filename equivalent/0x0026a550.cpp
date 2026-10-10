// STATUS: equivalent (tools/equiv.py level 3: 75 inputs, branch coverage 12/12)
// FUN_0026a550 @ 0x0026a550
extern "C" unsigned char __cdecl FUN_00272240(const char* input, int* consumed, int* parsed, int flags);
extern "C" int __cdecl FUN_00271e40(int parsed, char* output, int available, int mode, int* produced, int flags);

// equiv-conv: FUN_0026a550 eax ecx stack stack stack
int __cdecl FUN_0026a550(const char* source, char* dest, int mode, int capacity, int flags) {
    if (source == dest)
        return -5;
    int written = 0;
    while (*source) {
        struct { int parsed; int consumed; int produced; } v;
        if (!FUN_00272240(source, &v.consumed, &v.parsed, flags))
            return -2;
        int result = FUN_00271e40(v.parsed, dest, capacity - written - 2, mode, &v.produced, flags);
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
