// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000ff230..0x00102a50 (kind game, layer game, confidence high), dominant class CHand2HandAgent
// (tree_prelude.h: not needed)


// 0x00102550 CHand2HandAgent::vfunc_18 (52 B): matches/0x00102550.cpp [isolated: on include/gen/, and its TU merges more functions without the headers; on include/gen/ and not mergeable]
// sym: ?vfunc_18@CHand2HandAgent@@UAE_NM@Z
#include "gen/global.h"

bool CHand2HandAgent::vfunc_18(float limit) {
    float d = this->f_8c - this->f_a8;
    union {
        float f;
        unsigned int i;
    } u;
    u.f = d;
    u.i &= 0x7fffffff;
    return u.f < limit;
}

