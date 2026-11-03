#include "gen/owners.h"
typedef unsigned int uint_1f92f0;
struct Obj_1f92f0 {
    char pad[0x10];
};
extern "C" uint_1f92f0 __cdecl FUN_001f92f0(Obj_1f92f0* lhs, Obj_1f92f0* rhs) {
    if (((owners::Key_1f84d0 *)lhs)->FUN_001f84d0((const owners::Key_1f84d0 *)(Obj_1f92f0 *)((Obj_1f92f0*)((char*)rhs + 0x10))))
        return 0xffffffff;
    return ((owners::Key_1f84d0 *)(((Obj_1f92f0*)((char*)rhs + 0x10))))->FUN_001f84d0((const owners::Key_1f84d0 *)(Obj_1f92f0 *)lhs) != 0;
}