// Same code shape as 0x00235300 (propagated; names are from that function)
#include "compat/ptr.h"
class Part_235590 {
  public:
    void Init();
};
class ParamValueVector_235590 {
  public:
    hulk_intptr vt;
    int pad;
    Part_235590 part;
    ParamValueVector_235590* vfunc_0(int);
};
extern int base_vtable;
extern "C" void __cdecl thunk_FUN_00267090(ParamValueVector_235590*);
ParamValueVector_235590* ParamValueVector_235590::vfunc_0(int flag) {
    vt = (hulk_intptr)&base_vtable;
    part.Init();
    if (flag & 1)
        thunk_FUN_00267090(this);
    return this;
}