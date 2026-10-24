#include "compat/ptr.h"
#include "decls/data/engine/audio.h"
#include "gen/audio.h"

extern "C" char DAT_004298fc[];
extern void FUN_00247550(void*, void*);

class SeqActionVarVolume_252a20 : public audio::SeqAction {
  public:
    SeqActionVarVolume_252a20* vfunc_0(int);
};
SeqActionVarVolume_252a20* SeqActionVarVolume_252a20::vfunc_0(int x) {
    *(hulk_ulongptr*)this = ((hulk_intptr)DAT_004298fc);
    if (x & 1)
        FUN_00247550((void*)((hulk_intptr)DAT_004e6e90), this);
    return this;
}