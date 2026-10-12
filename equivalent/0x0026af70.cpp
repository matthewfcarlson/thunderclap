// STATUS: equivalent (tools/equiv.py level 3: 228 inputs, branch coverage 8/8)
// FUN_0026af70 @ 0x0026af70
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
// equiv-conv: FUN_0026af70 eax stack stack
typedef unsigned int uint;
extern "C" unsigned char __cdecl FUN_00271820(const char* text, uint* bytes, uint* other, int mode);

int __cdecl FUN_0026af70(const char* source, char* destination, uint capacity)
{
    uint copied = 0;
    uint bytes;
    uint other;
    while (*source) {
        if (!FUN_00271820(source, &bytes, &other, 0))
            return -1;
        if (copied + bytes > capacity - 1)
            break;
        memcpy(destination, source, bytes);
        copied += bytes;
        destination += bytes;
        source += bytes;
    }
    *destination = 0;
    return copied;
}