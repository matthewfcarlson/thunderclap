// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001065b0..0x00107000 (kind game, layer game, confidence high), dominant class CPatrolPathManager
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x00106c10 Closure3<CPatrolPathManager,bool,const_char_*,bool,int>::vfunc_2 (50 B): matches/0x00106c10.cpp [isolated: conflict: Arguments; on include/gen/ and not mergeable]
// sym: ?vfunc_2@Closure3_106c10@fn_00106c10@@QAEXPAX00@Z
#include "gen/global.h"
#include "game/script_bind.h"

struct CPatrolPathManager_106c10 {
    bool FUN_00106c10(const char*, bool, int);
};
struct Arguments {
    const char* text;
    bool flag;
    char padding[3];
    int count;
};

// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Closure3<CPatrolPathManager, bool, const char *, bool, int>::vfunc_2`.
namespace fn_00106c10 {
struct Closure3_106c10 : hulk_script::FunctionGenView {
    bool (::CPatrolPathManager::*f_1c)(const char *, bool, int);
    hulk_intptr f_20;
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Closure3_106c10::vfunc_2(void* __p0, void* __p1, void* __p2) { hulk_intptr unused = (hulk_intptr)__p0; Arguments * args = (Arguments *)__p1; bool * result = (bool *)__p2;

    Arguments* a = args;
    CPatrolPathManager_106c10* obj = (*(CPatrolPathManager_106c10 * *)&this->f_20);
    bool (CPatrolPathManager_106c10::*fn)(const char*, bool, int) = (*(bool (CPatrolPathManager_106c10::**)(const char *, bool, int))&this->f_1c);
    const char* text = a->text;
    bool flag = a->flag;
    int count = a->count;
    bool value = (obj->*fn)(text, flag, count);
    if (result)
        *result = value;
}
} // namespace fn_00106c10
#if defined(HULK_PTR64)
// (script2) natively gen's template still has this vftable slot (its destructor specializations emit the
// vftable): forward it to the record's function
template <> void Closure3<CPatrolPathManager, bool, const char *, bool, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { ((fn_00106c10::Closure3_106c10*)this)->vfunc_2(__p0, __p1, __p2); }
#endif

