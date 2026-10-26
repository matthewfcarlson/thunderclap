#include "compat/ptr.h"
#include "gen/audio.h"

namespace audio {

class SeqActionWait_250460 {
  public:
    virtual void v0();
    virtual void v1();
    int pad;
    audio::SeqEventWait* event;
    int zero;
    SeqActionWait_250460(audio::SeqEventWait* e) : event(e), zero(0) {}
};
} // namespace audio
class Target {
  public:
    void set(audio::SeqActionWait_250460*);
};
namespace audio {
class SeqEvent_250460 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
} // namespace audio
extern char bss;
extern "C" void* __cdecl alloc(void*);
void audio::SeqEventWait::vfunc_2(hulk_intptr __p0) { Target * p = (Target *)__p0;

    audio::SeqActionWait_250460* a = (audio::SeqActionWait_250460*)alloc(&bss);
    p->set(a ? (a->audio::SeqActionWait_250460::SeqActionWait_250460(this), a) : 0);
}
