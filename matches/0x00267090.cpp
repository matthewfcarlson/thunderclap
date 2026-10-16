#include "decls/data/engine/core.h"

struct Obj_267090 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4(int);
};
extern Obj_267090** FUN_00266f50(void*, int);
void FUN_00267090(int param_1) {
    Obj_267090** p = FUN_00266f50(((char*)&DAT_00527f40), param_1);
    (*p)->f4(param_1);
}