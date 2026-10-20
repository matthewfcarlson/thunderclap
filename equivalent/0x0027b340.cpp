// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 4/4)
// FUN_0027b340 @ 0x0027b340
// equiv-conv: FUN_0027b340 eax
extern "C" void* __cdecl FUN_0008d6d0(unsigned int);
char* FUN_0027b340(const char* source) {
    const char* end = source;
    do { ++end; } while (end[-1]);
    unsigned int length = (unsigned int)(end - source);
    char* result = (char*)FUN_0008d6d0(length);
    char* destination = result;
    do { *destination++ = *source; } while (*source++);
    return result;
}
