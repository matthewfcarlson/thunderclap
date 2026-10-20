#include "compat/ptr.h"
extern "C" void __cdecl release(void*);
extern "C" void* __cdecl alloc(hulk_uintptr);
extern "C" unsigned int __cdecl strlen(const char*);
class Obj {
    char pad[12];
    char* str;

  public:
    char Set(const char* s);
};
inline void copy(char* d, const char* s) {
    char c;
    do {
        c = *s;
        ++s;
        *d = c;
        ++d;
    } while (c);
}
char Obj::Set(const char* s) {
    release(str);
    if (!s) {
        str = (char*)s;
        return 1;
    }
    str = (char*)alloc(strlen(s) + 1);
    copy(str, s);
    return 1;
}