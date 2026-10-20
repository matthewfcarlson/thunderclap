#include "gen/audio.h"
extern void* vtable_252380;
class SeqEventVarVolumeRand_252380 {
  public:
    void* vf;
    int pad;
    float a;
    float b;
};
struct SeqEventVarVolumeRand_nv_252380 {
    void Init();
};
SeqEventVarVolumeRand_252380* __fastcall FUN_00252380(SeqEventVarVolumeRand_252380* self) {
    ((SeqEventVarVolumeRand_nv_252380*)(((audio::SeqEventVarVolumeRand*)(self))))->Init();
    self->vf = &vtable_252380;
    self->a = 0.5f;
    self->b = 1.0f;
    return self;
}