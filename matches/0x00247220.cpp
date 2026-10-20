#include "compat/ptr.h"
extern "C" void __cdecl FUN_002469e0();
extern "C" void __cdecl FUN_002469f0();
extern "C" void __cdecl FUN_00246a10();
extern "C" void __cdecl FUN_00246a40();
extern "C" void __cdecl FUN_00246a60();
extern "C" char DAT_0042921c[];
struct Base_247220 {
    virtual void F();
};
class ContentStream {
  public:
    unsigned vptr, a, b, c, d, e;
    unsigned char flag;
    unsigned char pad[3];
    Base_247220* source;
    ContentStream* Make(Base_247220*);
};
ContentStream* ContentStream::Make(Base_247220* arg) {
    a = ((hulk_intptr)(void (__cdecl*)())&FUN_002469e0);
    b = ((hulk_intptr)(void (__cdecl*)())&FUN_002469f0);
    c = ((hulk_intptr)(void (__cdecl*)())&FUN_00246a10);
    d = ((hulk_intptr)(void (__cdecl*)())&FUN_00246a40);
    e = ((hulk_intptr)(void (__cdecl*)())&FUN_00246a60);
    flag = 0;
    vptr = ((hulk_intptr)DAT_0042921c);
    source = arg;
    arg->F();
    return this;
}