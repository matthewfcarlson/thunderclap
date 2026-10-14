extern "C" void __cdecl Free(void*);
extern "C" void* __cdecl Alloc(unsigned int);
extern "C" unsigned int __cdecl strlen(const char*);
extern "C" char* __cdecl strcpy(char*, const char*);
class Obj {
    char pad[0xec];
    char* str;

  public:
    unsigned char Set(const char* s);
};
unsigned char Obj::Set(const char* s) {
    Free(str);
    if (!s) {
        str = 0;
        return 1;
    }
    str = (char*)Alloc(strlen(s) + 1);
    strcpy(str, s);
    return 1;
}