// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_001a3c30 @ 0x001a3c30
struct Holder { char pad[0xb0]; char *text; int FUN_001a3c30(const char *source); };
int __cdecl FUN_0008d340(void *);
void * __cdecl FUN_0008d6d0(unsigned int);
int Holder::FUN_001a3c30(const char *source) {
    int result = FUN_0008d340(text);
    if (!source) {
        text = 0;
        return (result & ~255) | 1;
    }
    const char *end = source;
    while (*end) ++end;
    char *dest = (char *)FUN_0008d6d0((unsigned int)(end - source + 1));
    text = dest;
    char *out = dest;
    do { *out++ = *source; } while (*source++);
    return ((int)dest & ~255) | 1;
}