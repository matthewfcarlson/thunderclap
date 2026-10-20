#include "compat/ptr.h"
extern "C" void __cdecl releaseMem(void*);
extern "C" void* __cdecl allocMem(hulk_uintptr);
extern "C" unsigned int __cdecl strlen(const char*);
extern "C" char* __cdecl strcpy(char*, const char*);
class Obj {
    char pad[8];
    char* text;

  public:
    void SetText(const char* src);
};
void Obj::SetText(const char* src) {
    if (text) {
        releaseMem(text);
        text = 0;
    }
    if (src) {
        text = (char*)allocMem(strlen(src) + 1);
        strcpy(text, src);
    }
}