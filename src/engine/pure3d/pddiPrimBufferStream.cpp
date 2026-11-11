// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00326dc0..0x00326e90 (kind game, layer engine, confidence medium), dominant class pure3d::pddiPrimBufferStream
#include "tree_prelude.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f72aabec {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f72aabec {} using namespace fn_f72aabec;
#include "engine/pure3d.h"

namespace fn_f72aabec {

// 0x00326dc0 FUN_00326dc0 (49 B): equivalent/0x00326dc0.cpp
// sym: _FUN_00326dc0
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 7/7)
// FUN_00326dc0 @ 0x00326dc0
// equiv-conv: FUN_00326dc0 eax ecx
extern "C" int FUN_00326dc0(unsigned int mode, int value)
{
    switch (mode) {
    case 0: return value / 3;
    case 1: return value - 2;
    case 2: return value / 2;
    case 3: return value - 1;
    case 4: return value;
    default: return 0;
    }
}

} // namespace fn_f72aabec

// 0x00326e70 pure3d::pddiPrimBufferStream::vfunc_2 (3 B): matches/0x00326e70.cpp
// sym: ?vfunc_2@pddiPrimBufferStream@pure3d@@UAEXKKK@Z
// Same code shape as 0x00098430 (propagated; names are from that function)
void pure3d::pddiPrimBufferStream::vfunc_2(unsigned long __p0, unsigned long __p1, unsigned long __p2) {}


// 0x00326e80 pure3d::pddiPrimBufferStream::vfunc_3 (3 B): matches/0x00326e80.cpp
// sym: ?vfunc_3@pddiPrimBufferStream@pure3d@@UAEXIII@Z
// Same code shape as 0x00098430 (propagated; names are from that function)
void pure3d::pddiPrimBufferStream::vfunc_3(unsigned int __p0, unsigned int __p1, unsigned int __p2) {}

