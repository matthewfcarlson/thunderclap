#include "decls/data/engine/audio.h"
// data: g_seqVarVolumeHeap = DAT_004e6ed8

#include "compat/ptr.h"
#include "gen/audio.h"

extern "C" char DAT_00429fac[];
typedef unsigned int u32_252930;
namespace audio {
class SeqEventType_252930 {
  public:
    virtual ~SeqEventType_252930();
    virtual void f1();
    virtual void f2();
    virtual void f3();
};
class SeqEventVarVolume_252930 {
  public:
    void* vptr;
    u32_252930 pad;
    float volume;
    void Init();
};
} // namespace audio
extern "C" audio::SeqEventVarVolume_252930* FUN_00247530(void*);
void* audio::SeqEventVarVolumeType::vfunc_3() {
    audio::SeqEventVarVolume_252930* p = FUN_00247530((void*)((char*)&DAT_004e6ed8));
    if (p) {
        p->Init();
        p->vptr = (void*)((hulk_intptr)DAT_00429fac);
        p->volume = 1.0f;
        return (void*)(p);
    }
    return (void*)(0);
}
