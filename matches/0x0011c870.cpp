#include "compat/ptr.h"
typedef unsigned int size_t;
extern "C" void __cdecl FUN_0008d340(void*);
extern "C" void* __cdecl FUN_0008d6d0(hulk_uintptr);
extern "C" size_t __cdecl strlen(const char*);
extern "C" char* __cdecl strcpy(char*, const char*);
class Obj {
    char pad[0x38];
    char* str;

  public:
    char set(const char* s);
};
char Obj::set(const char* s) {
    FUN_0008d340(str);
    if (!s) {
        str = 0;
        return 1;
    }
    str = (char*)FUN_0008d6d0(strlen(s) + 1);
    strcpy(str, s);
    return 1;
}