// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001c7e60..0x001c7e90 (kind game, layer game, confidence medium), dominant class pure3d::ShadowGenerator
#include "tree_prelude.h"
#include "compat/ptr.h"
#define TREE_TU_BEGIN namespace fn_fa25ba40 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fa25ba40 {} using namespace fn_fa25ba40;
#include "game/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_fa25ba40 {
extern "C" char DAT_003f6098[];
struct NonCopyable {
    virtual void f0();
    virtual void f1();
};
struct IRefCount {
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void destroy(void*);
struct Sub_1c7e60 {
    void cleanup();
};
namespace pure3d {
struct ShadowGenerator : NonCopyable {
    char pad[4];
    Sub_1c7e60 sub;
    ShadowGenerator* vfunc_2(unsigned char);
};
}


// 0x001c7e60 pure3d::ShadowGenerator::vfunc_2 (39 B): matches/0x001c7e60.cpp
// sym: ?vfunc_2@ShadowGenerator@pure3d@fn_fa25ba40@@QAEPAU123@E@Z
 // namespace pure3d
pure3d::ShadowGenerator* pure3d::ShadowGenerator::vfunc_2(unsigned char flags) {
    sub.cleanup();
    *(hulk_ulongptr*)this = ((hulk_intptr)DAT_003f6098);
    if (flags & 1)
        destroy(this);
    return this;
}

} // namespace fn_fa25ba40
