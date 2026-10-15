extern "C" int __cdecl rand();
extern "C" int __cdecl sprintf(char*, const char*, ...);
extern "C" unsigned int __cdecl strlen(const char*);
struct Obj {
    char pad[0x2004];
    char* cursor;
};
char* __cdecl FUN_00260ae0(Obj* p) {
    int n = rand();
    char* s = p->cursor;
    sprintf(s, "%u", n);
    p->cursor += strlen(s) + 1;
    return s;
}