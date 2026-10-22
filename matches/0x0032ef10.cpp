#include "compat/ptr.h"
#include "gen/pure3d.h"
extern "C" char DAT_00433cac[];
class Obj_32ef10 {
  public:
    virtual void A();
    virtual void B();
};
struct d3dRefractVertexShader_nv_32ef10 {
    void Go();
};
class d3dRefractVertexShader_32ef10 {
  public:
    virtual void A();
    char pad[0x7c];
    Obj_32ef10* a;
    Obj_32ef10* b;
    void F();
};
void d3dRefractVertexShader_32ef10::F() {
    Obj_32ef10* x = a;
    *(hulk_intptr*)this = ((hulk_intptr)DAT_00433cac);
    if (x)
        x->B();
    Obj_32ef10* y = b;
    if (y)
        y->B();
    ((d3dRefractVertexShader_nv_32ef10*)(((pure3d::d3dRefractVertexShader*)this)))->Go();
}