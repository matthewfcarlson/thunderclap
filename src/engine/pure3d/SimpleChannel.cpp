// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0028df60..0x0028dfc0 (kind game, layer engine, confidence medium), dominant class pure3d::SimpleChannel
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_ff0c407b {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_ff0c407b {} using namespace fn_ff0c407b;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_ff0c407b {
extern void* hulk_at_0042c930[];
} // namespace fn_ff0c407b
void operator delete(void*);
namespace fn_ff0c407b {
class Ref_28df60 {
  public:
    virtual void F0();
    virtual void Release();
};
class Channel_28df60 {
  public:
    void* vptr;
};
class SimpleChannel_28df60 : public Channel_28df60 {
  public:
    char pad[8];
    Ref_28df60* mc;
    void* m10;
    void* m14;
    SimpleChannel_28df60* f0(unsigned char flags);
};


// 0x0028df60 pure3d::SimpleChannel::vfunc_0 (84 B): matches/0x0028df60.cpp
// sym: ?f0@SimpleChannel_28df60@fn_ff0c407b@@QAEPAV12@E@Z
SimpleChannel_28df60* SimpleChannel_28df60::f0(unsigned char flags) {
    vptr = hulk_at_0042c930;
    if (!mc) {
        operator delete[](m14);
    } else {
        _ReadWriteBarrier();
        if (mc) {
            mc->Release();
            mc = 0;
        }
    }
    m14 = 0;
    vptr = g_vftable2;
    if (flags & 1)
        operator delete(this);
    return this;
}

} // namespace fn_ff0c407b
