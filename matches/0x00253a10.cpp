#include "decls/data/engine/audio.h"

#include "compat/ptr.h"
extern "C" char DAT_004298fc[];
extern int SeqActionVftable;
extern void __cdecl FUN_00247550(void*, void*);
class SeqAction {
  public:
    int* vptr;
};
class SeqActionVarPitch : public SeqAction {
  public:
    SeqAction* vfunc_0(int);
};
SeqAction* SeqActionVarPitch::vfunc_0(int flag) {
    SeqAction* self = this;
    vptr = (int*)((hulk_intptr)DAT_004298fc);
    if (flag & 1)
        FUN_00247550(((int*)((char*)&DAT_004e70e8 + 104)), self);
    return self;
}