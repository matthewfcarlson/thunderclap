// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_001a3ed0 @ 0x001a3ed0
struct Object { char pad[0xe0]; char* text; unsigned int FUN_001a3ed0(const char* value); };
unsigned int __cdecl FUN_0008d340(void*);
void* __cdecl FUN_0008d6d0(unsigned int);
unsigned int Object::FUN_001a3ed0(const char* value) {
    unsigned int freed = FUN_0008d340(text);
    if (!value) { text = 0; return (freed & ~255u) | 1; }
    const char* end = value;
    while (*end) ++end;
    char* result = (char*)FUN_0008d6d0((unsigned int)(end - value + 1));
    text = result;
    char* dest = result;
    do { *dest++ = *value; } while (*value++);
    return ((unsigned int)result & ~255u) | 1;
}