#include "compat/ptr.h"
typedef unsigned int size_t;
extern "C" void __cdecl releaseMem(void*);
extern "C" void* __cdecl allocMem(hulk_uintptr);
extern "C" size_t __cdecl strlen(const char*);
extern "C" char* __cdecl strcpy(char*, const char*);
class Obj {
    char pad[0x38];
    char* str;

  public:
    char set(const char* s);
};
char Obj::set(const char* s) {
    releaseMem(str);
    if (!s) {
        str = 0;
        return 1;
    }
    str = (char*)allocMem(strlen(s) + 1);
    strcpy(str, s);
    return 1;
}