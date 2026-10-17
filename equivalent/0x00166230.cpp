// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_00166230 @ 0x00166230
extern "C" void __cdecl FUN_0008d340(void *); 
extern "C" void * __cdecl FUN_0008d6d0(unsigned int);
struct Thing { char pad[12]; char *text; bool FUN_00166230(const char *source); };
bool Thing::FUN_00166230(const char *source) {
    FUN_0008d340(text);
    if (!source) { text = 0; return true; }
    unsigned int length = 0;
    while (source[length]) ++length;
    text = (char *)FUN_0008d6d0(length + 1);
    char *out = text;
    do { *out++ = *source; } while (*source++);
    return true;
}