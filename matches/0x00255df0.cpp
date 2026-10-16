#include "gen/audio.h"

class SeqAction_255df0 {
  public:
    virtual void x();
    char pad[0x10];
};
int Check(int);
void Do(int);

void audio::SeqActionClip::vfunc_4(int ) {
    if (this->f_14 != 0) {
        if (Check(this->f_14) == 1)
            Do(this->f_14);
    }
    this->f_18 = 5;
}
