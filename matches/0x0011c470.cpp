extern "C" void __cdecl release(void*);
extern "C" void* __cdecl alloc(unsigned int);
extern "C" unsigned int __cdecl strlen(const char*);
extern "C" char* __cdecl strcpy(char*, const char*);
class Obj {
    char pad[0x34];
    char* str;

  public:
    char Set(const char* s);
};
char Obj::Set(const char* s) {
    release(str);
    if (!s) {
        str = (char*)s;
        return 1;
    }
    str = (char*)alloc(strlen(s) + 1);
    strcpy(str, s);
    return 1;
}