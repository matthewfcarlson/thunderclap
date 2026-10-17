// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_001a3a00 @ 0x001a3a00
extern "C" unsigned int __cdecl FUN_0008d340(void *);
extern "C" void *__cdecl FUN_0008d6d0(unsigned int);
struct Item {
    char padding[0x8c];
    char *text;
    unsigned int FUN_001a3a00(const char *source);
};
unsigned int Item::FUN_001a3a00(const char *source) {
    unsigned int result = FUN_0008d340(text);
    if (!source) {
        text = 0;
        return (result & ~255u) | 1;
    }
    unsigned int length = 0;
    while (source[length]) ++length;
    char *allocated = (char *)FUN_0008d6d0(length + 1);
    text = allocated;
    char *dest = allocated;
    do {
        *dest++ = *source;
    } while (*source++);
    return ((unsigned int)allocated & ~255u) | 1;
}