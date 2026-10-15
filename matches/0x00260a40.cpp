typedef unsigned int size_t;
extern "C" int sprintf(char*, const char*, ...);
extern "C" size_t strlen(const char*);
extern "C" unsigned int FUN_00267f80();
struct Obj {
    char pad[0x2004];
    char* p;
};
char* __cdecl FUN_00260a40(Obj* o) {
    unsigned int n = FUN_00267f80();
    char* s = o->p;
    sprintf(s, "%u", n);
    o->p += strlen(s) + 1;
    return s;
}