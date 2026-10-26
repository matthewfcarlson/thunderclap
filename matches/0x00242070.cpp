#include "decls/data/engine/audio.h"
// data: g_data_242070 = DAT_004e5cf8

#include "compat/ptr.h"
#include "gen/audio.h"

typedef unsigned int u32_242070;
extern "C" void* __cdecl FUN_00247530(void*);
struct Callee_242070 {
    hulk_uintptr run();
};
namespace audio {

} // namespace audio
void* audio::MixType::vfunc_2() {
    void* p = FUN_00247530(((char*)&DAT_004e5cf8));
    if (p)
        return (void*)(((Callee_242070*)p)->run());
    return (void*)(0);
}
