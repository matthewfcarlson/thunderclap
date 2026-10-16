// Same code shape as 0x0032d960 (propagated; names are from that function)
#include "gen/global.h"

class pddiObject_1b8ff0 {
  public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
};

class pddiShader_1b8ff0 : public pddiObject_1b8ff0 {};

class pddiBaseShader_1b8ff0 : public pddiShader_1b8ff0 {
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

class d3dShader_1b8ff0 : public pddiBaseShader_1b8ff0 {
  public:
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc21();
};

int CRenderManager::vfunc_2() {
    return 1;
}
