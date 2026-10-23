#include "compat/ptr.h"
extern "C" void __cdecl FUN_0008d340(void*);
extern "C" void* __cdecl FUN_0008d6d0(hulk_uintptr);
extern "C" unsigned int __cdecl strlen(const char*);
extern "C" char* __cdecl strcpy(char*, const char*);
class Obj {
    char pad[16];
    char* s;

  public:
    unsigned char Set(const char* p);
};
unsigned char Obj::Set(const char* p) {
    FUN_0008d340(s);
    if (!p) {
        s = 0;
        return 1;
    }
    s = (char*)FUN_0008d6d0(strlen(p) + 1);
    strcpy(s, p);
    return 1;
}