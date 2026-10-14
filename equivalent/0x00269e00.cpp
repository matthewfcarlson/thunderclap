// STATUS: equivalent (tools/equiv.py level 3: 228 inputs, branch coverage 8/8)
// FUN_00269e00 @ 0x00269e00
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
// equiv-conv: FUN_00269e00 eax stack stack
typedef unsigned int uint_269e00;
extern "C" unsigned char __cdecl FUN_00271b70(const char* text, uint_269e00* bytes, uint_269e00* other, int mode);

int __cdecl FUN_00269e00(const char* source, char* destination, uint_269e00 capacity)
{
    uint_269e00 copied = 0;
    uint_269e00 bytes;
    uint_269e00 other;
    while (*source) {
        if (!FUN_00271b70(source, &bytes, &other, 0))
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