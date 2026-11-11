// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00291d20..0x00291dc0 (kind game, layer engine, confidence medium), dominant class pure3d::IgnoreLoader
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_ff304548 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_ff304548 {} using namespace fn_ff304548;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_ff304548 {
struct Arg_291d60 {
    bool more_002669f0();
    void skip_00266a30();
    void finish_00266be0();
};

} // namespace fn_ff304548

// 0x00291d20 content::P3DFileHandler::vfunc_2 (31 B): matches/0x00291d20.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_00291d20@@UAEPAV123@E@Z
namespace fn_00291d20 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class FileLoader_291d20 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* hulk_at_003f6098[];
namespace pure3d {
class NonCopyable : public FileLoader_291d20 {
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
} // namespace fn_00291d20


// 0x00291d60 pure3d::IgnoreLoader::vfunc_5 (56 B): matches/0x00291d60.cpp
// sym: ?vfunc_5@IgnoreLoader@pure3d@@UAEXPAX00H@Z
void pure3d::IgnoreLoader::vfunc_5(void* __p0, void* __p1, void* __p2, hulk_intptr __p3) { Arg_291d60 * arg = (Arg_291d60 *)__p2;

    while (arg->more_002669f0()) {
        arg->skip_00266a30();
        arg->finish_00266be0();
    }
    this->f_0c = 0;
}


// 0x00291da0 pure3d::IgnoreLoader::vfunc_2 (31 B): matches/0x00291da0.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_00291da0@@UAEPAV123@E@Z
namespace fn_00291da0 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class SimpleChunkHandler_291da0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* refcount_vftable[];
namespace pure3d {
class NonCopyable : public SimpleChunkHandler_291da0 {
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
} // namespace fn_00291da0

