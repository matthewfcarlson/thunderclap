// STATUS: equivalent (tools/equiv.py level 3: 137 inputs, branch coverage 8/8)
// FUN_0026a210 @ 0x0026a210
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
extern "C" char __cdecl FUN_00271dd0(const unsigned short *source, unsigned int *length, unsigned int *end, int flags);

// equiv-conv: FUN_0026a210 eax stack stack
int __cdecl FUN_0026a210(const unsigned short *source, char *destination, unsigned int capacity)
{
    unsigned int written = 0;
    while (*source != 0) {
        unsigned int length;
        unsigned int end;
        if (!FUN_00271dd0(source, &length, &end, 0))
            return -1;
        if (length + written > capacity - 2)
            break;
        const char *bytes = (const char *)source;
        memcpy(destination, bytes, length);
        destination += length;
        source = (const unsigned short *)(bytes + length);
        written += length;
    }
    *(unsigned short *)destination = 0;
    return written;
}
