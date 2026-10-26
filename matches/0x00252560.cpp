#include "gen/audio.h"
#include "decls/data/engine/audio.h"
// data: bss = DAT_004e6a68

namespace audio {
class Base {
  public:
    Base();
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    int unk;
};
class SeqEventVarVolumeRand_252560 : public Base {
  public:
    float x;
    float y;
    SeqEventVarVolumeRand_252560() : Base(), x(0.5f), y(1.0f) {}
};
} // namespace audio
extern "C" void* __cdecl alloc(void*);
void* audio::SeqEventVarVolumeRandType::vfunc_3() {
    audio::SeqEventVarVolumeRand_252560* p = (audio::SeqEventVarVolumeRand_252560*)alloc(((char*)((char*)&DAT_004e6a60 + 8)));
    if (p) {
        p->audio::SeqEventVarVolumeRand_252560::SeqEventVarVolumeRand_252560();
        return (void*)(p);
    }
    return (void*)(0);
}
