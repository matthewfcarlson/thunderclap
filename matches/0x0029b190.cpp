// Same code shape as 0x0032d960 (propagated; names are from that function)
#include "gen/pure3d.h"

class pddiObject_29b190 {
  public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
};

class pddiShader_29b190 : public pddiObject_29b190 {};

class pddiBaseShader_29b190 : public pddiShader_29b190 {
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

class d3dShader_29b190 : public pddiBaseShader_29b190 {
  public:
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc21();
};

int pure3d::TextString::vfunc_5() {
    return 1;
}
