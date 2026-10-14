extern "C" void __cdecl FreeMem(void*);
extern "C" void* __cdecl AllocMem(unsigned int);
extern "C" unsigned int __cdecl strlen(const char*);
extern "C" char* __cdecl strcpy(char*, const char*);
class Obj {
    char pad[0x160];
    char* name;

  public:
    unsigned char SetName(const char* s);
};
unsigned char Obj::SetName(const char* s) {
    FreeMem(name);
    if (!s) {
        name = 0;
        return 1;
    }
    name = (char*)AllocMem(strlen(s) + 1);
    strcpy(name, s);
    return 1;
}