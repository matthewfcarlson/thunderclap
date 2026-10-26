#include "decls/data/engine/core.h"
// data: g_saved = DAT_004cdbb0

#include "compat/ptr.h"
#include "gen/core.h"
extern "C" char DAT_0042af64[];

class Object_267ed0 : public core::BaseObject {
  public:
    int field;
    virtual Object_267ed0* vfunc_0(unsigned char);
};
extern void __cdecl FUN_00266f00(int, Object_267ed0*);
Object_267ed0* Object_267ed0::vfunc_0(unsigned char param) {
    (*(volatile int*)&DAT_004cdbb0) = field;
    *(hulk_ulongptr*)this = ((hulk_intptr)DAT_0042af64);
    if (param & 1)
        FUN_00266f00((*(volatile int*)&DAT_004cdbb0), this);
    return this;
}