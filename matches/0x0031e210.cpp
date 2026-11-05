#include "compat/ptr.h"
#include "decls/data/engine/pure3d.h"

struct Obj_31e210 {
    virtual void f0();
    virtual void f1(int);
};
extern "C" void FUN_0031e210(hulk_intptr x) {
    if ((*(Obj_31e210**)&DAT_005554ac))
        (*(Obj_31e210**)&DAT_005554ac)->f1(x);
}