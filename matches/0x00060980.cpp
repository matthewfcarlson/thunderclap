#include "compat/ptr.h"
#include "gen/global.h"

class CEffectStopTrack_60980 {
  public:
    virtual int f0();
    virtual int f1();
    virtual int f2();
    virtual int f3();
    virtual int f4();
    virtual int f5();
    virtual int f6();
    virtual int f7();
    virtual int f8();
    virtual int f9();
    virtual int f10();
    virtual int f11();
    virtual int vfunc_12(int);
    virtual int f13();
};
struct Obj_60980 {
    char pad[0x104];
    int field;
};
struct CEffectStopAction_60980 {
    char pad[0x104];
    int field;
    int method(hulk_intptr, int);
};
extern void* FUN_0008d690(int);
extern Obj_60980* FUN_0005a430(int);

int CGrappleEffectStopTrack::vfunc_12(int arg) {
    CEffectStopAction_60980* p = (CEffectStopAction_60980*)FUN_0008d690(0x24);
    if (p) {
        Obj_60980* o = FUN_0005a430(arg);
        int v = o->field;
        return p->method((hulk_intptr)this, v);
    }
    return 0;
}
