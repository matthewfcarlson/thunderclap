#include "compat/ptr.h"
#include "decls/data/records.h"

struct Obj_267090 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual int f4(int);
};
extern "C" Obj_267090** FUN_00266f50(void*, int);
extern "C" int FUN_00267090(hulk_intptr ptr) {
    Obj_267090** p = FUN_00266f50(((char*)&DAT_00527f40), ptr);
    return (*p)->f4(ptr);
}