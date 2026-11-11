// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00038290..0x000382c0 (kind game, layer game, confidence medium), dominant class content::LoadObject
#include "tree_prelude.h"
#include "gen/content.h"
#define TREE_TU_BEGIN namespace fn_f7f8e07d {
#define TREE_TU_END }
namespace fn_f7f8e07d {} using namespace fn_f7f8e07d;
#include "common.h"

// ---- declarations shared by the functions below
namespace fn_f7f8e07d {
class IRefCount_38290 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    int mRefCount;
};

} // namespace fn_f7f8e07d

// 0x00038290 content::LoadObject::vfunc_0 (4 B): matches/0x00038290.cpp
// sym: ?vfunc_0@LoadObject@content@@UAEXXZ
// Same code shape as 0x00018b30 (propagated; names are from that function)
void content::LoadObject::vfunc_0() {
    ++this->f_04;
}


// 0x000382a0 content::LoadObject::vfunc_1 (28 B): matches/0x000382a0.cpp [wrapped: conflict: content::LoadObject; core::IRefCount]
// sym: ?vfunc_1@LoadObject@content@fn_000382a0@@UAEXXZ
namespace fn_000382a0 {
namespace core {
class IRefCount {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(int);
    unsigned int count;
};
} // namespace core
namespace content {
class LoadObject : public core::IRefCount {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(int);
};
void LoadObject::vfunc_1() {
    if (count < 2) {
        volatile unsigned int* q = &count;
        *q = 0x8000000;
        vfunc_2(1);
        return;
    }
    --count;
}
} // namespace content
} // namespace fn_000382a0

