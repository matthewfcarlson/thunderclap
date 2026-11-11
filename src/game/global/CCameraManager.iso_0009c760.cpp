// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000989d0..0x0009f760 (kind game, layer game, confidence high), dominant class CCameraManager
// (tree_prelude.h: not needed)


// 0x0009c760 Closure5<CCameraManager,void,bool,bool,bool,bool,float>::vfunc_2 (72 B): matches/0x0009c760.cpp [isolated: conflict: V; on include/gen/ and not mergeable]
// sym: ?vfunc_2@?$Closure5@VCCameraManager@@X_N_N_N_NM@@UAEXPAX00@Z
#include "gen/global.h"

class CCameraManager_9c760 {
  public:
    void Set(int, int, int, bool, float);
};
union V {
    bool b;
    int n;
    float f;
};

template <> void Closure5<CCameraManager, void, bool, bool, bool, bool, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { V * args = (V *)__p1;

    V a, b, c;
    a.b = args->b;
    ++args;
    b.b = args->b;
    ++args;
    c.b = args->b;
    ++args;
    ((*(CCameraManager_9c760 * *)&this->f_20)->*(*(void (CCameraManager_9c760::**)(int, int, int, bool, float))&this->f_1c))(a.n, b.n, c.n, args->b, (args + 1)->f);
}

