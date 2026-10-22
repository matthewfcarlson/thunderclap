#include "compat/ptr.h"
class Obj_32ffe0 {
  public:
    virtual void a();
    virtual void b();
};
extern int vtable_32ffe0;
class d3dToon2VertexShader_32ffe0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual d3dToon2VertexShader_32ffe0* vfunc_3(unsigned char);
    char pad[0x7c];
    Obj_32ffe0* p80;
    Obj_32ffe0* p84;
    Obj_32ffe0* p88;
    void helper();
};
void thunk_FUN_00267090(d3dToon2VertexShader_32ffe0*);
d3dToon2VertexShader_32ffe0* d3dToon2VertexShader_32ffe0::vfunc_3(unsigned char flag) {
    *(volatile hulk_intptr*)this = (hulk_intptr)&vtable_32ffe0;
    if (p88)
        p88->b();
    if (p80)
        p80->b();
    if (p84)
        p84->b();
    helper();
    if (flag & 1)
        thunk_FUN_00267090(this);
    return this;
}