// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001e85c0..0x001e8710 (kind game, layer game, confidence high), dominant class CSoundMix
// (tree_prelude.h: not needed)


// 0x001e86b0 CSoundMix::vfunc_0 (4 B): matches/0x001e86b0.cpp [isolated: on include/gen/, and its TU merges more functions without the headers; on include/gen/ and not mergeable]
// sym: ?vfunc_0@CSoundMix@@UAEXXZ
// Same code shape as 0x00018b30 (propagated; names are from that function)
#include "gen/global.h"

class IRefCount_1e86b0 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    int mRefCount;
};

void CSoundMix::vfunc_0() {
    ++this->f_04;
}

