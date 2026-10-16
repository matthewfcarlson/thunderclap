// Same code shape as 0x00242070 (propagated; names are from that function)
#include "gen/audio.h"

typedef unsigned int u32_2559e0;
extern "C" void* __cdecl FUN_00247530(void*);
struct Callee_2559e0 {
    u32_2559e0 run();
};
extern char g_data_2559e0[];
namespace audio {

} // namespace audio
void* audio::SeqEventCrossFadeType::vfunc_3() {
    void* p = FUN_00247530(g_data_2559e0);
    if (p)
        return (void*)(((Callee_2559e0*)p)->run());
    return (void*)(0);
}
