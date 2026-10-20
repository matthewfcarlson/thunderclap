#include "compat/ptr.h"
struct X_144590 {
    X_144590* a();
    X_144590* b();
    int d(int);
    void e(int);
};
extern X_144590* __cdecl FUN_0027f250();
class MotionTrailStopAction {
  public:
    char pad00[0x1c];
    struct A {
        char pad[0x10];
        int value;
    }* mA;
    hulk_intptr mCheck;
    void vfunc_4();
};
void MotionTrailStopAction::vfunc_4() {
    if (mCheck) {
        X_144590* a = ((X_144590*)mCheck)->a();
        X_144590* b = a->b();
        X_144590* c = FUN_0027f250();
        int t = mA->value;
        int v = b->d(t);
        c->e(v);
    }
}