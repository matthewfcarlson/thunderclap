// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00291c40..0x00291d20 (kind game, layer engine, confidence high), dominant class pure3d::PNGHandler
#include "tree_prelude.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_ffab76e9 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_ffab76e9 {} using namespace fn_ffab76e9;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_ffab76e9 {
class ImageHandler_291c70 {
  public:
    ImageHandler_291c70();
    virtual void F();
};
class BMPHandler : public ImageHandler_291c70 {
  public:
    BMPHandler();
    virtual void F();
};


// 0x00291c40 pure3d::PNGHandler::vfunc_6 (6 B): matches/0x00291c40.cpp
// sym: _FUN_00291c40
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_00291c40() {
    return &(*(int*)&DAT_00400898);
}

} // namespace fn_ffab76e9

// 0x00291c50 pure3d::PNGHandler::vfunc_4 (3 B): matches/0x00291c50.cpp
// sym: ?vfunc_4@PNGHandler@pure3d@@UAE_NXZ
// Same code shape as 0x0032fce0 (propagated; names are from that function)
bool pure3d::PNGHandler::vfunc_4() {
    return true;
}


// 0x00291c60 pure3d::PNGHandler::vfunc_5 (3 B): matches/0x00291c60.cpp
// sym: ?vfunc_5@PNGHandler@pure3d@@UAEEXZ
// Same code shape as 0x00050220 (propagated; names are from that function)
unsigned char pure3d::PNGHandler::vfunc_5() {
    return 0;
}

namespace fn_ffab76e9 {

// 0x00291c70 FUN_00291c70 (18 B): matches/0x00291c70.cpp
// sym: ??0BMPHandler@fn_ffab76e9@@QAE@XZ
BMPHandler::BMPHandler() {}


// 0x00291c90 pure3d::BMPHandler::vfunc_6 (6 B): matches/0x00291c90.cpp
// sym: _FUN_00291c90
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_00291c90() {
    return &(*(int*)&DAT_00400894);
}

} // namespace fn_ffab76e9

// 0x00291ca0 pure3d::BMPHandler::vfunc_4 (3 B): matches/0x00291ca0.cpp
// sym: ?vfunc_4@BMPHandler@pure3d@@UAE_NXZ
// Same code shape as 0x0032fce0 (propagated; names are from that function)
bool pure3d::BMPHandler::vfunc_4() {
    return true;
}


// 0x00291cb0 pure3d::BMPHandler::vfunc_5 (3 B): matches/0x00291cb0.cpp
// sym: ?vfunc_5@BMPHandler@pure3d@@UAEEXZ
// Same code shape as 0x00050220 (propagated; names are from that function)
unsigned char pure3d::BMPHandler::vfunc_5() {
    return 0;
}


// 0x00291cc0 pure3d::PNGHandler::vfunc_2 (31 B): matches/0x00291cc0.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_00291cc0@@UAEPAV123@E@Z
namespace fn_00291cc0 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class ImageHandler_291cc0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* refcount_vftable[];
namespace pure3d {
class NonCopyable : public ImageHandler_291cc0 {
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
} // namespace fn_00291cc0


// 0x00291ce0 pure3d::BMPHandler::vfunc_2 (31 B): matches/0x00291ce0.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_00291ce0@@UAEPAV123@E@Z
namespace fn_00291ce0 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class ImageHandler_291ce0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* refcount_vftable[];
namespace pure3d {
class NonCopyable : public ImageHandler_291ce0 {
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
} // namespace fn_00291ce0

