// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_0012ece0 @ 0x0012ece0
typedef unsigned int size_t;
void __cdecl FUN_0008d340(void*);
void* __cdecl FUN_0008d6d0(size_t);
struct Thing {
    char pad[0x20];
    char* text;
    unsigned char FUN_0012ece0(const char* value);
};
unsigned char Thing::FUN_0012ece0(const char* value) {
    FUN_0008d340(text);
    if (!value) {
        text = 0;
        return 1;
    }
    const char* end = value;
    while (*end) ++end;
    text = (char*)FUN_0008d6d0(end - value + 1);
    char* dest = text;
    do {
        *dest++ = *value;
    } while (*value++);
    return 1;
}