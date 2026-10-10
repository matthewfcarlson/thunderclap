// STATUS: equivalent (tools/equiv.py level 3: 65 inputs, branch coverage 10/10)
// FUN_0026b000 @ 0x0026b000
extern "C" unsigned char __cdecl FUN_002716c0(const char* input, int* consumed, int* parsed, int flags);
extern "C" int __cdecl FUN_00271870(int parsed, char* output, int available, int mode, int* produced, int flags);

// equiv-conv: FUN_0026b000 eax ecx stack stack stack
int __cdecl FUN_0026b000(const char* source, char* dest, int mode, int capacity, int flags) {
    int written = 0;
    while (*source) {
        struct { int parsed; int consumed; int produced; } v;
        if (!FUN_002716c0(source, &v.consumed, &v.parsed, flags))
            return -2;
        int result = FUN_00271870(v.parsed, dest, capacity - written - 1, mode, &v.produced, flags);
        if (result != 0) {
            if (result == -1)
                *(char*)dest = 0;
            return result;
        }
        source += v.consumed;
        dest += v.produced;
        written += v.produced;
    }
    *(char*)dest = 0;
    return 0;
}

