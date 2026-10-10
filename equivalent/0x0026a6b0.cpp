// STATUS: equivalent (tools/equiv.py level 3: 51 inputs, branch coverage 8/8)
// FUN_0026a6b0 @ 0x0026a6b0
// equiv-conv: FUN_0026a6b0 eax stack stack
typedef unsigned int uint;
extern "C" unsigned char __cdecl FUN_00272070(const char* text, uint* bytes, uint* other, int mode);

int __cdecl FUN_0026a6b0(const char* source, char* destination, uint capacity)
{
    uint copied = 0;
    struct { uint bytes; uint other; } r;
    while (*(const uint*)source) {
        if (!FUN_00272070(source, &r.bytes, &r.other, 0))
            return -1;
        if (copied + r.bytes > capacity - 4)
            break;
        for (uint i = 0; i != r.bytes; ++i)
            destination[i] = source[i];
        copied += r.bytes;
        destination += r.bytes;
        source += r.bytes;
    }
    *(uint*)destination = 0;
    return copied;
}
