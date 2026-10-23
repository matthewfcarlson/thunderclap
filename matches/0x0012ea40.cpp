#include "compat/ptr.h"
extern "C" void __cdecl FUN_0008d340(void*);
extern "C" void* __cdecl FUN_0008d6d0(hulk_uintptr);
extern "C" unsigned int __cdecl strlen(const char*);
extern "C" char* __cdecl strcpy(char*, const char*);
class Obj {
    char pad[0x14];
    char* p;

  public:
    unsigned char Set(const char* s);
};
unsigned char Obj::Set(const char* s) {
    FUN_0008d340(p);
    if (!s) {
        p = 0;
        return 1;
    }
    p = (char*)FUN_0008d6d0(strlen(s) + 1);
    strcpy(p, s);
    return 1;
}