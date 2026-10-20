#include "compat/ptr.h"
#include "gen/pure3d.h"

extern "C" char DAT_0042d330[];
class Ref_296c50 {
  public:
    virtual void f0();
    virtual void Release();
};
struct Callback_296c50 {
    void* vt;
    Ref_296c50* result;
};
extern void FUN_00296220(Ref_296c50*, Callback_296c50*);

void pure3d::scenegraph::Scenegraph::vfunc_14() {
    if ((*(Ref_296c50 * *)&this->f_10)) {
        (*(Ref_296c50 * *)&this->f_10)->Release();
        (*(Ref_296c50 * *)&this->f_10) = 0;
    }
    if ((*(Ref_296c50 * *)&this->f_40)) {
        Callback_296c50 c;
        c.vt = (void*)((hulk_intptr)DAT_0042d330);
        c.result = 0;
        FUN_00296220((*(Ref_296c50 * *)&this->f_40), &c);
        c.vt = (void*)((hulk_intptr)DAT_0042d330);
        if (c.result)
            ((class Ref_296c50*)c.result)->Release();
    }
}
