extern "C" void __cdecl Free(void*);
extern "C" void* __cdecl Alloc(unsigned int);
extern "C" unsigned int __cdecl strlen(const char*);
extern "C" char* __cdecl strcpy(char*, const char*);
class X {
    char pad[16];
    char* p;

  public:
    unsigned char Set(const char* s);
};
unsigned char X::Set(const char* s) {
    Free(p);
    if (!s) {
        p = 0;
        return 1;
    }
    p = (char*)Alloc(strlen(s) + 1);
    strcpy(p, s);
    return 1;
}