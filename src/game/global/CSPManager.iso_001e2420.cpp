// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001db770..0x001e5f10 (kind game, layer game, confidence high), dominant class CSPManager
// (tree_prelude.h: not needed)


// 0x001e2420 Closure3<CSPManager,void,int,int,const_char_*>::vfunc_2 (28 B): matches/0x001e2420.cpp [isolated: conflict: Arguments; on include/gen/ and not mergeable]
// sym: ?vfunc_2@Closure3_1e2420@fn_001e2420@@QAEXPAX00@Z
#include "gen/global.h"
#include "game/script_bind.h"

extern "C" void _ReadWriteBarrier();
struct CSPManager_1e2420 {};
struct Arguments {
    int a;
    int b;
    const char* c;
};

// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Closure3<CSPManager, void, int, int, const char *>::vfunc_2`.
namespace fn_001e2420 {
struct Closure3_1e2420 : hulk_script::FunctionGenView {
    void (::CSPManager::*f_1c)(int, int, const char *);
    hulk_intptr f_20;
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Closure3_1e2420::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; Arguments * args = (Arguments *)__p1; void * unused2 = (void *)__p2;

    int a = args->a;
    _ReadWriteBarrier();
    int b = args->b;
    const char* c = args->c;
    ((*(CSPManager_1e2420 * *)&this->f_20)->*(*(void (CSPManager_1e2420::**)(int, int, const char *))&this->f_1c))(a, b, c);
    _ReadWriteBarrier();
}
} // namespace fn_001e2420

