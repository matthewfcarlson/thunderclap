#include "gen/pure3d.h"

#include "compat/ptr.h"
extern "C" char DAT_0042d1ec[];
extern "C" char DAT_0042d28c[];
extern "C" void _ReadWriteBarrier();
class Ref_296b50 {
  public:
    virtual void f();
    virtual void Release() throw();
};
struct DrawableNode_nv_296b50 {
    void Finish();
};

void pure3d::scenegraph::DrawableNode::FUN_00296b50() {
    *(void**)this = (void*)((hulk_intptr)DAT_0042d28c);
    _ReadWriteBarrier();
    if ((*(Ref_296b50 * *)&this->f_18)) {
        (*(Ref_296b50 * *)&this->f_18)->Release();
        (*(Ref_296b50 * *)&this->f_18) = 0;
    }
    *(void**)this = (void*)((hulk_intptr)DAT_0042d1ec);
    ((DrawableNode_nv_296b50*)this)->Finish();
}
