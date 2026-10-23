#include "compat/ptr.h"
extern "C" unsigned int __cdecl strlen(const char*);
extern "C" char* __cdecl strcpy(char*, const char*);
void __cdecl FUN_0008d340(void*);
void* __cdecl FUN_0008d6d0(hulk_uintptr);
class Obj_1a46b0 {
    char pad[0x170];
    char* s;

  public:
    char Set(const char* p);
};
char Obj_1a46b0::Set(const char* p) {
    FUN_0008d340(s);
    if (!p) {
        s = 0;
        return 1;
    }
    s = (char*)FUN_0008d6d0(strlen(p) + 1);
    strcpy(s, p);
    return 1;
}