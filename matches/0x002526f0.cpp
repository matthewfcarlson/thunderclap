#include "gen/audio.h"

inline void* operator new(unsigned int, void* p) {
    return p;
}
namespace audio {

class SeqActionVarVolumeRand_2526f0 {
  public:
    virtual void v0();
    virtual void v1();
    int unused;
    audio::SeqEventVarVolumeRand* owner;
    int value;
    SeqActionVarVolumeRand_2526f0(audio::SeqEventVarVolumeRand* p) : owner(p), value(0) {}
};
class Receiver {
  public:
    void Set(SeqActionVarVolumeRand_2526f0*);
};
class SeqEvent_2526f0 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(Receiver*);
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
};
} // namespace audio
extern char bss;
extern "C" void* __cdecl FUN_00247530(void*);
void audio::SeqEventVarVolumeRand::vfunc_2(int __p0) { Receiver * r = (Receiver *)__p0;

    void* p = FUN_00247530(&bss);
    SeqActionVarVolumeRand_2526f0* a = p ? new (p) SeqActionVarVolumeRand_2526f0(this) : 0;
    r->Set(a);
}
