#include "compat/ptr.h"
extern "C" unsigned __cdecl strlen(const char*);
extern "C" char* __cdecl strcpy(char*, const char*);
void __cdecl release(void*);
void* __cdecl alloc(hulk_uintptr);
class Obj {
    char pad[0x70];
    char* text;

  public:
    char set(const char* s);
};
char Obj::set(const char* s) {
    release(text);
    if (!s) {
        text = 0;
        return 1;
    }
    text = (char*)alloc(strlen(s) + 1);
    strcpy(text, s);
    return 1;
}