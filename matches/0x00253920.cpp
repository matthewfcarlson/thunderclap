#include "gen/audio.h"
#include "decls/data/engine/audio.h"
// data: gHeap = DAT_004e7198

void* Alloc(char*);
inline void* operator new(unsigned int, void* p) {
    return p;
}
namespace audio {
class SeqEvent_253920 {
  public:
    SeqEvent_253920();
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    int unknown;
    float pitch;
};
class SeqEventVarPitch_253920 : public SeqEvent_253920 {
  public:
    SeqEventVarPitch_253920() { pitch = 1.0f; }
    virtual void a();
};
} // namespace audio
void* audio::SeqEventVarPitchType::vfunc_3() {
    void* p = Alloc(((char*)&DAT_004e7198));
    if (p)
        return (void*)(new (p) audio::SeqEventVarPitch_253920);
    return (void*)(0);
}
