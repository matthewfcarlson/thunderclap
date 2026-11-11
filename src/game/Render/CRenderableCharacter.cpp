// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001c60b0..0x001c60f0 (kind game, layer game, confidence medium), dominant class Render::CRenderableCharacter
#include "tree_prelude.h"
#include "compat/ptr.h"
#define TREE_TU_BEGIN namespace fn_ffaef9d7 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_ffaef9d7 {} using namespace fn_ffaef9d7;
#include "game/Render.h"

// ---- declarations shared by the functions below
namespace fn_ffaef9d7 {
namespace Render {
class CRenderableCharacter {
  public:
    virtual CRenderableCharacter* vfunc_0(unsigned char flag);
    char pad[4];
};
}
struct Sub_1c60b0 {
    void f(void*);
    void g();
};
extern "C" Sub_1c60b0* FUN_001c3d90();
extern "C" void thunk_FUN_00267090(Render::CRenderableCharacter*);
extern int g_vft_1c60b0;


// 0x001c60b0 Render::CRenderableCharacter::vfunc_0 (56 B): matches/0x001c60b0.cpp
// sym: ?vfunc_0@CRenderableCharacter@Render@fn_ffaef9d7@@UAEPAV123@E@Z
Render::CRenderableCharacter* Render::CRenderableCharacter::vfunc_0(unsigned char flag) {
    Sub_1c60b0* p = (Sub_1c60b0*)((char*)this + 8);
    *(hulk_intptr*)this = (hulk_intptr)&g_vft_1c60b0;
    FUN_001c3d90()->f(p);
    p->g();
    if (flag & 1)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_ffaef9d7
