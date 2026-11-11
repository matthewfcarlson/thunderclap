// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001c49c0..0x001c5ae0 (kind game, layer game, confidence high), dominant class Render::Object
// (tree_prelude.h: not needed)


// 0x001c5720 FUN_001c5720 (22 B): matches/0x001c5720.cpp [isolated: same definition as 0x001c5640 in this TU; on include/gen/ and not mergeable]
// sym: ??1Store@@QAE@XZ
// Same code shape as 0x001c5640 (propagated; names are from that function)
#include "gen/Render.h"
class Store {
  public:
    virtual void f();
    void Cleanup2_001c7500();
    ~Store();
    int mData;
};
Store::~Store() {
    ((Render::StoreBase *)this)->FUN_001c7720();
    Cleanup2_001c7500();
}

