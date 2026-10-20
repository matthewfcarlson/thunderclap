#include "compat/ptr.h"
extern "C" unsigned char flag_8d710;
extern "C" void __cdecl InitA();
extern "C" void __cdecl InitC(int);
extern "C" int __cdecl DoThing(hulk_intptr, int);
struct Obj_8d710 {
    char pad[0x80];
    void InitB();
};
extern Obj_8d710 object_8d710;
int __cdecl Target(int a, hulk_intptr b) {
    if (!flag_8d710) {
        InitA();
        object_8d710.InitB();
        InitC(30);
        flag_8d710 = 1;
    }
    return DoThing(b, a);
}
