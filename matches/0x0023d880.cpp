#include "compat/ptr.h"
extern "C" void __cdecl FreeMem(void*);
extern "C" void* __cdecl AllocMem(hulk_uintptr);
extern "C" unsigned int __cdecl strlen(const char*);
extern "C" char* __cdecl strcpy(char*, const char*);
class Obj {
    char pad[12];
    char* text;

  public:
    char Set(const char* s);
};
char Obj::Set(const char* s) {
    FreeMem(text);
    if (!s) {
        text = 0;
        return 1;
    }
    text = (char*)AllocMem(strlen(s) + 1);
    strcpy(text, s);
    return 1;
}