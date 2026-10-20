// Same code shape as 0x00235300 (propagated; names are from that function)
#include "compat/ptr.h"
class Part_2353c0 {
  public:
    void Init();
};
namespace fight { class ParamValueName {
  public:
    hulk_intptr vt;
    int pad;
    Part_2353c0 part;
    ParamValueName* vfunc_0(int);
}; }
extern int base_vtable;
extern "C" void __cdecl thunk_FUN_00267090(fight::ParamValueName*);
fight::ParamValueName* fight::ParamValueName::vfunc_0(int flag) {
    vt = (hulk_intptr)&base_vtable;
    part.Init();
    if (flag & 1)
        thunk_FUN_00267090(this);
    return this;
}