#include "decls/data/game/global.h"
// data: gObject_86180 = DAT_004dd6e8

struct Obj_86180 {
    void Call(int);
};
void __stdcall Target(int a, int b, int c, int d) {
    if ((*(Obj_86180**)&DAT_004dd6e8))
        (*(Obj_86180**)&DAT_004dd6e8)->Call(a);
}