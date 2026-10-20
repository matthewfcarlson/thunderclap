#include "compat/ptr.h"
extern "C" void __cdecl thunk_FUN_00267090(void*);
extern "C" void* __cdecl FUN_0008d6d0(hulk_uintptr);
extern "C" unsigned int __cdecl strlen(const char*);
extern "C" char* __cdecl strcpy(char*, const char*);
class Obj {
    char pad[16];
    char* name;

  public:
    char SetName(const char* s);
};
char Obj::SetName(const char* s) {
    thunk_FUN_00267090(name);
    if (!s) {
        name = 0;
        return 1;
    }
    name = (char*)FUN_0008d6d0(strlen(s) + 1);
    strcpy(name, s);
    return 1;
}