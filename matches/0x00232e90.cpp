#include "compat/ptr.h"
extern "C" char DAT_00427898[];
typedef unsigned int u32_232e90;
struct Branch_232e90 {
    void Init();
};
struct Inner_232e90 {
    void Init();
};
class Branch {
  public:
    virtual void v0();
    char pad04[12];
    u32_232e90 arg;
    u32_232e90 field14;
    Inner_232e90 inner;
    u32_232e90 field1c;
    u32_232e90 field20;
    Branch* Build(u32_232e90);
};
Branch* Branch::Build(u32_232e90 param) {
    ((Branch_232e90*)this)->Init();
    *((hulk_uintptr*)this) = ((hulk_intptr)DAT_00427898);
    arg = param;
    field14 = 0;
    inner.Init();
    field1c = 0;
    field20 = 0;
    return this;
}