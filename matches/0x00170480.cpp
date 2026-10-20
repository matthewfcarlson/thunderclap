#include "compat/ptr.h"
extern "C" void __cdecl Free(void*);
extern "C" void* __cdecl Alloc(hulk_uintptr);
extern "C" unsigned int __cdecl strlen(const char*);
inline void Copy(char* dst, const char* src) {
    char c;
    do {
        c = *src;
        src++;
        *dst = c;
        dst++;
    } while (c);
}
class Obj {
    char pad[0x28];
    char* s;

  public:
    unsigned char Set(const char* p);
};
unsigned char Obj::Set(const char* p) {
    Free(s);
    if (!p) {
        s = 0;
        return 1;
    }
    char* dst = (char*)Alloc(strlen(p) + 1);
    s = dst;
    Copy(dst, p);
    return 1;
}