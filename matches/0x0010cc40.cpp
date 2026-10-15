extern "C" void FreeMem(void*);
extern "C" void* AllocMem(unsigned int);
extern "C" unsigned int strlen(const char*);
extern "C" char* strcpy(char*, const char*);
class Obj {
    char pad[16];
    char* name;

  public:
    char SetName(const char* s);
};
char Obj::SetName(const char* s) {
    FreeMem(name);
    if (!s) {
        name = 0;
        return 1;
    }
    name = (char*)AllocMem(strlen(s) + 1);
    strcpy(name, s);
    return 1;
}