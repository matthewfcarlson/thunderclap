#include "decls/data/game/unknown.h"
// data: flag_8d710 = DAT_004dd778, object_8d710 = DAT_004dd780

#include "compat/ptr.h"
extern "C" void __cdecl InitA();
extern "C" void __cdecl InitC(int);
extern "C" int __cdecl DoThing(hulk_intptr, int);
struct Obj_8d710 {
    char pad[0x80];
    void InitB();
};
int __cdecl Target(int a, hulk_intptr b) {
    if (!(*(unsigned char*)&DAT_004dd778)) {
        InitA();
        (*(Obj_8d710*)&DAT_004dd780).InitB();
        InitC(30);
        (*(unsigned char*)&DAT_004dd778) = 1;
    }
    return DoThing(b, a);
}
