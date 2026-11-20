// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001065b0..0x00107000 (kind game, layer game, confidence high), dominant class CPatrolPathManager
// (tree_prelude.h: not needed)


// 0x00106d30 Closure3<CPatrolPathManager,bool,const_char_*,int,math::Vector>::vfunc_2 (70 B): equivalent/0x00106d30.cpp [isolated: conflict: Arguments; on include/gen/ and not mergeable]
// sym: ?vfunc_2@Closure3_106d30@fn_00106d30@@QAEXPAX00@Z @dae50ec2a7b3 @wfceb4ac08c55 @v806e123f5663
// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 2/2)
// Closure3<CPatrolPathManager,bool,const_char_*,int,math::Vector>::vfunc_2 @ 0x00106d30
#include "gen/global.h"
#include "game/script_bind.h"

struct Vector_106d30 { float x,y,z; };
struct CPatrolPathManager_106d30 { bool invoke(const char*, int, Vector_106d30); };
struct Arguments { const char* name; int index; Vector_106d30 position; };

// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Closure3<CPatrolPathManager, bool, const char *, int,math::Vector>::vfunc_2`.
namespace fn_00106d30 {
struct Closure3_106d30 : hulk_script::FunctionGenView {
    bool (::CPatrolPathManager::*f_1c)(const char *, int, math::Vector);
    hulk_intptr f_20;
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Closure3_106d30::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; const Arguments * arguments = (const Arguments *)__p1; bool * result = (bool *)__p2;

    bool value = ((*(CPatrolPathManager_106d30 * *)&this->f_20)->*(*(bool (CPatrolPathManager_106d30::**)(const char *, int, Vector_106d30))&this->f_1c))(arguments->name, arguments->index, arguments->position);
    if (result) *result = value;
}
} // namespace fn_00106d30

