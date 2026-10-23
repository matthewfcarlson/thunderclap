#include "compat/ptr.h"
void __cdecl FUN_0008d340(void*);
void* __cdecl FUN_0008d6d0(hulk_uintptr);
extern "C" unsigned int __cdecl strlen(const char*);
extern "C" char* __cdecl strcpy(char*, const char*);
class Obj_1a3fb0 {
    char pad[0xf0];
    char* text;

  public:
    char Set(char* s);
};
char Obj_1a3fb0::Set(char* s) {
    FUN_0008d340(text);
    if (!s) {
        text = 0;
        return 1;
    }
    text = (char*)FUN_0008d6d0(strlen(s) + 1);
    strcpy(text, s);
    return 1;
}