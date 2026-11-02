#include "gen/audio.h"

class SeqAction_255df0 {
  public:
    virtual void x();
    char pad[0x10];
};
extern "C" int FUN_00259c50(int);
extern "C" void FUN_00258e50(int);

void audio::SeqActionClip::vfunc_4(int ) {
    if (this->f_14 != 0) {
        if (FUN_00259c50(this->f_14) == 1)
            FUN_00258e50(this->f_14);
    }
    this->f_18 = 5;
}
