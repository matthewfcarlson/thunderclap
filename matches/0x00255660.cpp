#include "compat/ptr.h"
#include "decls/data/engine/audio.h"
#include "gen/audio.h"

extern "C" char DAT_004298fc[];

extern void __cdecl FUN_00247550(void*, void*);
class SeqActionCrossFade_255660 : public audio::SeqAction {
  public:
    virtual SeqActionCrossFade_255660* vfunc_0(int);
};
SeqActionCrossFade_255660* SeqActionCrossFade_255660::vfunc_0(int flag) {
    *(void**)this = (void*)((hulk_intptr)DAT_004298fc);
    if (flag & 1)
        FUN_00247550((void*)((hulk_intptr)DAT_004e74c0), this);
    return this;
}