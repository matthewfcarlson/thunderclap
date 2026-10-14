extern "C" unsigned int __cdecl strlen(const char*);
extern "C" char* __cdecl strcpy(char*, const char*);
void __cdecl Free(void*);
void* __cdecl Alloc(unsigned int);
class Obj_1a46b0 {
    char pad[0x170];
    char* s;

  public:
    char Set(const char* p);
};
char Obj_1a46b0::Set(const char* p) {
    Free(s);
    if (!p) {
        s = 0;
        return 1;
    }
    s = (char*)Alloc(strlen(p) + 1);
    strcpy(s, p);
    return 1;
}