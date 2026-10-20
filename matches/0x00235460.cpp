// Same code shape as 0x00235300 (propagated; names are from that function)
#include "compat/ptr.h"
class Part_235460 {
  public:
    void Init();
};
namespace fight { class ParamValueStringList {
  public:
    int vt;
    int pad;
    Part_235460 part;
    ParamValueStringList* vfunc_0(int);
}; }
extern int base_vtable;
extern "C" void __cdecl thunk_FUN_00267090(fight::ParamValueStringList*);
fight::ParamValueStringList* fight::ParamValueStringList::vfunc_0(int flag) {
    vt = (hulk_intptr)&base_vtable;
    part.Init();
    if (flag & 1)
        thunk_FUN_00267090(this);
    return this;
}