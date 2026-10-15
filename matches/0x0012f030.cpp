extern "C" void __cdecl Free(void*);
extern "C" void* __cdecl Alloc(unsigned int);
extern "C" unsigned int __cdecl strlen(const char*);
extern "C" char* __cdecl strcpy(char*, const char*);
class Obj {
    char pad[16];
    char* s;

  public:
    unsigned char Set(const char* p);
};
unsigned char Obj::Set(const char* p) {
    Free(s);
    if (!p) {
        s = 0;
        return 1;
    }
    s = (char*)Alloc(strlen(p) + 1);
    strcpy(s, p);
    return 1;
}