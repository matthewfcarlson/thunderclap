#include "compat/ptr.h"
extern "C" char DAT_00421a3c[];
void thunk(int);
class StoreBase {
  public:
    hulk_intptr vp;
    int a[4];
    int b;
    void Fn();
};
void StoreBase::Fn() {
    int t = b;
    vp = ((hulk_intptr)DAT_00421a3c);
    thunk(t);
}
