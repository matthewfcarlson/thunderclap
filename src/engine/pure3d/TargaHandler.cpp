// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002af160..0x002af1f0 (kind game, layer engine, confidence high), dominant class pure3d::TargaHandler
#include "tree_prelude.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_fe55a13d {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_fe55a13d {} using namespace fn_fe55a13d;
#include "engine/pure3d.h"

namespace fn_fe55a13d {

// 0x002af160 pure3d::TargaHandler::vfunc_6 (6 B): matches/0x002af160.cpp
// sym: _FUN_002af160
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_002af160() {
    return &(*(int*)&DAT_00400890);
}

} // namespace fn_fe55a13d

// 0x002af170 pure3d::TargaHandler::vfunc_4 (3 B): matches/0x002af170.cpp
// sym: ?vfunc_4@TargaHandler@pure3d@@UAE_NXZ
// Same code shape as 0x0032fce0 (propagated; names are from that function)
bool pure3d::TargaHandler::vfunc_4() {
    return true;
}


// 0x002af180 pure3d::TargaHandler::vfunc_5 (3 B): matches/0x002af180.cpp
// sym: ?vfunc_5@TargaHandler@pure3d@@UAEEXZ
// Same code shape as 0x0032fce0 (propagated; names are from that function)
unsigned char pure3d::TargaHandler::vfunc_5() {
    return (unsigned char)(true);
}


// 0x002af190 pure3d::TargaHandler::vfunc_2 (31 B): matches/0x002af190.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_002af190@@UAEPAV123@E@Z
namespace fn_002af190 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class ImageHandler_2af190 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* refcount_vftable[];
namespace pure3d {
class NonCopyable : public ImageHandler_2af190 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_002af190

