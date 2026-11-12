// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0023b540..0x0023b830 (kind game, layer engine, confidence medium), dominant class fight::Chunk
#include "tree_prelude.h"
#include "compat/ptr.h"
#define TREE_TU_BEGIN namespace fn_f9ad35a3 {
#define TREE_TU_END }
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f9ad35a3 {} using namespace fn_f9ad35a3;
namespace fn_f9ad35a3 { extern "C" char DAT_004286dc[]; }   // (x64t7) the game vftables the TU's placeholder names stood for (verify_relocs)
#include "engine/fight.h"

// ---- declarations shared by the functions below
namespace fn_f9ad35a3 {
class Chunk {
  public:
    char pad[0x28];
    int field;
    void Init_0023c640(int);
};
extern int hulk_at_004286dc;
extern void* Bank_23b7e0_vftable[];
class Bank_23b7e0 {
  public:
    void Destroy_0023c660(); // FUN_00236d60, __thiscall, this in ecx
};
class Chunk_23b7e0 : public Bank_23b7e0 {
  public:
    Chunk_23b7e0* vfunc_5(signed char flags);
};


// 0x0023b540 FUN_0023b540 (27 B): matches/0x0023b540.cpp
// sym: ?Build@fn_f9ad35a3@@YIPAVChunk@1@PAV21@@Z
Chunk* __fastcall Build(Chunk* self) {
    self->Init_0023c640(3);
    *(hulk_intptr*)self = (hulk_intptr)&hulk_at_004286dc;
    self->field = 0;
    return self;
}


// 0x0023b7e0 fight::Chunk::vfunc_2 (36 B): matches/0x0023b7e0.cpp
// sym: ?vfunc_5@Chunk_23b7e0@fn_f9ad35a3@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
Chunk_23b7e0* Chunk_23b7e0::vfunc_5(signed char flags) {
    *(void***)this = ((void**)DAT_004286dc);
    Destroy_0023c660();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

} // namespace fn_f9ad35a3
