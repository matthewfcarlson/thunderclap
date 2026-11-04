#include "compat/ptr.h"
extern "C" void FreeMem(void*);
extern "C" void* AllocMem(hulk_uintptr);
extern "C" unsigned int strlen(const char*);
extern "C" char* strcpy(char*, const char*);
class Obj {
    char pad[16];
    char* name;

  public:
    char SetText_0010cc40(const char* s);
};
char Obj::SetText_0010cc40(const char* s) {
    FreeMem(name);
    if (!s) {
        name = 0;
        return 1;
    }
    name = (char*)AllocMem(strlen(s) + 1);
    strcpy(name, s);
    return 1;
}