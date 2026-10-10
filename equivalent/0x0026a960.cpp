// STATUS: equivalent (tools/equiv.py level 3: 72 inputs, branch coverage 10/10)
// FUN_0026a960 @ 0x0026a960
extern "C" unsigned char __cdecl FUN_00272070(const int* input, int* consumed, int* parsed, int flags);
extern "C" int __cdecl FUN_002720b0(int parsed, char* output, int available, int mode, int* produced, int flags);

// equiv-conv: FUN_0026a960 eax ecx stack stack stack
int __cdecl FUN_0026a960(const int* source, char* dest, int mode, int capacity, int flags) {
    int written = 0;
    while (*source) {
        struct { int parsed; int consumed; int produced; } v;
        if (!FUN_00272070(source, &v.consumed, &v.parsed, flags))
            return -2;
        int result = FUN_002720b0(v.parsed, dest, capacity - written - 4, mode, &v.produced, flags);
        if (result != 0) {
            if (result == -1)
                *(int*)dest = 0;
            return result;
        }
        source = (const int*)((const char*)source + v.consumed);
        dest += v.produced;
        written += v.produced;
    }
    *(int*)dest = 0;
    return 0;
}
