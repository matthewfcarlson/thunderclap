// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_00238ae0 @ 0x00238ae0
typedef unsigned int size_t;
extern "C" void __cdecl FUN_0008d340(void *);
extern "C" void * __cdecl FUN_0008d6d0(size_t);
struct Object {
    char pad[0x14];
    char *text;
    bool FUN_00238ae0(const char *source);
};
bool Object::FUN_00238ae0(const char *source) {
    FUN_0008d340(text);
    if (!source) {
        text = 0;
        return true;
    }
    const char *end = source;
    while (*end) ++end;
    text = (char *)FUN_0008d6d0((size_t)(end - source) + 1);
    char *dest = text;
    do { *dest++ = *source; } while (*source++);
    return true;
}