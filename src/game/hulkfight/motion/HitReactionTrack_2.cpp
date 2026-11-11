// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0014efd0..0x0014f210 (kind game, layer game, confidence medium), dominant class hulkfight::motion::HitReactionTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f0a316da {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f0a316da {} using namespace fn_f0a316da;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f0a316da {
struct Vec3_14efd0 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};
void __cdecl FUN_00224d70(float angle, Vec3_14efd0 *axis);
struct Marker;
struct Timing_14efd0 {
    hulk_freg FUN_000354c0();
};
struct Clock_14efd0 {
    Timing_14efd0 *FUN_00059a30();
};
class Owner_14efd0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Marker *GetMarker();
};
struct Config_14efd0 {
    char pad0[0x10];
    int f10;
    float f14;
    float f18;
    float f1c;
    float f20;
    int f24;
    char f28;
    char pad29[3];
    float f2c;
    float f30;
    float f34;
    float f38;
    float f3c;
    float f40;
    char f44;
};
struct State_14efd0 {
    float f0;
    float f4;
    char pad8[0x10];
    Vec3_14efd0 axis;
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
    void FUN_00059370(Marker *m);
    // equiv-conv: FUN_000595f0 ecx stack stack stack stack
    void FUN_000595f0(Vec3_14efd0 *v, float a, float b, float c);
};
struct Frame_14efd0 {
    float t;
    Vec3_14efd0 tmp;
};
extern char DAT_00494b44;
extern char DAT_00494b60;
extern void* __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern "C" void* __cdecl FUN_0008d690(unsigned int);
struct CFightParamsCollision_14f110;
struct Settings_14f110 { char data[0x98]; void FUN_00059820(); void FUN_00059300(); };
struct Controller_14f110 { unsigned char FUN_00231a40(void*, CFightParamsCollision_14f110*); };
struct Handle_14f110 { Controller_14f110* FUN_000392e0(CFightParamsCollision_14f110*); };
struct Link_14f110 { Handle_14f110* FUN_00059a30(); };
struct Owner_14f110 { char pad[8]; void* field8; Link_14f110* FUN_000592a0(); void FUN_00059760(Controller_14f110*); };
struct CFightParamsCollision_14f110 { virtual void vfunc_0(); virtual void vfunc_1(); CFightParamsCollision_14f110* FUN_000598e0(void*, Settings_14f110*); };
namespace hulkfight { namespace motion {
struct HitReactionTrack {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual int vfunc_9(void*, void*, Owner_14f110*);
};
} }
extern "C" void __cdecl FUN_0014efd0(void *, void *, void *);


// 0x0014efd0 FUN_0014efd0 (310 B): equivalent/0x0014efd0.cpp
// sym: _FUN_0014efd0 @d130aa5a7d49 @wf9d7647f7af9
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 8/8)
// FUN_0014efd0 @ 0x0014efd0
    // equiv-conv: FUN_000595f0 ecx stack stack stack stack
// equiv-conv: FUN_0014efd0 ebx esi edi
extern "C" void FUN_0014efd0(void *owner, void *cfg, void * st_)
{
    State_14efd0 * st = (State_14efd0 *)st_;
    Frame_14efd0 f;
    f.t = ((Clock_14efd0 *)((owners::Object_592a0 *)(((Owner_14efd0 *)owner)))->FUN_000592a0())->FUN_00059a30()->FUN_000354c0();
    Marker *m = ((Owner_14efd0 *)owner)->GetMarker();
    if (m != 0 && ((Config_14efd0 *)cfg)->f44 == 0) {
        st->FUN_00059370(m);
        f.tmp.x = st->f28;
        f.tmp.y = 0;
        f.tmp.z = st->f30;
        f.tmp.FUN_0022d110();
    } else {
        st->f74 = ((Config_14efd0 *)cfg)->f10;
        st->axis = (*(Vec3_14efd0*)&DAT_004afa08);
        FUN_00224d70(f.t + ((Config_14efd0 *)cfg)->f14, &st->axis);
        float t2 = f.t + ((Config_14efd0 *)cfg)->f30;
        f.tmp = (*(Vec3_14efd0*)&DAT_004afa08);
        FUN_00224d70(t2, &f.tmp);
    }
    st->f0 = ((Config_14efd0 *)cfg)->f18;
    st->f4 = ((Config_14efd0 *)cfg)->f1c;
    st->f54 += ((Config_14efd0 *)cfg)->f24;
    st->f24 = ((Config_14efd0 *)cfg)->f28;
    st->f58 = ((Config_14efd0 *)cfg)->f2c;
    st->f68 = ((Config_14efd0 *)cfg)->f40;
    if (((Config_14efd0 *)cfg)->f20 >= (*(float*)&DAT_003f32e0))
        st->f78 = ((Config_14efd0 *)cfg)->f20;
    float u = ((Config_14efd0 *)cfg)->f38;
    if (u <= (*(float*)&DAT_003f32e0))
        u = ((Config_14efd0 *)cfg)->f2c;
    st->FUN_000595f0(&f.tmp, ((Config_14efd0 *)cfg)->f34, u, ((Config_14efd0 *)cfg)->f3c);
}


// 0x0014f110 hulkfight::motion::HitReactionTrack::vfunc_9 (244 B): equivalent/0x0014f110.cpp
// sym: ?vfunc_9@HitReactionTrack@motion@hulkfight@fn_f0a316da@@UAEHPAX0PAUOwner_14f110@4@@Z @e9abec1c1327 @wcf6994b0eba5
// STATUS: equivalent (tools/equiv.py level 3: 3008 inputs, branch coverage 8/8)
// hulkfight::motion::HitReactionTrack::vfunc_9 @ 0x0014f110
// hulkfight::motion::HitReactionTrack::vfunc_9 @ 0x0014f110
// equiv-conv: FUN_0014efd0 ebx esi edi
int hulkfight::motion::HitReactionTrack::vfunc_9(void* unused, void* argument, Owner_14f110* owner) {
 if (!FUN_00344e74(owner,0,&DAT_00494b44,&DAT_00494b60,0)) return 1;
 Settings_14f110 settings;
 settings.FUN_00059820();
 FUN_0014efd0((Owner_14f110 *)owner,(hulkfight :: motion :: HitReactionTrack *)this,(Settings_14f110 *)(&settings));
 CFightParamsCollision_14f110* reaction = (CFightParamsCollision_14f110*)FUN_0008d690(0xb0);
 if (reaction) reaction = reaction->FUN_000598e0(owner->field8,&settings);
 reaction->vfunc_0();
 Controller_14f110* controller = owner->FUN_000592a0()->FUN_00059a30()->FUN_000392e0(reaction);
 owner->FUN_00059760(controller);
 if (!controller) { reaction->vfunc_1(); settings.FUN_00059300(); return 1; }
 unsigned char result = controller->FUN_00231a40(argument,reaction);
 reaction->vfunc_1();
 settings.FUN_00059300();
 return result == 0;
}

} // namespace fn_f0a316da
