// Same code shape as 0x002226e0 (propagated; names are from that function)
#include "gen/audio.h"

class Inner_262fc0 {
  public:
    void call();
};

void audio::HalRsdFileStream::vfunc_10() {
    ((Inner_262fc0*)((char*)this + 0x10))->call();
}
