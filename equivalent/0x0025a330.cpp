// STATUS: equivalent (tools/equiv.py level 3: 2886 inputs, branch coverage 2/2)
// audio::MixBuss::vfunc_0 @ 0x0025a330
#include "compat/ptr.h"
#include "gen/audio.h"

struct BussData {
    char reserved[0x24];
    int nameCount;
};
unsigned int __cdecl FUN_00246f50(BussData *data, const char *format, ...);
namespace audio {
}
int audio::MixBuss::vfunc_0(hulk_intptr __p0) { BussData ** data = (BussData **)__p0;

    unsigned int result = FUN_00246f50(*data, "[\n");
    if ((unsigned char)result != 0) {
        ++(*data)->nameCount;
        result = FUN_00246f50(*data, "%s ", "mName");
    }
    return (int)(result & 0xffffff00U);
}
