// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0010b2a0..0x0010c0d0 (kind game, layer game, confidence high), dominant class hulkfight::ai::FaceTargetAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/ai.h"
#include "gen/fight.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f8ed28bc {
#define TREE_TU_END }
namespace fn_f8ed28bc {} using namespace fn_f8ed28bc;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_f8ed28bc {
extern int* hulk_at_004e0ad0;
class CCondition_10b430 {
  public:
    virtual int vfunc_0(int);
};
class Track_10b440 {
  public:
    Track_10b440();
    virtual void f();
};
class FaceTargetTrack : public Track_10b440 {
  public:
    FaceTargetTrack();
    char pad[4];
    int flag;
    int value;
    float angle;
};
struct Param_10b480 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_10b480 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
extern int* hulk_at_004e0ad8;
class CCondition_10b4c0 {
  public:
    virtual int vfunc_0(int);
};
class Track_10b4d0 {
  public:
    Track_10b4d0();
    virtual void f();
};
class FaceMotionTrack : public Track_10b4d0 {
  public:
    FaceMotionTrack();
    char pad[4];
    int a;
    int b;
    float c;
};
struct Param_10b510 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_10b510 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
class Obj {
  public:
    char pad[0x1b78];
    int a;
    int b;
    int c;
    void Get(int* out);
};
struct V3 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};
struct Pos {
    void FUN_00059a50(V3 *out);
};
struct Ctl {
    unsigned __int64 FUN_000443c0();
    char pad0[0x1b0];
    int f1b0;               // 0x1b0
    char pad1b4[0x478 - 0x1b4];
    float thr2;             // 0x478
    float thr1;             // 0x47c
};
struct Sub {
    char pad0[0x24];
    int f24;                // 0x24
    char pad28[0x54 - 0x28];
    int f54;                // 0x54
    char pad58[0x6c - 0x58];
    int f6c;                // 0x6c
    char pad70[0x78 - 0x70];
    int f78;                // 0x78
    char pad7c[0x11c - 0x7c];
    V3 dir;                 // 0x11c
    char pad128[0x150 - 0x128];
};
struct Tgt {
    char pad0[0x40];
    V3 pos;                 // 0x40
};
struct Player {
    char pad0[0x10];
    Pos *pos;               // 0x10
    char pad14[0x11c - 0x14];
    Ctl *ctl;               // 0x11c
    char pad120[0x328 - 0x120];
    Tgt *tgt;               // 0x328
    char pad32c[0x1b78 - 0x32c];
    V3 aim;                 // 0x1b78
    char pad1b84[0x1f58 - 0x1b84];
    Sub sub;                // 0x1f58
    int f20a8;              // 0x20a8
    hulk_freg FUN_00035700();
    void FUN_00035550(V3 *out);
};
struct Me {
    char pad0[0x11c];
    Ctl *ctl;               // 0x11c
    char pad120[0x12c - 0x120];
    Tgt *tgt;               // 0x12c
};
struct Owner {
    Player *FUN_00059a30();
};
struct Link {
};
struct Hold {
    char pad0[0x124];
    Me *me;                 // 0x124
};
} // namespace fn_f8ed28bc
struct World {
    char pad0[0x20];
    Hold *hold;             // 0x20
};
namespace fn_f8ed28bc {
extern hulk_freg __cdecl FUN_00224ea0(float a, float b);
struct MotionState {
    char pad[0x2064];
    volatile unsigned int positionX, positionY, positionZ;
    char gap[4];
    volatile unsigned int previousX, previousY, previousZ;
};
struct MotionOwner { MotionState* FUN_00059a30(); };
struct MotionSource {  };
extern void* hulk_at_0040d824[];
class Track_10b920 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
class FaceTargetTrack_10b920 : public Track_10b920 {
  public:
    FaceTargetTrack_10b920* vfunc_5(signed char flags);
};
extern void* hulk_at_0040d854[];
class Track_10b950 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
class FaceMotionTrack_10b950 : public Track_10b950 {
  public:
    FaceMotionTrack_10b950* vfunc_5(signed char flags);
};
class RefObj_10b980 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_10b980 {
  public:
    Action_10b980();
    virtual void Update();
    char pad[0x18];
};
class RefObj_10ba10 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_10ba10 {
  public:
    Action_10ba10();
    virtual void Update();
    char pad[0x18];
};
class FaceMotionAction_10ba10 : public Action_10ba10 {
  public:
    int mTarget;
    RefObj_10ba10* mObj;
    FaceMotionAction_10ba10(int target, RefObj_10ba10* obj);
    virtual void Execute();
};
class Ref_10ba60 {
  public:
    virtual void A();
    virtual void B();
};
extern int hulk_at_0040d8a0;
class FaceMotionAction {
  public:
    hulk_intptr vptr;
    char pad[0x18];
    int* p;
    Ref_10ba60* r;
    void Run();
};
class CStageCondition_10bae0;
class ParamValue_10bae0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_10bae0 : public ParamValue_10bae0 {
  public:
    int pad;
};
class CStageCondition_10bb30;
class ParamValue_10bb30 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_10bb30 : public ParamValue_10bb30 {
  public:
    int pad;
};
} // namespace fn_f8ed28bc
namespace fight {
class TrackFactoryCaster_10bb50 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace ai {
class FaceTargetTrack_10bb50 {};
} }
namespace fn_f8ed28bc {
extern "C" void* FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_004a2128;
class Params_10bd40 {
  public:
    int x;
};
extern Params_10bd40 hulk_at_00494b44;
extern Params_10bd40 hulk_at_00494b60;
int __cdecl Check(void*, int, Params_10bd40*, Params_10bd40*, int);
class Object_10bd40 {
  public:
    int Init_0010b980(hulkfight::ai::FaceTargetTrack*, hulk_intptr);
};
Object_10bd40* __cdecl Alloc_0008d690(int);
struct RefCounted_10bd90 {
  public:
    virtual void f0();
    virtual void Release();
};
class FaceTargetAction : public Action_10b980 {
  public:
    virtual void _m_vf1();
    virtual void _m_vf2();
    virtual void _m_vf3();
    virtual void _m_vf4();
    virtual bool vfunc_5(int a, int b);
    FaceTargetAction(int target, RefObj_10b980* obj);
    union { int mTarget; int m_1c; };
    union { Link *link; RefObj_10b980* mObj; RefCounted_10bd90* m_20; };
    FaceTargetAction* vfunc_2(int flag);
};
extern char hulk_at_0040d884[];
struct RefCounted_10be30 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char g_vt_10be30[];
class FaceMotionAction_10be30 {
  public:
    FaceMotionAction_10be30* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_10be30* m_20;
};
class TrackFactoryCaster_10bf20 {
  public:
    virtual void f();
};
class TargetCaster : public TrackFactoryCaster_10bf20 {};
class TrackFactoryCasterTemplate_10bf20 : public TrackFactoryCaster_10bf20 {};
extern "C" int __cdecl FUN_00236ac0(const char*, TrackFactoryCaster_10bf20*);
class Factory {
  public:
    void add_002367c0(int);
};
} // namespace fn_f8ed28bc
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f8ed28bc {
class TrackFactoryTemplate_10bf70 {
  public:
    TrackFactoryTemplate_10bf70() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
class FaceTargetTrack_10bfb0 {
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    int pad;
    int m8;
    int mc;
    float m10;
    FaceTargetTrack_10bfb0();
};
extern void* __cdecl Allocate_0008d690(unsigned int);
extern int FaceVtable;
extern int hulk_at_0040d92c;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_0010b410();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};
class TrackFactoryTemplate_10c020 {
  public:
    TrackFactoryTemplate_10c020() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" char DAT_0040d854[];
extern "C" void* __cdecl alloc(hulk_uintptr);
class Face {
  public:
    Face();
    hulk_intptr vf;
    int pad4;
    int m8;
    int mc;
    float m10;
};


// 0x0010b2a0 FUN_0010b2a0 (6 B): matches/0x0010b2a0.cpp
// sym: ?FUN_0010b2a0@fn_f8ed28bc@@YAHXZ
int FUN_0010b2a0() {
    return 1;
}

// 0x0010b2b0 thunk_FUN_000964e0 (5 B): not yet verified
} // namespace fn_f8ed28bc

// 0x0010b2c0 FUN_0010b2c0 (194 B): matches/0x0010b2c0.cpp [wrapped: conflict: FUN_0010b2a0; operatornew]
// sym: ?Build@This_10b2c0@fn_0010b2c0@@QAEPAV12@XZ
void* operator new(size_t) HULK_NEW_THROW;
namespace fn_0010b2c0 {
// cl-flags: /O2


extern "C++" __declspec(nothrow) void __cdecl FUN_0010b2a0();
extern "C" void __cdecl FUN_0010b2b0();
class List_10b2c0;

class ColorHolder {
  public:
};

struct Context_10b2c0 {
    char pad0[8];
    ColorHolder ch;
    char pad1[0x60 - 8 - 1];
    Context_10b2c0() throw();
};

class List_10b2c0 {
  public:
    void Add_00232a80(Context_10b2c0* it);
};

class This_10b2c0 {
  public:
    List_10b2c0* GetList_00232780();
    This_10b2c0* Build();
};




extern "C" void __cdecl FUN_00238b60(hulk_intptr a, int b);
extern "C" void __cdecl FUN_00238330(hulk_intptr a, int b);

This_10b2c0* This_10b2c0::Build() {
    List_10b2c0* list = GetList_00232780();
    Context_10b2c0* a = new Context_10b2c0();
    ((owners::Target_27b040 *)&(a->ch))->FUN_0027b040((hulk_uintptr)(((float**)&DAT_004a1f60)[0]));
    list->Add_00232a80(a);
    Context_10b2c0* b = new Context_10b2c0();
    ((owners::Target_27b040 *)&(b->ch))->FUN_0027b040((hulk_uintptr)(((float**)&DAT_004a1f60)[1]));
    list->Add_00232a80(b);
    Context_10b2c0* c = new Context_10b2c0();
    ((owners::Target_27b040 *)&(c->ch))->FUN_0027b040((hulk_uintptr)(((float**)&DAT_004a1f60)[2]));
    list->Add_00232a80(c);
    FUN_00238b60(((hulk_intptr)(void (__cdecl*)())&FUN_0010b2a0), 0);
    FUN_00238330(((hulk_intptr)(void (__cdecl*)())&FUN_0010b2b0), 0);
    return this;
}
} // namespace fn_0010b2c0


// 0x0010b3d0 FUN_0010b3d0 (12 B): matches/0x0010b3d0.cpp
// sym: ?FUN_0010b3d0@Obj_10b3d0@owners@@QAE_NH@Z
bool owners::Obj_10b3d0::FUN_0010b3d0(int v) {
    value = v;
    return true;
}


// 0x0010b3e0 FUN_0010b3e0 (12 B): matches/0x0010b3e0.cpp
// sym: ?FUN_0010b3e0@A_10b3e0@owners@@QAEDH@Z
char owners::A_10b3e0::FUN_0010b3e0(int x) {
    *((int*)m + 4) = x;
    return 1;
}


// 0x0010b3f0 FUN_0010b3f0 (12 B): matches/0x0010b3f0.cpp
// sym: ?FUN_0010b3f0@X_10b3f0@owners@@QAE_NH@Z
bool owners::X_10b3f0::FUN_0010b3f0(int v) {
    m = v;
    return true;
}


// 0x0010b400 FUN_0010b400 (12 B): matches/0x0010b400.cpp
// sym: ?FUN_0010b400@Obj_10b400@owners@@QAEDH@Z
char owners::Obj_10b400::FUN_0010b400(int value) {
    m10 = value;
    return 1;
}

namespace fn_f8ed28bc {

// 0x0010b410 FUN_0010b410 (19 B): matches/0x0010b410.cpp
// sym: ?FUN_0010b410@fn_f8ed28bc@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0010b410() {
    FUN_00234810(((char*)&DAT_004e0ad0), ((char*)&DAT_004e0ad4));
}

} // namespace fn_f8ed28bc

// 0x0010b430 hulkfight::ai::FaceTargetTrack::vfunc_0 (16 B): matches/0x0010b430.cpp
// sym: ?vfunc_0@FaceTargetTrack@ai@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::ai::FaceTargetTrack::vfunc_0(int index) {
    int* p = hulk_at_004e0ad0;
    return p[index];
}

namespace fn_f8ed28bc {

// 0x0010b440 FUN_0010b440 (39 B): matches/0x0010b440.cpp
// sym: ??0FaceTargetTrack@fn_f8ed28bc@@QAE@XZ
FaceTargetTrack::FaceTargetTrack() : Track_10b440() {
    value = 0;
    angle = -1.0f;
    flag = 1;
}

} // namespace fn_f8ed28bc

// 0x0010b470 hulkfight::ai::FaceTargetTrack::vfunc_6 (4 B): matches/0x0010b470.cpp
// sym: ?vfunc_6@FaceTargetTrack@ai@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::ai::FaceTargetTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0010b480 hulkfight::ai::FaceTargetTrack::vfunc_7 (7 B): matches/0x0010b480.cpp
// sym: ?vfunc_7@FaceTargetTrack@ai@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::ai::FaceTargetTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

namespace fn_f8ed28bc {

// 0x0010b4a0 FUN_0010b4a0 (19 B): matches/0x0010b4a0.cpp
// sym: ?FUN_0010b4a0@fn_f8ed28bc@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0010b4a0() {
    FUN_00234810(((char*)&DAT_004e0ad8), ((char*)&DAT_004e0adc));
}

} // namespace fn_f8ed28bc

// 0x0010b4c0 hulkfight::ai::FaceMotionTrack::vfunc_0 (16 B): matches/0x0010b4c0.cpp
// sym: ?vfunc_0@FaceMotionTrack@ai@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::ai::FaceMotionTrack::vfunc_0(int index) {
    int* p = hulk_at_004e0ad8;
    return p[index];
}

namespace fn_f8ed28bc {

// 0x0010b4d0 FUN_0010b4d0 (39 B): matches/0x0010b4d0.cpp
// sym: ??0FaceMotionTrack@fn_f8ed28bc@@QAE@XZ
FaceMotionTrack::FaceMotionTrack() : Track_10b4d0() {
    b = 0;
    c = -1.0f;
    a = 1;
}

} // namespace fn_f8ed28bc

// 0x0010b500 hulkfight::ai::FaceMotionTrack::vfunc_6 (4 B): matches/0x0010b500.cpp
// sym: ?vfunc_6@FaceMotionTrack@ai@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::ai::FaceMotionTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0010b510 hulkfight::ai::FaceMotionTrack::vfunc_7 (7 B): matches/0x0010b510.cpp
// sym: ?vfunc_7@FaceMotionTrack@ai@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::ai::FaceMotionTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

namespace fn_f8ed28bc {

// 0x0010b550 FUN_0010b550 (33 B): matches/0x0010b550.cpp
// sym: ?Get@Obj@fn_f8ed28bc@@QAEXPAH@Z
void Obj::Get(int* out) {
    out[0] = a;
    out[1] = b;
    out[2] = c;
}

} // namespace fn_f8ed28bc

// 0x0010b580 FUN_0010b580 (33 B): matches/0x0010b580.cpp
// sym: ?FUN_0010b580@C_10b580@owners@@QAEXPBI@Z
void owners::C_10b580::FUN_0010b580(const unsigned int* p) {
    *(unsigned int*)(pad + 0x1b78) = p[0];
    *(unsigned int*)(pad + 0x1b7c) = p[1];
    *(unsigned int*)(pad + 0x1b80) = p[2];
}

namespace fn_f8ed28bc {

// 0x0010b5b0 hulkfight::ai::FaceTargetAction::vfunc_5 (730 B): equivalent/0x0010b5b0.cpp
// sym: ?vfunc_5@FaceTargetAction@fn_f8ed28bc@@UAE_NHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 20013 inputs, branch coverage 39/43, incomplete)
// hulkfight::ai::FaceTargetAction::vfunc_5 @ 0x0010b5b0
bool FaceTargetAction::vfunc_5(int a, int b)
{
    if (a != 0)
        return true;
    if (link == 0)
        return false;
    Player *p = ((Owner *)((owners::Object_592a0 *)link)->FUN_000592a0())->FUN_00059a30();
    if (p == 0)
        return false;
    bool ok = p->ctl->FUN_000443c0() == (*(unsigned __int64*)&DAT_004dc0c8);
    Tgt *t = p->tgt;
    if (t == 0) {
        if (p->f20a8 >= 0)
            return false;
        Ctl *pc = p->ctl;
        if (pc == 0)
            return false;
        Me *me = DAT_004dd700->hold->me;
        if (me == 0)
            return false;
        Tgt *mt = me->tgt;
        if (mt == 0)
            return false;
        Ctl *mc = me->ctl;
        if (mc == 0)
            return false;
        if (pc->f1b0 == mc->f1b0)
            return false;
        t = mt;
    }
    struct Frame {
        V3 u;                   // esp+0xc
        V3 d;                   // esp+0x18
        union {                 // esp+0x24: one slot, three lives
            V3 tp;              //   the target position
            V3 aim;             //   a copy of p->aim
            V3 vf;              //   FUN_00035550's out-vector
        } t;
        V3 w;                   // esp+0x30
    } f;
    f.t.tp = t->pos;
    f.u.x = 0.0f; f.u.y = 0.0f; f.u.z = 0.0f;
    p->pos->FUN_00059a50(&f.u);
    f.d.x = f.t.tp.x - f.u.x;
    f.d.y = f.t.tp.y - f.u.y;
    f.d.z = f.t.tp.z - f.u.z;
    f.d.FUN_0022d110();
    Sub *sub = &p->sub;
    float F = p->FUN_00035700();
    // The original copies p->aim with x and y on the FPU stack and z through the dead tp slot.
    float ax = p->aim.x, ay = p->aim.y;
    f.t.aim.z = p->aim.z;
    f.w.x = ax - f.u.x;
    f.w.y = ay - f.u.y;
    f.w.z = f.t.aim.z - f.u.z;
    bool far = f.w.FUN_0022d110() > 1.0f;
    if (ok && sub != 0 && F == 0.0f && far) {
        float a1 = FUN_00224ea0(f.d.x, f.d.z);
        p->FUN_00035550(&f.t.vf);
        Ctl *pc;
        double dd = a1 * 57.2957764f - FUN_00224ea0(f.t.vf.x, f.t.vf.z) * 57.2957764f;
        pc = p->ctl;
        float delta = (float)dd;
        double ad = fabs(dd);
        if (ad > pc->thr1 && ad < pc->thr1 + 50.0f) {
            sub->f54 = 1;
            sub->f24 = 1;
            ((owners::C_10b580 *)p)->FUN_0010b580((const unsigned int *)(V3 *)(&f.u));
        } else if (ad > pc->thr2 && ad < pc->thr2 + 50.0f) {
            sub->f24 = 1;
            if (delta < 0.0f)
                sub->f6c = 1;
            else
                sub->f78 = 1;
            ((owners::C_10b580 *)p)->FUN_0010b580((const unsigned int *)(V3 *)(&f.u));
        }
    }
    sub->dir = f.d;
    return true;
}

} // namespace fn_f8ed28bc

// 0x0010b890 hulkfight::ai::FaceMotionAction::vfunc_5 (78 B): equivalent/0x0010b890.cpp
// sym: ?vfunc_5@FaceMotionAction@ai@hulkfight@@UAE_NHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 19972 inputs, branch coverage 4/4)
// hulkfight::ai::FaceMotionAction::vfunc_5 @ 0x0010b890
bool hulkfight::ai::FaceMotionAction::vfunc_5(hulk_intptr mode, int unused) {
    if (mode) return (bool)((mode & ~255) | 1);
    if (!(*(MotionSource * *)&this->f_20)) return (bool)(0);
    MotionOwner* owner = ((MotionOwner *)((owners::Object_592a0 *)((*(MotionSource * *)&this->f_20)))->FUN_000592a0());
    MotionState* state = owner->FUN_00059a30();
    state->previousX = state->positionX;
    state->previousY = state->positionY;
    state->previousZ = state->positionZ;
    return (bool)((((hulk_uintptr)state + 0x1f58) & ~255U) | 1);
}

namespace fn_f8ed28bc {

// 0x0010b900 FUN_0010b900 (11 B): matches/0x0010b900.cpp
// sym: ?Set@fn_f8ed28bc@@YAXPAXH@Z
void Set(void* p, int v) {
    *(int*)p = v;
}


// 0x0010b910 FUN_0010b910 (16 B): matches/0x0010b910.cpp
// sym: ?FUN_0010b910@fn_f8ed28bc@@YAXPAPAH@Z
void __cdecl FUN_0010b910(int** p) {
    if (*p) {
        *p = 0;
    }
}


// 0x0010b920 hulkfight::ai::FaceTargetTrack::vfunc_5 (36 B): matches/0x0010b920.cpp
// sym: ?vfunc_5@FaceTargetTrack_10b920@fn_f8ed28bc@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
FaceTargetTrack_10b920* FaceTargetTrack_10b920::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0040d824;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x0010b950 hulkfight::ai::FaceMotionTrack::vfunc_5 (36 B): matches/0x0010b950.cpp
// sym: ?vfunc_5@FaceMotionTrack_10b950@fn_f8ed28bc@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
FaceMotionTrack_10b950* FaceMotionTrack_10b950::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0040d854;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x0010b980 FUN_0010b980 (72 B): matches/0x0010b980.cpp
// sym: ??0FaceTargetAction@fn_f8ed28bc@@QAE@HPAVRefObj_10b980@1@@Z
FaceTargetAction::FaceTargetAction(int target, RefObj_10b980* obj) {
    int* p = &mTarget;
    *p = 0;
    mObj = 0;
    mTarget = target;
    if (obj) {
        obj->AddRef();
    }
    if (mObj) {
        mObj->Release();
    }
    mObj = obj;
}

} // namespace fn_f8ed28bc

// 0x0010b9d0 FUN_0010b9d0 (50 B): matches/0x0010b9d0.cpp [wrapped: conflict: FaceTargetAction]
// sym: ?Cleanup@FaceTargetAction@fn_0010b9d0@@QAEXXZ
namespace fn_0010b9d0 {
extern "C" char DAT_0040d884[];
extern "C" void _ReadWriteBarrier();
struct Ref_10b9d0 {
    virtual void f0();
    virtual void Release();
};
void __fastcall BaseDestroy_002326a0(void*);
struct FaceTargetAction {
    hulk_intptr vptr;
    char pad[0x18];
    int field1c;
    Ref_10b9d0* field20;
    void Cleanup();
};
void FaceTargetAction::Cleanup() {
    vptr = ((hulk_intptr)DAT_0040d884);
    _ReadWriteBarrier();
    Ref_10b9d0* r = field20;
    if (r) {
        r->Release();
        field20 = 0;
    }
    if (field1c)
        field1c = 0;
    BaseDestroy_002326a0(this);
}
} // namespace fn_0010b9d0

namespace fn_f8ed28bc {

// 0x0010ba10 FUN_0010ba10 (72 B): matches/0x0010ba10.cpp
// sym: ??0FaceMotionAction_10ba10@fn_f8ed28bc@@QAE@HPAVRefObj_10ba10@1@@Z
// Same code shape as 0x0010b980 (propagated; names are from that function)
FaceMotionAction_10ba10::FaceMotionAction_10ba10(int target, RefObj_10ba10* obj) {
    int* p = &mTarget;
    *p = 0;
    mObj = 0;
    mTarget = target;
    if (obj) {
        obj->AddRef();
    }
    if (mObj) {
        mObj->Release();
    }
    mObj = obj;
}


// 0x0010ba60 FUN_0010ba60 (50 B): matches/0x0010ba60.cpp
// sym: ?Run@FaceMotionAction@fn_f8ed28bc@@QAEXXZ
void FaceMotionAction::Run() {
    vptr = (hulk_intptr)&hulk_at_0040d8a0;
    _ReadWriteBarrier();
    if (r) {
        r->B();
        r = 0;
    }
    if (p)
        p = 0;
    ((fight::Action *)this)->FUN_002326a0();
}

} // namespace fn_f8ed28bc

// 0x0010bac0 fight::ParamFloatConstRange<hulkfight::ai::FaceTargetTrack>::vfunc_6 (26 B): matches/0x0010bac0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VFaceTargetTrack@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::FaceTargetTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::ai::FaceTargetTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::ai::FaceTargetTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::ai::FaceTargetTrack>::**)(int))&this->f_10))(b);
}


// 0x0010bae0 fight::ParamFloatConstRange<hulkfight::ai::FaceTargetTrack>::vfunc_2 (11 B): matches/0x0010bae0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VFaceTargetTrack@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::FaceTargetTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0010bb10 fight::ParamFloatConstRange<hulkfight::ai::FaceMotionTrack>::vfunc_6 (26 B): matches/0x0010bb10.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VFaceTargetTrack@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::FaceMotionTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::ai::FaceMotionTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::ai::FaceMotionTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::ai::FaceMotionTrack>::**)(int))&this->f_10))(b);
}


// 0x0010bb30 fight::ParamFloatConstRange<hulkfight::ai::FaceMotionTrack>::vfunc_2 (11 B): matches/0x0010bb30.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VFaceTargetTrack@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::FaceMotionTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0010bb50 fight::TrackFactoryCasterTemplate<hulkfight::ai::FaceTargetTrack>::vfunc_0 (36 B): matches/0x0010bb50.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VFaceTargetTrack@ai@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::ai::FaceTargetTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004a2128, 0) != 0;
}


// 0x0010bb80 fight::ParamFloatConstRange<hulkfight::ai::FaceTargetTrack>::vfunc_0 (30 B): matches/0x0010bb80.cpp
// sym: ??_G?$ParamFloatConstRange@VFaceTargetTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::ai::FaceTargetTrack>::~ParamFloatConstRange() {}


// 0x0010bbb0 fight::TrackFactoryCasterTemplate<hulkfight::ai::FaceMotionTrack>::vfunc_0 (36 B): matches/0x0010bbb0.cpp [wrapped: conflict: fight::TrackFactoryCaster; fight::TrackFactoryCasterTemplate]
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VFaceMotionTrack@ai@hulkfight@fn_0010bbb0@@@fight@fn_0010bbb0@@UAEHPAX@Z
namespace fn_0010bbb0 {
extern char DAT_0049850c;
extern char DAT_004a21d0;
extern "C++" __declspec(nothrow) int __cdecl FUN_00344e74(void*, int, const void*, const void*, int);
namespace fight {
class TrackFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
template <class T> class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace ai {
class FaceMotionTrack;
}
} // namespace hulkfight
template <> int fight::TrackFactoryCasterTemplate<hulkfight::ai::FaceMotionTrack>::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004a21d0, 0) != 0;
}
} // namespace fn_0010bbb0


// 0x0010bbe0 fight::ParamFloatConstRange<hulkfight::ai::FaceMotionTrack>::vfunc_0 (30 B): matches/0x0010bbe0.cpp
// sym: ??_G?$ParamFloatConstRange@VFaceMotionTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::ai::FaceMotionTrack>::~ParamFloatConstRange() {}


// 0x0010bd40 hulkfight::ai::FaceTargetTrack::vfunc_10 (70 B): matches/0x0010bd40.cpp
// sym: ?vfunc_10@FaceTargetTrack@ai@hulkfight@@UAEHHHH@Z
hulk_intptr hulkfight::ai::FaceTargetTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = Check((void*)c, 0, &hulk_at_00494b44, &hulk_at_00494b60, 0);
    if (result) {
        Object_10bd40* p = Alloc_0008d690(0x24);
        if (p)
            return p->Init_0010b980(this, c);
    }
    return 0;
}

namespace fn_f8ed28bc {

// 0x0010bd90 hulkfight::ai::FaceTargetAction::vfunc_2 (71 B): matches/0x0010bd90.cpp
// sym: ?vfunc_2@FaceTargetAction@fn_f8ed28bc@@QAEPAV12@H@Z
FaceTargetAction* FaceTargetAction::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&hulk_at_0040d884;
    RefCounted_10bd90* q = *(RefCounted_10bd90* volatile*)&m_20;
    if (q != 0) {
        q->Release();
        m_20 = 0;
    }
    if (m_1c != 0) {
        m_1c = 0;
    }
    ((fight::Action *)this)->FUN_002326a0();
    if (flag & 1) {
        opdel(this);
    }
    return this;
}


// 0x0010be30 hulkfight::ai::FaceMotionAction::vfunc_2 (71 B): matches/0x0010be30.cpp
// sym: ?vfunc_2@FaceMotionAction_10be30@fn_f8ed28bc@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
FaceMotionAction_10be30* FaceMotionAction_10be30::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&g_vt_10be30;
    RefCounted_10be30* q = *(RefCounted_10be30* volatile*)&m_20;
    if (q != 0) {
        q->Release();
        m_20 = 0;
    }
    if (m_1c != 0) {
        m_1c = 0;
    }
    ((fight::Action *)this)->FUN_002326a0();
    if (flag & 1) {
        opdel(this);
    }
    return this;
}


// 0x0010bf20 FUN_0010bf20 (77 B): matches/0x0010bf20.cpp
// sym: _FUN_0010bf20
extern "C" void FUN_0010bf20(Factory* p) {
    {
        TargetCaster a;
        p->add_002367c0(FUN_00236ac0("faceTarget", &a));
    }
    {
        TrackFactoryCasterTemplate_10bf20 b;
        p->add_002367c0(FUN_00236ac0("faceMotion", &b));
    }
}

} // namespace fn_f8ed28bc

// 0x0010bf70 fight::TrackFactoryCasterTemplate<hulkfight::ai::FaceTargetTrack>::vfunc_1 (60 B): matches/0x0010bf70.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VFaceTargetTrack@ai@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::ai::FaceTargetTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_10bf70));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_10bf70* t = new (mem) TrackFactoryTemplate_10bf70();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0010bfb0 fight::TrackFactoryTemplate<hulkfight::ai::FaceTargetTrack>::vfunc_5 (59 B): matches/0x0010bfb0.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VFaceTargetTrack@ai@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<hulkfight::ai::FaceTargetTrack>::vfunc_5() {
    FaceTargetTrack_10bfb0* p = (FaceTargetTrack_10bfb0*)Allocate_0008d690(0x14);
    if (p) {
        p->FaceTargetTrack_10bfb0::FaceTargetTrack_10bfb0();
        *(hulk_intptr*)p = (hulk_intptr)&FaceVtable;
        p->mc = 0;
        p->m10 = -1.0f;
        p->m8 = 1;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f8ed28bc {

// 0x0010bff0 fight::TrackFactoryTemplate<hulkfight::ai::FaceTargetTrack>::vfunc_2 (43 B): matches/0x0010bff0.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f8ed28bc@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0040d92c;
    base1_dtor_0010b410();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f8ed28bc

// 0x0010c020 fight::TrackFactoryCasterTemplate<hulkfight::ai::FaceMotionTrack>::vfunc_1 (60 B): matches/0x0010c020.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VFaceMotionTrack@ai@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::ai::FaceMotionTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_10c020));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_10c020* t = new (mem) TrackFactoryTemplate_10c020();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0010c060 fight::TrackFactoryTemplate<hulkfight::ai::FaceMotionTrack>::vfunc_5 (59 B): matches/0x0010c060.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VFaceMotionTrack@ai@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<hulkfight::ai::FaceMotionTrack>::vfunc_5() {
    Face* p = (Face*)alloc(0x14);
    if (p) {
        p->Face::Face();
        p->vf = ((hulk_intptr)DAT_0040d854);
        p->mc = 0;
        p->m10 = -1.0f;
        p->m8 = 1;
        return (void*)(p);
    }
    return (void*)(0);
}


// 0x0010c0a0 fight::TrackFactoryTemplate<hulkfight::ai::FaceMotionTrack>::vfunc_2 (43 B): matches/0x0010c0a0.cpp [wrapped: same definition as 0x0010bff0 in this TU]
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_0010c0a0@@QAEPAXE@Z
namespace fn_0010c0a0 {
// Same code shape as 0x0006fb50 (propagated; names are from that function)
extern int hulk_at_0040d948;

struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_0010b4a0();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

void thunk_delete_00263f30(void*);

void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0040d948;
    base1_dtor_0010b4a0();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}
} // namespace fn_0010c0a0

