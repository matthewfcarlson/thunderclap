#include "compat/ptr.h"
extern "C" char DAT_0043386c[];
class Ref_32a3d0 {
  public:
    virtual void F0();
    virtual void F1();
};
struct d3dSimpleShader_32a3d0 {
    char pad[0x80];
    Ref_32a3d0* member;
    void Target();
    void Next();
};
void d3dSimpleShader_32a3d0::Target() {
    *(hulk_ulongptr*)this = ((hulk_intptr)DAT_0043386c);
    if (member)
        member->F1();
    Next();
}
