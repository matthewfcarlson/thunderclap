// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002a5060..0x002a5150 (kind game, layer engine, confidence medium), dominant class pure3d::DrawablePrimitive
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/drawable_container.h"
#define TREE_TU_BEGIN namespace fn_fdccf8a8 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fdccf8a8 {} using namespace fn_fdccf8a8;
namespace fn_fdccf8a8 {
void __cdecl SweepTrack_DeleteThis_00263f30(void* p);   // (unb4) the thunk to free (or free) this TU's SweepTrack_DeleteThis reaches
}
namespace fn_fdccf8a8 { extern "C" char DAT_0042d978[]; }   // (x64t7) the game vftables the TU's placeholder names stood for (verify_relocs)
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_fdccf8a8 {
// (x64t18) pure3d::Entity's words and pure3d::DrawablePrimitive's (0x40 bytes on the 32-bit builds), non-polymorphic:
// the constructors are the game's, Entity's 0x0027b070 called by its address name (the local stand-in base's
// constructor had no definition natively), and store the game's vftables by address
struct Entity_2a5060 {
    void* vftable;
    int b[3];
    Entity_2a5060* FUN_0027b070();   // pure3d::Entity's constructor
};
struct DrawablePrimitive : HulkDrawablePrimitive {   // (x64t20, D105) the record: its word pointer-sized natively
    DrawablePrimitive* FUN_002a5060();
};
extern int hulk_at_0042d978;
class Obj_2a50b0 {
    char pad[0x10];

  public:
    unsigned int value;
};
extern void* Entity_2a5120_vftable[];
class Entity_2a5120 {
  public:
    void Destroy_0027afd0(); // FUN_00236d60, __thiscall, this in ecx
};
class DrawablePrimitive_2a5120 : public Entity_2a5120 {
  public:
    DrawablePrimitive_2a5120* vfunc_5(signed char flags);
};


// 0x002a5060 FUN_002a5060 (53 B): matches/0x002a5060.cpp
// sym: ?FUN_002a5060@DrawablePrimitive@fn_fdccf8a8@@QAEPAU12@XZ
DrawablePrimitive* DrawablePrimitive::FUN_002a5060() {
    ((Entity_2a5060*)this)->FUN_0027b070();
    word = 0;
    *((hulk_intptr*)this) = (hulk_intptr)&hulk_at_0042d978;
    _ReadWriteBarrier();
    ((int*)box)[0] = 0;
    ((int*)box)[1] = 0;
    ((int*)box)[2] = 0;
    ((int*)box)[3] = 0;
    ((int*)box)[4] = 0;
    ((int*)box)[5] = 0;
    ((int*)sphere)[0] = 0;
    ((int*)sphere)[1] = 0;
    ((int*)sphere)[2] = 0;
    ((int*)sphere)[3] = 0;
    return this;
}


// 0x002a50a0 FUN_002a50a0 (11 B): matches/0x002a50a0.cpp
// sym: @FUN_002a50a0@4
// Same code shape as 0x00060920 (propagated; names are from that function)
extern "C" void __fastcall FUN_002a50a0(CEffectStopTrack* self) {
    *(hulk_intptr*)self = (hulk_intptr)((int*)DAT_0042d978);
    FUN_0027afd0(self);
}


// 0x002a50b0 FUN_002a50b0 (4 B): matches/0x002a50b0.cpp
// sym: ?FUN_002a50b0@fn_fdccf8a8@@YIIPAVObj_2a50b0@1@@Z
// Same code shape as 0x00059a30 (propagated; names are from that function)
unsigned int __fastcall FUN_002a50b0(Obj_2a50b0* self) {
    return self->value;
}


// 0x002a5120 pure3d::DrawablePrimitive::vfunc_2 (36 B): matches/0x002a5120.cpp
// sym: ?vfunc_5@DrawablePrimitive_2a5120@fn_fdccf8a8@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
DrawablePrimitive_2a5120* DrawablePrimitive_2a5120::vfunc_5(signed char flags) {
    *(void***)this = ((void**)DAT_0042d978);
    Destroy_0027afd0();
    if (flags & 1) {
        SweepTrack_DeleteThis_00263f30(this);
    }
    return this;
}

} // namespace fn_fdccf8a8
