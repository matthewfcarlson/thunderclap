extern "C" void __cdecl Free(void*);
extern "C" void* __cdecl Alloc(unsigned int);
extern "C" unsigned int __cdecl strlen(const char*);
extern "C" char* __cdecl strcpy(char*, const char*);
class Obj {
    char pad[12];
    char* name;

  public:
    char SetName(const char* s);
};
char Obj::SetName(const char* s) {
    Free(name);
    if (!s) {
        name = 0;
        return 1;
    }
    name = (char*)Alloc(strlen(s) + 1);
    strcpy(name, s);
    return 1;
}