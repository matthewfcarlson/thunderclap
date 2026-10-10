// STATUS: equivalent (tools/equiv.py level 3: 73 inputs, branch coverage 12/12)
// FUN_0026aab0 @ 0x0026aab0
// equiv-conv: FUN_0026aab0 eax ecx stack stack stack
extern "C" bool __cdecl FUN_00271820(const char *source, int *srcBytes, int *units, int options);
extern "C" int __cdecl FUN_002720b0(int units, char *destination, int remaining, int mode, int *written, int options);

int __cdecl FUN_0026aab0(const char *source, char *destination, int mode, int capacity, int options)
{
    if ((const void *)source == (const void *)destination)
        return -5;
    struct { int units; int srcBytes; int written; } r;
    int used = 0;
    while (*source) {
        if (!FUN_00271820(source, &r.srcBytes, &r.units, options))
            return -2;
        int result = FUN_002720b0(r.units, destination, capacity - used - 4, mode, &r.written, options);
        if (result) {
            if (result == -1)
                *(int *)destination = 0;
            return result;
        }
        source = (const char *)((const char *)source + r.srcBytes);
        destination += r.written;
        used += r.written;
    }
    *(int *)destination = 0;
    return 0;
}
