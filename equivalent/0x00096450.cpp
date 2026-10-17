// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 4/4)
// FUN_00096450 @ 0x00096450
extern "C" void* __cdecl FUN_0008d6d0(unsigned int);
char* __cdecl FUN_00096450(const char* source)
{
    const char* end = source;
    while (*end) ++end;
    unsigned int length = (unsigned int)(end - source) + 1;
    char* destination = (char*)FUN_0008d6d0(length);
    if (!destination) return destination;
    for (unsigned int i = 0; i < length; ++i)
        destination[i] = source[i];
    return destination;
}