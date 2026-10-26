#include "gen/audio.h"
#include "decls/data/engine/audio.h"

class SeqEventVarVolumeRand_2525a0 : public audio::SeqEvent {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual SeqEventVarVolumeRand_2525a0* vfunc_4(int);
};
extern void __fastcall FUN_0025fd10(void*);
extern void FUN_00247550(void*, SeqEventVarVolumeRand_2525a0*);
SeqEventVarVolumeRand_2525a0* SeqEventVarVolumeRand_2525a0::vfunc_4(int x) {
    FUN_0025fd10((void*)(this));
    if (x & 1)
        FUN_00247550(((char*)((char*)&DAT_004e6de0 + 72)), this);
    return this;
}
