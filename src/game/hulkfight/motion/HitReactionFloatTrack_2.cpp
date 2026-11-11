// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0014f2f0..0x0014f570 (kind game, layer game, confidence medium), dominant class hulkfight::motion::HitReactionFloatTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fc396088 {
#define TREE_TU_END }
namespace fn_fc396088 {} using namespace fn_fc396088;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_fc396088 {
struct Vec3_14f2f0 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};
void __cdecl FUN_00224d70(float angle, Vec3_14f2f0 *axis);
struct Marker_14f2f0 {
    char pad0[0x7c];
    float f7c;
};
struct Timing_14f2f0 {
    hulk_freg FUN_000354c0();
};
struct Clock_14f2f0 {
    Timing_14f2f0 *FUN_00059a30();
};
class Owner_14f2f0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Marker_14f2f0 *GetMarker();
};
struct Config_14f2f0 {
    char pad0[0x10];
    int f10;
    float f14;
    float f18;
    float f1c;
    int f20;
    float f24;
    float f28;
    float f2c;
    float f30;
    float f34;
    float f38;
    float f3c;
    float f40;
    float f44;
    float f48;
    float f4c;
    char f50;
};
struct State_14f2f0 {
    float f0;
    float f4;
    char pad8[0x10];
    Vec3_14f2f0 axis;
    char f24;
    char pad25[3];
    float f28;
    char pad2c[4];
    float f30;
    char pad34[0x20];
    int f54;
    float f58;
    char pad5c[0xc];
    float f68;
    char pad6c[8];
    int f74;
    float f78;
    void FUN_00059370(Marker_14f2f0 *m);
    // equiv-conv: FUN_000595f0 ecx stack stack stack stack
    void FUN_000595f0(Vec3_14f2f0 *v, float a, float b, float c);
};
struct Frame_14f2f0 {
    float t;
    float v;
    Vec3_14f2f0 tmp;
};
extern char DAT_00494b44;
extern char DAT_00494b60;
struct Reaction_14f470;
struct Context_14f470;
struct Temporary_14f470 {
 char data[0x98];
 void FUN_00059820();
 void FUN_00059300();
};
struct Controller_14f470 { unsigned char FUN_00231a40(void*, Reaction_14f470*); };
struct Link_14f470 { Controller_14f470* FUN_000392e0(Reaction_14f470*); };
struct Result_14f470 { Link_14f470* FUN_00059a30(); };
struct Reaction_14f470 {
 virtual void slot0();
 virtual void slot1();
 Reaction_14f470* FUN_000598e0(void*, Temporary_14f470*);
};
struct Context_14f470 {
 char padding[8];
 void* owner;
 void FUN_00059760(Controller_14f470*);
};
extern void* __cdecl FUN_00344e74(Context_14f470*, int, void*, void*, int);
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern "C" void __cdecl FUN_0014f2f0(void *, void *, void *);


// 0x0014f2f0 FUN_0014f2f0 (369 B): equivalent/0x0014f2f0.cpp
// sym: _FUN_0014f2f0
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 6/6)
// FUN_0014f2f0 @ 0x0014f2f0
    // equiv-conv: FUN_000595f0 ecx stack stack stack stack
// equiv-conv: FUN_0014f2f0 eax esi edi
extern "C" void FUN_0014f2f0(void *owner, void *cfg, void * st_)
{
    State_14f2f0 * st = (State_14f2f0 *)st_;
    Frame_14f2f0 f;
    f.t = ((Clock_14f2f0 *)((owners::Object_592a0 *)(((Owner_14f2f0 *)owner)))->FUN_000592a0())->FUN_00059a30()->FUN_000354c0();
    Marker_14f2f0 *m = ((Owner_14f2f0 *)owner)->GetMarker();
    f.v = 0.0f;
    if (m != 0 && ((Config_14f2f0 *)cfg)->f50 == 0) {
        st->FUN_00059370(m);
        f.tmp.x = st->f28;
        f.tmp.y = 0;
        f.tmp.z = st->f30;
        f.tmp.FUN_0022d110();
        f.v = m->f7c;
    } else {
        st->f74 = ((Config_14f2f0 *)cfg)->f10;
        st->axis = (*(Vec3_14f2f0*)&DAT_004afa08);
        FUN_00224d70(f.t + ((Config_14f2f0 *)cfg)->f14, &st->axis);
        float t2 = f.t + ((Config_14f2f0 *)cfg)->f24;
        f.tmp = (*(Vec3_14f2f0*)&DAT_004afa08);
        FUN_00224d70(t2, &f.tmp);
    }
    st->f0 = ((Config_14f2f0 *)cfg)->f18;
    st->f4 = ((Config_14f2f0 *)cfg)->f1c;
    st->f54 += ((Config_14f2f0 *)cfg)->f20;
    st->f24 = 1;
    st->f68 = ((Config_14f2f0 *)cfg)->f48 + (((Config_14f2f0 *)cfg)->f4c - ((Config_14f2f0 *)cfg)->f48) * f.v;
    if (((Config_14f2f0 *)cfg)->f28 >= (*(float*)&DAT_003f32e0))
        st->f78 = ((Config_14f2f0 *)cfg)->f28 + (((Config_14f2f0 *)cfg)->f2c - ((Config_14f2f0 *)cfg)->f28) * f.v;
    float r1 = ((Config_14f2f0 *)cfg)->f38 + (((Config_14f2f0 *)cfg)->f3c - ((Config_14f2f0 *)cfg)->f38) * f.v;
    st->f58 = r1;
    float r2 = ((Config_14f2f0 *)cfg)->f40 + (((Config_14f2f0 *)cfg)->f44 - ((Config_14f2f0 *)cfg)->f40) * f.v;
    float r3 = ((Config_14f2f0 *)cfg)->f30 + (((Config_14f2f0 *)cfg)->f34 - ((Config_14f2f0 *)cfg)->f30) * f.v;
    st->FUN_000595f0(&f.tmp, r3, r1, r2);
}

} // namespace fn_fc396088

// 0x0014f470 hulkfight::motion::HitReactionFloatTrack::vfunc_9 (246 B): equivalent/0x0014f470.cpp
// sym: ?vfunc_9@HitReactionFloatTrack@motion@hulkfight@@UAEHHHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 3008 inputs, branch coverage 8/8)
// hulkfight::motion::HitReactionFloatTrack::vfunc_9 @ 0x0014f470
// hulkfight::motion::HitReactionFloatTrack::vfunc_9 @ 0x0014f470
// equiv-conv: FUN_0014f2f0 eax esi edi
int hulkfight::motion::HitReactionFloatTrack::vfunc_9(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { void * unused = (void *)__p0; void * argument = (void *)__p1; Context_14f470 * context = (Context_14f470 *)__p2;

 if (!FUN_00344e74(context, 0, &DAT_00494b44, &DAT_00494b60, 0)) return 1;
 Temporary_14f470 temporary;
 temporary.FUN_00059820();
 FUN_0014f2f0((Context_14f470 *)context, (void*)this, (Temporary_14f470 *)(&temporary));
 Reaction_14f470* allocation = (Reaction_14f470*)FUN_0008d690(0xb0);
 Reaction_14f470* reaction = allocation ? allocation->FUN_000598e0(context->owner, &temporary) : 0;
 reaction->slot0();
 Result_14f470* result = ((Result_14f470 *)((owners::Object_592a0 *)context)->FUN_000592a0());
 Link_14f470* link = result->FUN_00059a30();
 Controller_14f470* controller = link->FUN_000392e0(reaction);
 context->FUN_00059760(controller);
 if (!controller) {
 reaction->slot1();
 temporary.FUN_00059300();
 return 1;
 }
 unsigned char success = controller->FUN_00231a40(argument, reaction);
 reaction->slot1();
 temporary.FUN_00059300();
 return success == 0;
}

