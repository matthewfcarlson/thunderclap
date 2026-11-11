// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00242070..0x00242090 (kind game, layer engine, confidence medium), dominant class audio::MixType
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/audio.h"
#include "gen/audio.h"
#define TREE_TU_BEGIN namespace fn_ff111a58 {
#define TREE_TU_END }
namespace fn_ff111a58 {} using namespace fn_ff111a58;
#include "engine/audio.h"

// ---- declarations shared by the functions below
namespace fn_ff111a58 {
typedef unsigned int u32_242070;
extern "C" void* __cdecl FUN_00247530(void*);
struct Callee_242070 {
    hulk_uintptr run_0025a2c0();
};

} // namespace fn_ff111a58

// 0x00242070 audio::MixType::vfunc_2 (27 B): matches/0x00242070.cpp
// sym: ?vfunc_2@MixType@audio@@UAEPAXXZ
// data: g_data_242070 = DAT_004e5cf8
 // namespace audio
void* audio::MixType::vfunc_2() {
    void* p = FUN_00247530(((char*)&DAT_004e5cf8));
    if (p)
        return (void*)(((Callee_242070*)p)->run_0025a2c0());
    return (void*)(0);
}

