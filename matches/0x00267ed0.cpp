#include "compat/ptr.h"
#include "gen/core.h"
extern "C" char DAT_0042af64[];

class Object_267ed0 : public core::BaseObject {
  public:
    int field;
    virtual Object_267ed0* vfunc_0(unsigned char);
};
extern volatile int g_saved;
extern void __cdecl FUN_00266f00(int, Object_267ed0*);
Object_267ed0* Object_267ed0::vfunc_0(unsigned char param) {
    g_saved = field;
    *(hulk_ulongptr*)this = ((hulk_intptr)DAT_0042af64);
    if (param & 1)
        FUN_00266f00(g_saved, this);
    return this;
}