#include "gen/audio.h"

class SeqAction_255560 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    char pad[8];
};
void ReleaseThing(int);

void audio::SeqActionCrossFade::vfunc_4(int unused) {
    if (this->f_10) {
        ReleaseThing(this->f_10);
        this->f_10 = 0;
    }
    this->f_0c = 0;
}
