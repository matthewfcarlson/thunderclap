// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_001a4800 @ 0x001a4800
extern "C" void __cdecl FUN_0008d340(void *);
extern "C" void * __cdecl FUN_0008d6d0(unsigned int);
struct Object { char pad[0x18c]; char *text; unsigned char FUN_001a4800(const char *source); };
unsigned char Object::FUN_001a4800(const char *source) {
    FUN_0008d340(text);
    if (!source) { text = 0; return 1; }
    unsigned int length = 0;
    while (source[length]) ++length;
    text = (char *)FUN_0008d6d0(length + 1);
    char *dest = text;
    do { *dest++ = *source; } while (*source++);
    return 1;
}