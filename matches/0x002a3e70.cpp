// Same code shape as 0x0032d960 (propagated; names are from that function)
#include "gen/pure3d.h"

class pddiObject_2a3e70 {
  public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
};

class pddiShader_2a3e70 : public pddiObject_2a3e70 {};

class pddiBaseShader_2a3e70 : public pddiShader_2a3e70 {
  public:
    virtual void vfunc5();
    virtual void vfunc6();
    virtual void vfunc7();
    virtual void vfunc8();
    virtual void vfunc9();
    virtual void vfunc10();
    virtual int UsesLayeredTexture();
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc19();
    virtual void vfunc20();
};

class d3dShader_2a3e70 : public pddiBaseShader_2a3e70 {
  public:
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc21();
};

int pure3d::DrawableContainer::vfunc_5() {
    return 1;
}
