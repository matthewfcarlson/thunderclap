#include "compat/ptr.h"
extern "C" char DAT_00433e64[];
class Shader {
  public:
    virtual void F0();
    virtual void F1();
};
class d3dSpheremapVertexShader_331690 {
  public:
    hulk_intptr vft;
    char pad[0x7c];
    Shader* a;
    Shader* b;
    void Fn();
    void End();
};
void d3dSpheremapVertexShader_331690::Fn() {
    Shader* x = a;
    vft = ((hulk_intptr)DAT_00433e64);
    if (x)
        x->F1();
    x = b;
    if (x)
        x->F1();
    End();
}
