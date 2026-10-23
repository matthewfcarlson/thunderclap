#include "compat/ptr.h"
extern "C" unsigned __cdecl strlen(const char*);
extern "C" char* __cdecl strcpy(char*, const char*);
void __cdecl FUN_0008d340(void*);
void* __cdecl FUN_0008d6d0(hulk_uintptr);
class Obj {
    char pad[0x70];
    char* text;

  public:
    char set(const char* s);
};
char Obj::set(const char* s) {
    FUN_0008d340(text);
    if (!s) {
        text = 0;
        return 1;
    }
    text = (char*)FUN_0008d6d0(strlen(s) + 1);
    strcpy(text, s);
    return 1;
}