#include "gen/pure3d.h"

#include "compat/ptr.h"
extern "C" char DAT_0043386c[];
class Ref_32a3d0 {
  public:
    virtual void F0();
    virtual void F1();
};
struct d3dSimpleShader_nv_32a3d0 {
    void Next();
};

void pure3d::d3dSimpleShader::FUN_0032a3d0() {
    *(hulk_ulongptr*)this = ((hulk_intptr)DAT_0043386c);
    if ((*(Ref_32a3d0 * *)&this->f_80))
        (*(Ref_32a3d0 * *)&this->f_80)->F1();
    ((d3dSimpleShader_nv_32a3d0*)this)->Next();
}
