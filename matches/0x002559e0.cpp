// Same code shape as 0x00242070 (propagated; names are from that function)
#include "decls/data/engine/audio.h"
// data: g_data_2559e0 = DAT_004e7508

#include "compat/ptr.h"
#include "gen/audio.h"

typedef unsigned int u32_2559e0;
extern "C" void* __cdecl FUN_00247530(void*);
struct Callee_2559e0 {
    hulk_uintptr run();
};
namespace audio {

} // namespace audio
void* audio::SeqEventCrossFadeType::vfunc_3() {
    void* p = FUN_00247530(((char*)&DAT_004e7508));
    if (p)
        return (void*)(((Callee_2559e0*)p)->run());
    return (void*)(0);
}
