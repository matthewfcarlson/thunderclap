// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001f0ab0..0x001f2db0 (kind game, layer game, confidence high), dominant class CSoundSystem
// (tree_prelude.h: not needed)


// 0x001f2190 Closure3<CSoundSystem,void,char_*,float,float>::vfunc_2 (28 B): equivalent/0x001f2190.cpp [isolated: conflict: SoundArgs; on include/gen/ and not mergeable]
// sym: ?vfunc_2@Closure3_1f2190@fn_001f2190@@QAEXPAX00@Z @737c210bc5da @w4be225ef0d24 @vc1e7f4ec70c6
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Closure3<CSoundSystem,void,char_*,float,float>::vfunc_2 @ 0x001f2190
#include "gen/global.h"
#include "game/script_bind.h"

struct CSoundSystem_1f2190 {};
struct SoundArgs { char *name; float first; float second; };

// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Closure3<CSoundSystem, void, char *, float, float>::vfunc_2`.
namespace fn_001f2190 {
struct Closure3_1f2190 : hulk_script::FunctionGenView {
    void (::CSoundSystem::*f_1c)(char *, float, float);
    hulk_intptr f_20;
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Closure3_1f2190::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; SoundArgs * args = (SoundArgs *)__p1; void * unused2 = (void *)__p2;

    ((*(CSoundSystem_1f2190 * *)&this->f_20)->*(*(void (CSoundSystem_1f2190::**)(char *, float, float))&this->f_1c))(args->name, args->first, args->second);
}
} // namespace fn_001f2190

