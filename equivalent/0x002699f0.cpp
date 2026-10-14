// STATUS: equivalent (tools/equiv.py level 3: 228 inputs, branch coverage 8/8)
// FUN_002699f0 @ 0x002699f0
typedef unsigned int uint_2699f0;
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
extern "C" bool __cdecl FUN_002716c0(const char* source, uint_2699f0* length, uint_2699f0* other, int zero);

// Copies whole UTF-8-like characters from source into dest while they fit in capacity-1 bytes,
// then terminates dest. Returns the number of bytes copied, or -1 on a bad character.
// equiv-conv: FUN_002699f0 eax stack stack
int __cdecl FUN_002699f0(const char* source, char* dest, uint_2699f0 capacity) {
    uint_2699f0 written = 0;
    while (*source != 0) {
        uint_2699f0 length;
        uint_2699f0 other;
        if (!FUN_002716c0(source, &length, &other, 0))
            return -1;
        if (written + length > capacity - 1)
            break;
        memcpy(dest, source, length);
        written += length;
        source += length;
        dest += length;
    }
    *dest = 0;
    return (int)written;
}
