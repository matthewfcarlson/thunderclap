#include "gen/owners.h"
typedef unsigned int uint_1f92f0;
struct Obj_1f92f0 {
    char pad[0x10];
};
extern "C" uint_1f92f0 __cdecl FUN_001f92f0(Obj_1f92f0* param_1, Obj_1f92f0* param_2) {
    if (((owners::Key_1f84d0 *)param_1)->FUN_001f84d0((const owners::Key_1f84d0 *)(Obj_1f92f0 *)((Obj_1f92f0*)((char*)param_2 + 0x10))))
        return 0xffffffff;
    return ((owners::Key_1f84d0 *)(((Obj_1f92f0*)((char*)param_2 + 0x10))))->FUN_001f84d0((const owners::Key_1f84d0 *)(Obj_1f92f0 *)param_1) != 0;
}