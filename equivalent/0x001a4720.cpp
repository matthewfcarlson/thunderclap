// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_001a4720 @ 0x001a4720
extern void __cdecl FUN_0008d340(void *);
extern void * __cdecl FUN_0008d6d0(unsigned int);
struct Object {
    char padding[0x17c];
    char *text;
    unsigned char FUN_001a4720(const char *value);
};
unsigned char Object::FUN_001a4720(const char *value) {
    FUN_0008d340(text);
    if (!value) {
        text = 0;
        return 1;
    }
    const char *end = value;
    do { ++end; } while (end[-1]);
    text = (char *)FUN_0008d6d0((unsigned int)(end - value));
    char *destination = text;
    do { *destination++ = *value; } while (*value++);
    return 1;
}