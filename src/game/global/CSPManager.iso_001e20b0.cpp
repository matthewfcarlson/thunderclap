// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001db770..0x001e5f10 (kind game, layer game, confidence high), dominant class CSPManager
// (tree_prelude.h: not needed)


// 0x001e20b0 Closure3<CSPManager,void,const_char_*,const_char_*,math::Vector>::vfunc_2 (56 B): equivalent/0x001e20b0.cpp [isolated: conflict: Arguments; on include/gen/ and not mergeable]
// sym: ?vfunc_2@?$Closure3@VCSPManager@@XPBDPBDVVector@math@@@@UAEXPAX00@Z @d2144190d08a @w0e17802db584
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Closure3<CSPManager,void,const_char_*,const_char_*,math::Vector>::vfunc_2 @ 0x001e20b0
#include "gen/global.h"

struct Vector_1e20b0 { float x, y, z; };
struct CSPManager_1e20b0 {
    void FUN_001e20b0(const char *, const char *, Vector_1e20b0);
};
struct Arguments {
    const char *first;
    const char *second;
    Vector_1e20b0 position;
};

template <> void Closure3<CSPManager, void, const char *, const char *,math::Vector>::vfunc_2(void* __p0, void* __p1, void* __p2) { const Arguments * arguments = (const Arguments *)__p1;

    ((*(CSPManager_1e20b0 * *)&this->f_20)->*(*(void (CSPManager_1e20b0::**)(const char *, const char *, Vector_1e20b0))&this->f_1c))(arguments->first, arguments->second, arguments->position);
}

