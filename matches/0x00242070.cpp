#include "gen/audio.h"

typedef unsigned int u32_242070;
extern "C" void* __cdecl FUN_00247530(void*);
struct Callee_242070 {
    u32_242070 run();
};
extern char g_data_242070[];
namespace audio {

} // namespace audio
void* audio::MixType::vfunc_2() {
    void* p = FUN_00247530(g_data_242070);
    if (p)
        return (void*)(((Callee_242070*)p)->run());
    return (void*)(0);
}
