extern "C" void __cdecl Free(void*);
extern "C" void* __cdecl Alloc(unsigned int);
extern "C" char* __cdecl strcpy(char*, const char*);
extern "C" unsigned int __cdecl strlen(const char*);
class Obj {
    char pad[0x14];
    char* str;

  public:
    bool Set(const char* s);
};
bool Obj::Set(const char* s) {
    Free(str);
    if (!s) {
        str = 0;
        return true;
    }
    str = (char*)Alloc(strlen(s) + 1);
    strcpy(str, s);
    return true;
}