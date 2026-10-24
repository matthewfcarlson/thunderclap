#include "gen/pure3d.h"

#include "compat/ptr.h"
extern "C" char DAT_00433a04[];
class Base_32c270 {
  public:
    virtual void f();
    virtual void Release();
};
struct d3dReflShader_nv_32c270 {
    void Tail();
};

void pure3d::d3dReflShader::FUN_0032c270() {
    Base_32c270* p = (*(Base_32c270 * *)&this->f_80);
    *(hulk_intptr*)this = ((hulk_intptr)DAT_00433a04);
    if (p)
        p->Release();
    p = (*(Base_32c270 * *)&this->f_84);
    if (p)
        p->Release();
    ((d3dReflShader_nv_32c270*)this)->Tail();
}
