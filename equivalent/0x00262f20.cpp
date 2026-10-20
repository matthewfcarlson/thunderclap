// STATUS: equivalent (tools/equiv.py level 3: 20001 inputs, branch coverage 9/9)
// audio::HalRsdFileStream::vfunc_1 @ 0x00262f20
#include "gen/audio.h"

namespace audio { class HalStream_262f20 { public: virtual void vfunc_0(); virtual int vfunc_1(); };   }
int audio::HalRsdFileStream::vfunc_1() { switch (this->f_44) { case 0: return 0; case 1: case 3: return 1; case 4: case 5: case 6: return 2; default: return 3; } }
