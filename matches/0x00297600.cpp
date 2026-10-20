#include "compat/ptr.h"
extern "C" char DAT_0042d3bc[];
class Ref_297600 {
  public:
    virtual void f0();
    virtual void f1();
};
class TransformNode {
  public:
    virtual void f0();
    virtual void f1();
    TransformNode* vfunc_2(unsigned int p);
    void helper();
    char pad[0xA8 - 4];
    Ref_297600* ref;
};
void __cdecl thunk_FUN_00267090(TransformNode*);
TransformNode* TransformNode::vfunc_2(unsigned int p) {
    *(volatile hulk_intptr*)this = ((hulk_intptr)DAT_0042d3bc);
    Ref_297600* r = *(Ref_297600* volatile*)&ref;
    if (r) {
        r->f1();
        ref = 0;
    }
    helper();
    if (p & 1)
        thunk_FUN_00267090(this);
    return this;
}
