// Same code shape as 0x0032d960 (propagated; names are from that function)
#include "gen/core.h"

class pddiObject_273d40 {
  public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
};

class pddiShader_273d40 : public pddiObject_273d40 {};

class pddiBaseShader_273d40 : public pddiShader_273d40 {
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

class d3dShader_273d40 : public pddiBaseShader_273d40 {
  public:
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc21();
};

int core::SaveGameOpenRequest::vfunc_6() {
    return 1;
}
