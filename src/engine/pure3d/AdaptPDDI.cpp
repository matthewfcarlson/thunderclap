// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002c31b0..0x002c3230 (kind game, layer engine, confidence high), dominant class pure3d::AdaptPDDI
#include "tree_prelude.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f9b33d3e {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f9b33d3e {} using namespace fn_f9b33d3e;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f9b33d3e {
extern "C" void FUN_002b53e0();
extern "C" void FUN_002a3130();
extern "C" void FUN_0029f7c0();
extern "C" void FUN_002b53f0();
extern "C" void FUN_002a3460();
extern "C" void FUN_0029c3b0();
extern "C" void FUN_0028fcb0(void*);
void Helper_002726e0(int a, int b, int c);


// 0x002c31b0 FUN_002c31b0 (15 B): matches/0x002c31b0.cpp
// sym: _FUN_002c31b0
extern "C" void FUN_002c31b0() {
    FUN_002b53e0();
    FUN_002a3130();
    FUN_0029f7c0();
}


// 0x002c31c0 FUN_002c31c0 (15 B): matches/0x002c31c0.cpp
// sym: _FUN_002c31c0
// Same code shape as 0x002c31b0 (propagated; names are from that function)
extern "C" void FUN_002c31c0() {
    FUN_002b53f0();
    FUN_002a3460();
    FUN_0029c3b0();
}

} // namespace fn_f9b33d3e

// 0x002c31f0 pure3d::AdaptPDDI::vfunc_0 (14 B): matches/0x002c31f0.cpp
// sym: ?vfunc_0@AdaptPDDI@pure3d@@UAEXPAX@Z
// Same code shape as 0x00267220 (propagated; names are from that function)
void pure3d::AdaptPDDI::vfunc_0(void* __p0) { void * p = (void *)__p0;

    FUN_0028fcb0(p);
}


// 0x002c3200 pure3d::AdaptPDDI::vfunc_1 (14 B): matches/0x002c3200.cpp
// sym: ?vfunc_1@AdaptPDDI@pure3d@@UAEXPAX@Z
// Same code shape as 0x00267220 (propagated; names are from that function)
void pure3d::AdaptPDDI::vfunc_1(void* __p0) { void * p = (void *)__p0;

    FUN_0028fcb0(p);
}


// 0x002c3210 pure3d::AdaptPDDI::vfunc_2 (26 B): matches/0x002c3210.cpp
// sym: ?vfunc_2@AdaptPDDI@pure3d@@UAEXHHH@Z
void pure3d::AdaptPDDI::vfunc_2(int a, int b, int c) {
    Helper_002726e0(a, b, c);
}

