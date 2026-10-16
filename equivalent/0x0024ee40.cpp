// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 30/30)
// audio::ChannelSendVolumeFadeBehaviour::vfunc_1 @ 0x0024ee40
#include "decls/data/game/global.h"

namespace om {
class DynBehaviour {
public:
    virtual void vfunc_0();
};
}

namespace audio {
class ChannelSendVolumeFadeBehaviour : public om::DynBehaviour {
public:
    virtual void vfunc_0();
    virtual bool vfunc_1(int unused, int elapsed);

    char pad4[0x14];
    int duration;                    // 0x18
    unsigned char *targets;          // 0x1c, byte targets 0..255
    float *current;                  // 0x20
};
}


bool audio::ChannelSendVolumeFadeBehaviour::vfunc_1(int unused, int elapsed)
{
    double step;
    if (duration == 0)
        step = (*(float*)&DAT_003f32dc);
    else
        step = (double)elapsed / (double)duration;

    int reached = 0;
    for (int i = 0; i < 64; i++) {
        float target = (float)targets[i] * 0.0039215689f;
        float *p = &current[i];
        double c = *p;
        if (c < target) {
            c = c + step;
            if (c >= target) {
                c = target;
                reached++;
            }
        } else {
            c = c - step;
            if (c <= target) {
                c = target;
                reached++;
            }
        }
        *p = (float)c;
    }
    return reached == 64;
}
