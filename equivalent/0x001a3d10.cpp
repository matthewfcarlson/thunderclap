// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_001a3d10 @ 0x001a3d10
int __cdecl FUN_0008d340(void *p);
void * __cdecl FUN_0008d6d0(unsigned int size);
struct Object {
    char padding[0xc0];
    char *name;
    int FUN_001a3d10(const char *text);
};
int Object::FUN_001a3d10(const char *text) {
    int result = FUN_0008d340(name);
    if (!text) {
        name = 0;
        return (result & ~255) | 1;
    }
    const char *end = text;
    while (*end) ++end;
    char *copy = (char *)FUN_0008d6d0((unsigned int)(end - text + 1));
    name = copy;
    char *destination = copy;
    do {
        *destination++ = *text;
    } while (*text++);
    return ((int)copy & ~255) | 1;
}