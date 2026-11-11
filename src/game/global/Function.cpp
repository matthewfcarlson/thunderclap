// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001d0480..0x001d0620 (kind game, layer game, confidence medium), dominant class Function
#include "tree_prelude.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/script.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_ff17ecef {
#define TREE_TU_END }
namespace fn_ff17ecef {} using namespace fn_ff17ecef;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_ff17ecef {
extern void* IRefCount_vftable_1d04a0;
struct TypeInfo_1d04d0 {
    int FUN_00344913(const TypeInfo_1d04d0 *other) const;
};
extern TypeInfo_1d04d0 DAT_0048e10c;

} // namespace fn_ff17ecef

// 0x001d0480 FUN_001d0480 (32 B): matches/0x001d0480.cpp [wrapped: conflict: Function]
// sym: ??0Function@fn_001d0480@@QAE@PBDH@Z
namespace fn_001d0480 {
// Function's constructor (include/decls/data/script.h ScriptFunctionFields): the name and the argument count.
class Function : public ScriptFunctionFields {
  public:
    virtual void f();
    Function(const char* n, int count);
};
Function::Function(const char* n, int count) {
    name = n;
    argc = count;
    key = 0;
}
} // namespace fn_001d0480

namespace fn_ff17ecef {

// 0x001d04a0 FUN_001d04a0 (7 B): matches/0x001d04a0.cpp
// sym: ?FUN_001d04a0@fn_ff17ecef@@YIXPAX@Z
// Same code shape as 0x001b6820 (propagated; names are from that function)
void __fastcall FUN_001d04a0(void* self) {
    *(void**)self = &IRefCount_vftable_1d04a0;
}

} // namespace fn_ff17ecef

// 0x001d04b0 FUN_001d04b0 (10 B): matches/0x001d04b0.cpp
// sym: ?FUN_001d04b0@CAgent_1d04b0@owners@@QAEXH@Z
// Same code shape as 0x000fc4b0 (propagated; names are from that function)
// Function's key (include/decls/data/script.h ScriptFunctionFields.key; owners::CAgent_1d04b0.field).
void owners::CAgent_1d04b0::FUN_001d04b0(hulk_intptr value) {
    field = value;
}


// 0x001d04c0 Function::vfunc_1 (5 B): matches/0x001d04c0.cpp
// sym: ?vfunc_1@Function@@UAE_NHH@Z
// Same code shape as 0x000d7a40 (propagated; names are from that function)
bool Function::vfunc_1(int , int ) {
    return false;
}


// 0x001d04d0 FUN_001d04d0 (199 B): equivalent/0x001d04d0.cpp
// sym: _FUN_001d04d0
// STATUS: equivalent (tools/equiv.py level 3: 118 inputs, branch coverage 18/18)
// FUN_001d04d0 @ 0x001d04d0
extern "C" char FUN_001d04d0(const TypeInfo_1d04d0 *t)
{
    if (t->FUN_00344913(((TypeInfo_1d04d0*)&DAT_0048e100)))
        return 'v';
    if (t->FUN_00344913(((TypeInfo_1d04d0*)&DAT_0048e0e4)))
        return 'b';
    if (t->FUN_00344913(((TypeInfo_1d04d0*)&DAT_0049cad8)) || t->FUN_00344913(((TypeInfo_1d04d0*)&DAT_0048e0f0)))
        return 's';
    if (t->FUN_00344913(((TypeInfo_1d04d0*)&DAT_0048e134)) || t->FUN_00344913(((TypeInfo_1d04d0*)&DAT_0049b95c)))
        return 'i';
    if (t->FUN_00344913(((TypeInfo_1d04d0*)&DAT_0048e128)))
        return 'f';
    if (t->FUN_00344913(&DAT_0048e10c))
        return 'V';
    if (t->FUN_00344913(((TypeInfo_1d04d0*)&DAT_004c5cbc)))
        return 1;
    if (t->FUN_00344913(((TypeInfo_1d04d0*)&DAT_004c5ca0)))
        return 1;
    return 'c';
}


// 0x001d05a0 Function::vfunc_0 (31 B): matches/0x001d05a0.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_001d05a0@@UAEPAV123@E@Z
namespace fn_001d05a0 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class IRefCount {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* refcount_vftable[];
namespace pure3d {
class NonCopyable : public IRefCount {
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
} // namespace fn_001d05a0

