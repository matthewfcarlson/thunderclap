#include "compat/ptr.h"
#include "gen/pure3d.h"
extern "C" char DAT_00433b9c[];
class Shader_32d8e0 {
  public:
    virtual void A();
    virtual void B();
};
struct d3dLayeredShader_nv_32d8e0 {
    void Cleanup();
};
class Thing_32d8e0 {
  public:
    virtual void V();
    char pad[0x7c];
    Shader_32d8e0* a;
    Shader_32d8e0* b;
    void Fn();
};
void Thing_32d8e0::Fn() {
    Shader_32d8e0* a = this->a;
    *(hulk_ulongptr*)this = ((hulk_intptr)DAT_00433b9c);
    if (a)
        a->B();
    Shader_32d8e0* b = this->b;
    if (b)
        b->B();
    ((d3dLayeredShader_nv_32d8e0*)(((pure3d::d3dLayeredShader*)this)))->Cleanup();
}