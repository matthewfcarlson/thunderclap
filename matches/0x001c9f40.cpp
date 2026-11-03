#include "gen/owners.h"
extern "C" void* __cdecl memset(void*, int, unsigned int);
int __cdecl Fmt(char*, unsigned int, const char*, const char*);
owners::Obj_1c9f40* owners::Obj_1c9f40::FUN_001c9f40(int a, const char* b, const char* c) {
    memset(this, 0, 0x54);
    this->a = a;
    this->v = 0x54;
    this->s1[0] = 0;
    this->s2[0] = 0;
    if (b)
        Fmt(this->s1, 0x20, "%s", b);
    if (c)
        Fmt(this->s2, 0x20, "%s", c);
    return this;
}
