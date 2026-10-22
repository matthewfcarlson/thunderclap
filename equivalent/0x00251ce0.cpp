// STATUS: equivalent (tools/equiv.py level 3: 19929 inputs, branch coverage 54/54)
// audio::ChannelVolumeFadeBehaviour::vfunc_1 @ 0x00251ce0
#include "compat/ptr.h"
namespace audio {
class ChannelVolumeFadeBehaviour {
public:
    virtual void vfunc_0();
    virtual bool vfunc_1(int a1, int elapsed);
    char pad04[0x14];
    int duration;               // 0x18
    unsigned char *targets;     // 0x1c
    float *volumes;             // 0x20
};

// Moves the 16 channel volumes toward their targets (targets[i] / 255); true when all arrived.
bool ChannelVolumeFadeBehaviour::vfunc_1(int a1, int elapsed)
{
    hulk_freg step;
    if (duration == 0)
        step = 1.0f;
    else
        step = (hulk_freg)elapsed / duration;

    int arrived = 0;
    for (int i = 0; i < 16; i++) {
        hulk_freg cur = volumes[i];
        float target = targets[i] * 0.003921569f;
        if (cur < target) {
            hulk_freg v = cur + step;
            if (!(v >= target)) {
                volumes[i] = v;
            } else {
                volumes[i] = target;
                arrived++;
            }
        } else {
            hulk_freg v = cur - step;
            if (!(v <= target)) {
                volumes[i] = v;
            } else {
                volumes[i] = target;
                arrived++;
            }
        }
    }
    return arrived == 16;
}
}
