// STATUS: equivalent (tools/equiv.py level 3: 113 inputs, branch coverage 8/8)
// FUN_0026a6b0 @ 0x0026a6b0
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
// equiv-conv: FUN_0026a6b0 eax stack stack
typedef unsigned int uint_26a6b0;
extern "C" unsigned char __cdecl FUN_00272070(const char* text, uint_26a6b0* bytes, uint_26a6b0* other, int mode);

int __cdecl FUN_0026a6b0(const char* source, char* destination, uint_26a6b0 capacity)
{
    uint_26a6b0 copied = 0;
    struct { uint_26a6b0 bytes; uint_26a6b0 other; } r;
    while (*(const uint_26a6b0*)source) {
        if (!FUN_00272070(source, &r.bytes, &r.other, 0))
            return -1;
        if (copied + r.bytes > capacity - 4)
            break;
        memcpy(destination, source, r.bytes);
        copied += r.bytes;
        destination += r.bytes;
        source += r.bytes;
    }
    *(uint_26a6b0*)destination = 0;
    return copied;
}
