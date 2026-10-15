extern "C" void __cdecl Free(void*);
extern "C" void* __cdecl Alloc(unsigned int);
extern "C" unsigned int __cdecl strlen(const char*);
extern "C" char* __cdecl strcpy(char*, const char*);
class Obj {
    char pad[0x14];
    char* p;

  public:
    unsigned char Set(const char* s);
};
unsigned char Obj::Set(const char* s) {
    Free(p);
    if (!s) {
        p = 0;
        return 1;
    }
    p = (char*)Alloc(strlen(s) + 1);
    strcpy(p, s);
    return 1;
}