// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0027afe0..0x0027b0b0 (kind game, layer engine, confidence high), dominant class pure3d::Entity
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/pure3d.h"
#include "decls/data/game/unknown.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f83389b9 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f83389b9 {} using namespace fn_f83389b9;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace pure3d {
class Entity_27aff0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    char pad[0x100];
};
}
unsigned __int64 FUN_002672f0(void* a, int b, int c);
namespace fn_f83389b9 {
typedef unsigned int U32_27b040;
typedef unsigned __int64 U64_27b040;
U64_27b040 __cdecl MakeThing_002672f0(U32_27b040, U32_27b040, U32_27b040);
extern "C" char DAT_0042c180[];
class Entity {
  public:
    hulk_intptr vptr;
    int a;
    int b;
    int c;
    Entity();
};

} // namespace fn_f83389b9

// 0x0027afe0 pure3d::Entity::vfunc_3 (3 B): matches/0x0027afe0.cpp
// sym: ?vfunc_3@Entity@pure3d@@UAE_NXZ
// Same code shape as 0x00050220 (propagated; names are from that function)
bool pure3d::Entity::vfunc_3() {
    return (bool)(0);
}


// 0x0027aff0 pure3d::Entity::vfunc_4 (3 B): matches/0x0027aff0.cpp
// sym: ?vfunc_4@Entity@pure3d@@UAEPAXXZ
// Same code shape as 0x002a1130 (propagated; names are from that function)
 // namespace pure3d
void* pure3d::Entity::vfunc_4() {
    return (void*)(this);
}

namespace fn_f83389b9 {

// 0x0027b000 FUN_0027b000 (6 B): matches/0x0027b000.cpp
// sym: _FUN_0027b000
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_0027b000() {
    return &(*(int*)&DAT_004ce348);
}


// 0x0027b010 FUN_0027b010 (6 B): matches/0x0027b010.cpp
// sym: _FUN_0027b010
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_0027b010() {
    return &(*(int*)&DAT_004ce358);
}

} // namespace fn_f83389b9

// 0x0027b020 FUN_0027b020 (18 B): matches/0x0027b020.cpp
// sym: _FUN_0027b020
extern "C" unsigned __int64 FUN_0027b020(void* a) {
    return FUN_002672f0(a, 0, 0);
}


// 0x0027b040 FUN_0027b040 (46 B): matches/0x0027b040.cpp
// sym: ?FUN_0027b040@Target_27b040@owners@@QAE_KI@Z
U64_27b040 owners::Target_27b040::FUN_0027b040(hulk_uintptr value) {
    U64_27b040 result;
    if (((U32_27b040)value))
        result = MakeThing_002672f0(((U32_27b040)value), 0, 0);
    else
        result = 0;
    a = (U32_27b040)result;
    b = (U32_27b040)(result >> 32);
    return result;
}

namespace fn_f83389b9 {

// 0x0027b070 FUN_0027b070 (20 B): matches/0x0027b070.cpp
// sym: ??0Entity@fn_f83389b9@@QAE@XZ
Entity::Entity() {
    a = 0;
    vptr = ((hulk_intptr)DAT_0042c180);
    b = 0;
    c = 0;
}

} // namespace fn_f83389b9

// 0x0027b090 pure3d::Entity::vfunc_2 (31 B): matches/0x0027b090.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_0027b090@@UAEPAV123@E@Z
namespace fn_0027b090 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class LoadObject_27b090 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* hulk_at_003f6098[];
namespace pure3d {
class NonCopyable : public LoadObject_27b090 {
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
} // namespace fn_0027b090

