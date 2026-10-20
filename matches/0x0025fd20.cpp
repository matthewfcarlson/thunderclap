#include "compat/ptr.h"
#include "gen/audio.h"

typedef unsigned int u32_25fd20;
namespace audio {
} // namespace audio
extern int FUN_00263db0(u32_25fd20, u32_25fd20);
int audio::SeqEvent::vfunc_0(void* __p0) { hulk_uintptr param_1 = (hulk_uintptr)__p0;

    return FUN_00263db0(param_1, 0);
}
