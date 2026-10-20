// STATUS: equivalent (tools/equiv.py level 3: 20001 inputs, branch coverage 7/7)
// audio::HalRadicalAdpcmDecodeStream::vfunc_1 @ 0x00262c70
#include "gen/audio.h"

namespace audio {
class HalStream_262c70 {
public:
    virtual void vfunc_0();
    virtual int vfunc_1();
};

}
int audio::HalRadicalAdpcmDecodeStream::vfunc_1() {
    switch ((*(unsigned int *)&this->f_1c)) {
    case 0: return 0;
    case 1: return 1;
    case 2:
    case 3:
    case 4: return 2;
    default: return 3;
    }
}
