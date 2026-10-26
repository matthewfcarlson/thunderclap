#include "compat/ptr.h"
#include "gen/audio.h"

class SeqAction_255dc0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void vfunc_3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};
namespace audio {
} // namespace audio
int __cdecl Check(int);
void __cdecl DoThing(int);
void audio::SeqActionClip::vfunc_3(hulk_intptr arg) {
    int x = this->f_14;
    if (x != 0 && Check(x) == 1)
        DoThing(this->f_14);
    this->f_18 = 4;
}
