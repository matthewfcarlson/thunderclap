// STATUS: equivalent (tools/equiv.py level 3: 228 inputs, branch coverage 8/8)
// FUN_0026ab60 @ 0x0026ab60
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
typedef unsigned int uint_26ab60;
extern "C" bool __cdecl FUN_00272240(const char* source, uint_26ab60* length, uint_26ab60* other, int zero);

// Copies whole UTF-8-like characters from source into dest while they fit in capacity-1 bytes,
// then terminates dest. Returns the number of bytes copied, or -1 on a bad character.
// equiv-conv: FUN_0026ab60 eax stack stack
int __cdecl FUN_0026ab60(const char* source, char* dest, uint_26ab60 capacity) {
    uint_26ab60 written = 0;
    while (*source != 0) {
        uint_26ab60 length;
        uint_26ab60 other;
        if (!FUN_00272240(source, &length, &other, 0))
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
