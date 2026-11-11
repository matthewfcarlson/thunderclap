// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002af280..0x002af2d0 (kind game, layer engine, confidence high), dominant class pure3d::DXTNHandler
#include "tree_prelude.h"
#include "decls/data/engine/pure3d.h"
#include "decls/data/game/unknown.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f7696906 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f7696906 {} using namespace fn_f7696906;
#include "engine/pure3d.h"

namespace fn_f7696906 {

// 0x002af280 pure3d::DXTNHandler::vfunc_6 (6 B): matches/0x002af280.cpp
// sym: _FUN_002af280
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_002af280() {
    return &(*(int*)&DAT_0042e2cc);
}

} // namespace fn_f7696906

// 0x002af290 pure3d::DXTNHandler::vfunc_4 (3 B): matches/0x002af290.cpp
// sym: ?vfunc_4@DXTNHandler@pure3d@@UAE_NXZ
// Same code shape as 0x0032fce0 (propagated; names are from that function)
bool pure3d::DXTNHandler::vfunc_4() {
    return true;
}


// 0x002af2a0 pure3d::DXTNHandler::vfunc_5 (3 B): matches/0x002af2a0.cpp
// sym: ?vfunc_5@DXTNHandler@pure3d@@UAEEXZ
// Same code shape as 0x00050220 (propagated; names are from that function)
unsigned char pure3d::DXTNHandler::vfunc_5() {
    return 0;
}


// 0x002af2b0 pure3d::DXTNHandler::vfunc_2 (31 B): matches/0x002af2b0.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_002af2b0@@UAEPAV123@E@Z
namespace fn_002af2b0 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class ImageHandler_2af2b0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* hulk_at_003f6098[];
namespace pure3d {
class NonCopyable : public ImageHandler_2af2b0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = hulk_at_003f6098;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_002af2b0

