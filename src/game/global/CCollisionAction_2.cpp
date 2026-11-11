// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00019380..0x0001adb0 (kind game, layer game, confidence high), dominant class CCollisionAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/unknown.h"
#include "gen/fight.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f54c57d3 {
#define TREE_TU_END }
namespace fn_f54c57d3 {} using namespace fn_f54c57d3;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f54c57d3 {
extern void* hulk_at_003f3390[];
class Ref_19420 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_19420 {
  public:
    void* vptr;
};
class CCollisionAction_19420 : public CAction_19420 {
  public:
    char pad_1c[0x18];
    Ref_19420* m1c;
    char pad_3c[0x1c];
    Ref_19420* m3c;
    char pad_48[0x8];
    Ref_19420* m48;
    ~CCollisionAction_19420();
};
struct Vec3_19470 {
    float x, y, z;
    hulk_freg FUN_0022d110();
    hulk_freg FUN_000111f0();
};
struct RefObj_19470 {
    virtual void AddRef();
    virtual void Release();
};
struct Mat;
struct CFightParamsCollision_19470 {
    int r00;
    int r04;
    Vec3_19470 target;
    char pad14[4];
    Vec3_19470 aim;
    unsigned char flag24;
    char pad25[0x38 - 0x25];
    Vec3_19470 v38;
    char pad44[4];
    int w48;
    RefObj_19470* ref;
    RefObj_19470* ref50;
    int r54;
    float r58;
    char pad5c[0x68 - 0x5c];
    float r68;
    int r6c;
    int r70;
    int f74;
    int r78;
    float f7c;
    float f80;
    char pad84[0x91 - 0x84];
    unsigned char r91;
    char pad92[0x98 - 0x92];
    Vec3_19470 scratchAnchor;
    Vec3_19470 scratchAttacker;
    CFightParamsCollision_19470* FUN_00059820();
    void FUN_000595f0(Vec3_19470* v, float a, float b, float c);
    void FUN_00059300();
    CFightParamsCollision_19470* FUN_000598e0(RefObj_19470* r, CFightParamsCollision_19470* src);
};
struct Chooser_19470 {
    virtual void c0();
    virtual void c1();
    virtual void c2();
    virtual void c3();
    virtual void c4();
    virtual void c5();
    virtual void c6();
    virtual void c7();
    virtual RefObj_19470* v8(RefObj_19470* r, int z);
};
struct Params {
  public:
    char _m_pad_0[0x30];
    int f30;
    int f34;
    char b38;
    char _m_pad_39[0x2];
    unsigned char b3b;
    char _m_pad_3c[0x8];
    int f44;
    char _m_pad_48[0x4];
    Chooser_19470* f4c;
    char _m_pad_50[0x8];
    Chooser_19470* f58;
    char _m_pad_5c[0xc];
    int f68;
    int f6c;
    char _m_pad_70[0x8];
    char s78[0x20];
    char _m_pad_98[0x40];
    int mode;
    int fdc;
    char _m_pad_e0[0xc];
    int fec;
    unsigned char bf0;
    char _m_pad_f1[0x3];
    float ff4;
    float ff8;
    float ffc;
    float f100;
    float f104;
    unsigned char b108;
    char _m_pad_109[0x3];
    float f10c;
    float f110;
    float f114;
    float f118;
    float f11c;
    void FUN_00012f50(Vec3_19470* out);
    void FUN_00012f80(Vec3_19470* out);
    void FUN_00012fd0(Vec3_19470* out);
};
struct Slot231 {
    void FUN_00231ad0(void* key, RefObj_19470* r, int v);
};
struct Key231 {
    char FUN_00231e80(void* res);
};
struct Gear_19470 {
    char pad00[0x14];
    int f14;
    char pad18[4];
    float f1c;
    char pad20[0x1b0 - 0x20];
    int f1b0;
    __int64 FUN_000443c0();
};
struct Tracker_19470 {
    char pad00[0x34];
    char b34;
    char pad35[0x4c - 0x35];
    RefObj_19470* f4c;
};
struct Holder10_19470 {
    RefObj_19470* first;
};
struct Fighter128_19470 {
    void FUN_001d86d0(Vec3_19470* a, Vec3_19470* b);
};
struct Fighter_19470 {
    char pad00[0x10];
    Holder10_19470* f10;
    char pad14[0xdc - 0x14];
    int fdc;
    char pad_e0[0x11c - 0xe0];
    Gear_19470* f11c;
    char pad120[0x128 - 0x120];
    Fighter128_19470* f128;
    RefObj_19470* f12c;
    char pad130[0x328 - 0x130];
    int f328;
    char pad32c[0x334 - 0x32c];
    Fighter_19470* f334;
    Fighter_19470* f338;
    char pad33c[0x390 - 0x33c];
    Fighter_19470* f390;
    char pad394[0x20b0 - 0x394];
    int f20b0;
    char FUN_0003a590(void* world, Fighter_19470* t);
    char FUN_000373d0();
    char FUN_000360f0();
    char FUN_000437a0(Gear_19470* g, CFightParamsCollision_19470* req, int a, int b, int c);
    char FUN_00043350(int a, RefObj_19470* b, int c, float d, int e, int f);
    void FUN_0003ffa0(RefObj_19470* o, int z);
};
struct Anchor_19470 {
    Fighter_19470* FUN_00059a30();
    void FUN_00059a50(Vec3_19470* out);
};
struct Owner_19470 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Tracker_19470* v3();
    char pad04[4];
    RefObj_19470* f8;
};
struct Fx_19470 {
    void FUN_001eca40(Fighter_19470* a, Fighter_19470* b, const char* s);
};
} // namespace fn_f54c57d3
struct World {
    char pad00[0x34];
    Fx_19470* f34;
};
namespace fn_f54c57d3 {
void* __cdecl FUN_0008d690(unsigned int size);
void __cdecl FUN_00018810(RefObj_19470** slot, RefObj_19470* obj);
void __cdecl FUN_000187a0(void* slot, int v);
void __cdecl FUN_00018840(void* slot, int v);
extern "C" void __cdecl FUN_00096a90(RefObj_19470* obj, Vec3_19470* out);
hulk_freg __cdecl FUN_00224f10(Mat* m);
void __cdecl FUN_00224d70(float angle, Vec3_19470* axis);
extern "C" char __cdecl FUN_000444f0(int v);
float __cdecl FUN_000445a0();
float __cdecl FUN_000445b0();
extern "C" void __cdecl FUN_00014210(int, void *, void *, void *);
class Attack {
  public:
    char pad00[0x1c];
    Owner_19470* owner;
    Params* params;
    char pad24[0x34 - 0x24];
    int f34;
    int f38;
    int pad3c;
    float f40;
    float f44;
    int f48;
    void FUN_00013f20(int a, RefObj_19470* b, int* outA, int* outB);
    void FUN_00019470(Fighter_19470* t, int a2, Vec3_19470* P, Vec3_19470* N, int a5);
};
struct Vec3_19d30 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};
struct RefObj_19d30 {
    virtual void AddRef();
    virtual void Release();
};
struct Request {
    hulk_intptr r00;
    int r04;
    Vec3_19d30 target;
    char pad14[4];
    Vec3_19d30 aim;
    unsigned char flag24;
    char pad25[0x4c - 0x25];
    RefObj_19d30* ref;
    char pad50[4];
    int r54;
    float r58;
    char pad5c[0x68 - 0x5c];
    float r68;
    char pad6c[0x78 - 0x6c];
    float r78;
    char pad7c[0x91 - 0x7c];
    unsigned char r91;
    char pad92[0xa0 - 0x92];
    Request* FUN_00059820();
    void FUN_000595f0(Vec3_19d30* v, float a, float b, float c);
    void FUN_00059300();
};
struct Fighter_19d30 {
    char pad00[0x12c];
    RefObj_19d30* ref12c;
    char pad130[0x328 - 0x130];
    int f328;
    void FUN_0003ffa0(void* obj, int zero);
};
struct Anchor_19d30 {
    Fighter_19d30* FUN_00059a30();
    void FUN_00059a50(Vec3_19d30* out);
};
struct Owner_19d30 {
};
struct Target_19d30 {
    char pad00[0x64];
    float a;
    float b;
    float c;
    char pad70[0x100 - 0x70];
    void* obj;
    void FUN_00081420(Request* req);
};
struct Frame_19d30 {
    Vec3_19d30 delta;
    float fa;
    float fb;
    float fc;
    Vec3_19d30 a;
    Vec3_19d30 b;
    Request req;
    float spill;
    Vec3_19d30 out;
};
class SpawnAction {
public:
    char pad00[0x1c];
    Owner_19d30* owner;
    Params* params;
    void FUN_00019d30(Target_19d30* t, Vec3_19d30* p1, Vec3_19d30* p2);
};
struct Game_1a690 {
    bool Ready_00035ab0();
    void Go_0003b580(int a, int b, int c);
    char pad[0x1b49];
    char f1b49;
    char pad2[0x2fe];
    int f1e48;
};
struct Sess {
    Game_1a690* Get();
};
struct Mid_1a690 {
    Game_1a690* Get_00059a30();
};
struct Tgt_1a690 {
    void Fn_001b4200(void*);
};
struct Ref_1a690 {
    virtual void v0();
    virtual void Release();
};
struct Info_1a690 {
    char pad[0x39];
    char flag;
};
Mid_1a690* __stdcall Conv_001b6580();
struct Owner_1a690 {
    Mid_1a690* Get_000592a0();
};
Sess* Lookup();

} // namespace fn_f54c57d3

// 0x00019380 FUN_00019380 (160 B): equivalent/0x00019380.cpp [wrapped: conflict: CAction; CCollisionAction]
// sym: ??0CCollisionAction@fn_00019380@@QAE@PAURef_19380@1@PAUOwner_19380@1@0H@Z @d9d44db93f4f @wa99106f63c92
namespace fn_00019380 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_00019380 @ 0x00019380
// CCollisionAction::CCollisionAction @ 0x00019380
struct Ref_19380 {
    virtual void AddRef();
    virtual void Release();
};

struct Owner_19380 {
    char pad00[0xe0];
    float x;
    float y;
    float z;
};

struct FUN_00232660 {
    FUN_00232660() throw();
    virtual void v0_00018b30();
    char pad04[0x18];
};

class CAction : public FUN_00232660 {
public:
    Ref_19380 *target;
    Owner_19380 *owner;
    int param;
    char pad28[0x34 - 0x28];
    CAction(Owner_19380 *o, Ref_19380 *t, int p) {
        target = 0;
        if (t)
            t->AddRef();
        if (target)
            target->Release();
        target = t;
        param = p;
        owner = o;
    }
    virtual void v1();
};

class CCollisionAction : public CAction {
public:
    int f34;
    int f38;
    int f3c;
    float y;
    float z;
    Ref_19380 *source;
    CCollisionAction(Ref_19380 *s, Owner_19380 *o, Ref_19380 *t, int p);
    virtual void v1();
};

CCollisionAction::CCollisionAction(Ref_19380 *s, Owner_19380 *o, Ref_19380 *t, int p) : CAction(o, t, p)
{
    f34 = 0;
    f38 = 0;
    f3c = 0;
    source = 0;
    struct { float x, y, z; } pos;
    pos.x = o->x;
    pos.y = o->y;
    pos.z = o->z;
    y = pos.y;
    z = pos.z;
    if (s)
        s->AddRef();
    if (source)
        source->Release();
    source = s;
}
} // namespace fn_00019380

namespace fn_f54c57d3 {

// 0x00019420 FUN_00019420 (80 B): matches/0x00019420.cpp
// sym: ??1CCollisionAction_19420@fn_f54c57d3@@QAE@XZ
CCollisionAction_19420::~CCollisionAction_19420() {
    vptr = gD;
    _ReadWriteBarrier();
    if (m3c) {
        m3c->Release();
        m3c = 0;
    }
    if (m48) {
        m48->Release();
        m48 = 0;
    }
    vptr = hulk_at_003f3390;
    _ReadWriteBarrier();
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    ((fight::Action *)(CAction_19420 *)this)->FUN_002326a0();
}


// 0x00019470 FUN_00019470 (2227 B): equivalent/0x00019470.cpp
// sym: ?FUN_00019470@Attack@fn_f54c57d3@@QAEXPAUFighter_19470@2@HPAUVec3_19470@2@1H@Z @9561f5cfe551 @we43dc2f938be
// STATUS: equivalent (tools/equiv.py level 3: 20078 inputs, branch coverage 99/100, incomplete)
// FUN_00019470 @ 0x00019470
// equiv-conv: FUN_00014210 eax ecx edx esi
void Attack::FUN_00019470(Fighter_19470* t, int a2, Vec3_19470* P, Vec3_19470* N, int a5) {
    if (params->f44 == 1)
        return;

    Anchor_19470* anchor = ((Anchor_19470 *)((owners::Object_592a0 *)owner)->FUN_000592a0());
    Fighter_19470* attacker = anchor->FUN_00059a30();
    World* world = DAT_004dd700;
    if (t == attacker || !t || t->f20b0 || t == attacker->f338 || t == attacker->f334 || t == attacker->f390)
        return;

    Gear_19470* attackerGear = attacker->f11c;
    if (!attacker->FUN_0003a590(world, t))
        return;

    CFightParamsCollision_19470 request;
    request.scratchAnchor.x = 0;
    request.scratchAnchor.y = 0;
    request.scratchAnchor.z = 0;
    anchor->FUN_00059a50(&request.scratchAnchor);
    request.scratchAttacker.x = 0;
    request.scratchAttacker.y = 0;
    request.scratchAttacker.z = 0;
    ((owners::Obj_35230 *)attacker)->FUN_00035230((unsigned *)(Vec3_19470 *)(&request.scratchAttacker));

    Gear_19470* targetGear = t->f11c;
    if (!targetGear)
        return;

    Params* settings = params;
    if ((settings->b38 || settings->b3b) && attackerGear->f1b0 == targetGear->f1b0)
        return;

    int outA = (int)attackerGear;
    if (targetGear->f14) {
        int gearLimit = settings->f34;
        int totalLimit = settings->f30;
        outA = totalLimit;
        __int64 gearId = targetGear->FUN_000443c0();
        if ((unsigned int)gearId != (unsigned int)(*(int*)&DAT_004dc0e0) ||
            (unsigned int)(gearId >> 32) != (unsigned int)(*(int*)((char*)&DAT_004dc0e0 + 4))) {
            if (gearLimit > 0 && f38 >= gearLimit)
                return;
            if (totalLimit > 0 && f34 >= totalLimit)
                return;
        }
        ++f38;
    } else if (settings->f30 > 0 && f34 >= settings->f30) {
        return;
    }

    ++f34;
    float outB;
    FUN_00013f20(a5, t->f12c, &outA, (int*)&outB);

    Tracker_19470* tracker = owner->v3();
    request.FUN_00059820();
    if (tracker && tracker->b34)
        FUN_00018810(&request.ref, tracker->f4c);
    else
        FUN_00018810(&request.ref, attacker->f12c);
    FUN_00018810(&request.ref50, t->f12c);
    FUN_000187a0(&request.r6c, f48);
    FUN_00018840(&request.r70, attacker->fdc);
    settings = params;
    request.f74 = settings->fec ? settings->fec : a2;

    Vec3_19470 hitPosition = *P;
    FUN_00096a90(t->f12c, &hitPosition);
    request.target.x = (P->x + hitPosition.x) * 0.5f;
    request.target.y = (P->y + hitPosition.y) * 0.5f;
    request.target.z = (P->z + hitPosition.z) * 0.5f;

    Vec3_19470 displacement;
    displacement.x = request.target.x - P->x;
    displacement.y = request.target.y - P->y;
    displacement.z = request.target.z - P->z;
    if (displacement.FUN_0022d110() > 1.0f) {
        request.target = *P;
        ((owners::Vec3_11160 *)&(request.target))->FUN_00011160(1.0f, (const owners::Vec3_11160 *)(const Vec3_19470 *)(&displacement));
    }

    request.aim = *N;
    settings = params;
    request.r00 = settings->f68;
    request.r04 = settings->f6c;
    request.r91 = settings->b3b;
    request.r54 = settings->fdc;
    Vec3_19470 outputVector;
    FUN_00014210(settings->mode, (Fighter_19470 *)attacker, t->f12c, (Vec3_19470 *)(&outputVector));

    Params* directionSettings = params;
    Vec3_19470 direction;
    Vec3_19470 alternateDirection;
    Vec3_19470 directionDifference;
    directionSettings->FUN_00012f50(&direction);
    directionSettings->FUN_00012f80(&alternateDirection);
    if (alternateDirection.FUN_000111f0() > 0.0f) {
        float blend = ((owners::ClampOwner_3ebb0 *)attacker)->FUN_0003ebb0(1);
        directionDifference.x = alternateDirection.x - direction.x;
        directionDifference.y = alternateDirection.y - direction.y;
        directionDifference.z = alternateDirection.z - direction.z;
        ((owners::Vec3_11160 *)&direction)->FUN_00011160(blend, (const owners::Vec3_11160 *)(const Vec3_19470 *)(&directionDifference));
    }

    float angle = FUN_00224f10((Mat*)&outputVector);
    FUN_00224d70(angle, &direction);
    request.v38 = direction;
    request.f7c = ((owners::ClampOwner_3ebb0 *)attacker)->FUN_0003ebb0(1);
    request.f80 = outB;

    int gearMode = targetGear->f14;
    float forward;
    float sideways;
    float upward;
    float scale;
    if (FUN_000444f0(gearMode)) {
        directionSettings = params;
        request.flag24 = directionSettings->bf0;
        request.r58 = directionSettings->ff4;
        request.r68 = directionSettings->f104;
        sideways = directionSettings->ffc;
        forward = directionSettings->ff8;
        upward = directionSettings->f100;
        scale = targetGear->f1c;
        scale = FUN_000445a0() / scale;
    } else {
        directionSettings = params;
        if (gearMode == 1) {
            request.flag24 = directionSettings->b108;
            request.r58 = directionSettings->f10c;
            request.r68 = directionSettings->f11c;
            sideways = directionSettings->f114;
            forward = directionSettings->f110;
            upward = directionSettings->f118;
        } else {
            request.flag24 = 0;
            request.r58 = 0;
            request.r68 = 0;
            sideways = 0;
            forward = 0;
            upward = 0;
        }
        scale = targetGear->f1c;
        scale = FUN_000445b0() / scale;
    }

    if (request.r58 < 0.0f)
        request.r58 = -(FUN_000964e0() * request.r58);
    if (request.r68 < 0.0f)
        request.r68 = -(FUN_000964e0() * request.r68);
    request.r78 = outA;
    if (sideways <= 0.0f)
        sideways = request.r58;
    request.FUN_000595f0(&outputVector, scale * forward, scale * sideways, scale * upward);

    if (!t->FUN_000373d0()) {
        Fighter128_19470* targetComponent = t->f128;
        if (targetComponent && direction.FUN_000111f0() > 0.0f)
            targetComponent->FUN_001d86d0(&direction, P);
    }

    bool directHit = t->FUN_000360f0() && (request.r91 == 0 || gearMode == 2 || gearMode == 3);
    if (directHit) {
        t->FUN_00043350(request.r78, request.ref, request.w48, request.f80, 0, *(int*)&request.r91);
    } else {
        Chooser_19470* targetChooser = params->f4c;
        bool found = false;
        if (targetChooser) {
            CFightParamsCollision_19470* allocated = (CFightParamsCollision_19470*)FUN_0008d690((int)sizeof(CFightParamsCollision_19470));
            RefObj_19470* copy =
                allocated ? (RefObj_19470*)allocated->FUN_000598e0(t->f10->first, &request) : 0;
            copy->AddRef();
            RefObj_19470* result = targetChooser->v8(copy, 0);
            if (result)
                ((Slot231*)result)->FUN_00231ad0(&t->fdc, copy, -1);
            copy->Release();
            found = result != 0;
        }
        if (found) {
            world->f34->FUN_001eca40(attacker, t, params->s78);
        } else {
            char hit = t->FUN_000437a0((Gear_19470*)outA, &request, 0, 0, 0);
            const char* sound = params->s78;
            if (sound && *sound)
                world->f34->FUN_001eca40(attacker, t, hit ? sound : "whiff");
        }

        params->FUN_00012fd0(&directionDifference);
        ((owners::State_35b70 *)t)->FUN_00035b70(directionDifference.x, f40, f44);
        f40 = f40 * 0.75f;
        f44 = f44 * 0.75f;
    }

    Chooser_19470* attackerChooser = params->f58;
    if (attackerChooser) {
        CFightParamsCollision_19470* allocated = (CFightParamsCollision_19470*)FUN_0008d690((int)sizeof(CFightParamsCollision_19470));
        RefObj_19470* copy = allocated ? (RefObj_19470*)allocated->FUN_000598e0(owner->f8, &request) : 0;
        copy->AddRef();
        RefObj_19470* result = attackerChooser->v8(copy, 0);
        if (result && !((Key231*)&attacker->fdc)->FUN_00231e80(result))
            ((Slot231*)result)->FUN_00231ad0(&attacker->fdc, copy, -1);
        copy->Release();
    }
    if (attacker->f328 == 0)
        attacker->FUN_0003ffa0(t->f12c, 0);
    ((owners::Queue_35c70 *)attacker)->FUN_00035c70((hulk_intptr)(RefObj_19470 *)(t->f12c));
    request.FUN_00059300();
}


// 0x00019d30 FUN_00019d30 (786 B): equivalent/0x00019d30.cpp
// sym: ?FUN_00019d30@SpawnAction@fn_f54c57d3@@QAEXPAUTarget_19d30@2@PAUVec3_19d30@2@1@Z @578e8915c0c4 @w2569bfd14357
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 16/16)
// FUN_00019d30 @ 0x00019d30
// equiv-conv: FUN_00014210 eax ecx edx esi
void SpawnAction::FUN_00019d30(Target_19d30* t, Vec3_19d30* p1, Vec3_19d30* p2)
{
    Anchor_19d30* anchor = ((Anchor_19d30 *)((owners::Object_592a0 *)owner)->FUN_000592a0());
    Fighter_19d30* fighter = anchor->FUN_00059a30();
    if (t == 0)
        return;
    Frame_19d30 f;
    f.a.x = 0.0f;
    f.a.y = 0.0f;
    f.a.z = 0.0f;
    anchor->FUN_00059a50(&f.a);
    f.b.x = 0.0f;
    f.b.y = 0.0f;
    f.b.z = 0.0f;
    ((owners::Obj_35230 *)fighter)->FUN_00035230((unsigned *)(Vec3_19d30 *)(&f.b));
    f.req.FUN_00059820();

    Vec3_19d30 mid;
    mid.x = p1->x + t->a;
    mid.y = p1->y + t->b;
    mid.z = p1->z + t->c;
    mid.x = mid.x * 0.5f;
    mid.y = mid.y * 0.5f;
    mid.z = mid.z * 0.5f;
    f.req.target = mid;
    f.delta = mid;
    f.delta.x = f.delta.x - p1->x;
    f.delta.y = f.delta.y - p1->y;
    f.delta.z = f.delta.z - p1->z;
    if (f.delta.FUN_0022d110() > 1.0f) {
        f.req.target.x = f.delta.x + p1->x;
        f.req.target.y = f.delta.y + p1->y;
        f.req.target.z = f.delta.z + p1->z;
    }

    f.req.aim = *p2;
    Params* pr = params;
    f.req.r00 = pr->f68;
    f.req.r04 = pr->f6c;
    f.req.r91 = pr->b3b;
    f.req.r54 = pr->fdc;
    RefObj_19d30* nr = fighter->ref12c;
    if (nr)
        nr->AddRef();
    if (f.req.ref)
        f.req.ref->Release();
    pr = params;
    f.req.ref = nr;
    FUN_00014210(pr->mode, (Fighter_19d30 *)fighter, t->obj, (Vec3_19d30 *)(&f.out));
    pr = params;
    f.req.flag24 = pr->bf0;
    f.req.r58 = pr->ff4;
    f.req.r68 = pr->f104;
    f.fa = pr->ffc;
    f.fc = pr->ff8;
    f.fb = pr->f100;
    if (f.req.r58 < 0.0f)
        f.req.r58 = -(FUN_000964e0() * f.req.r58);
    if (f.req.r68 < 0.0f)
        f.req.r68 = -(FUN_000964e0() * f.req.r68);
    f.req.r78 = 1.0f;
    if (f.fa <= 0.0f)
        f.fa = f.req.r58;
    f.req.FUN_000595f0(&f.out, f.fc, f.fa, f.fb);
    t->FUN_00081420(&f.req);
    if (fighter->f328 == 0)
        fighter->FUN_0003ffa0(t->obj, 0);
    ((owners::Queue_35c70 *)fighter)->FUN_00035c70((hulk_intptr)(t->obj));
    f.req.FUN_00059300();
}

} // namespace fn_f54c57d3

// 0x0001a050 FUN_0001a050 (241 B): equivalent/0x0001a050.cpp [wrapped: conflict: World]
// sym: ?FUN_0001a050@Target_1a050@fn_0001a050@@QAEXHH@Z @74acf0a0101e @wba52e802437a
namespace fn_0001a050 {
// STATUS: equivalent (tools/equiv.py level 3: 1441 inputs, branch coverage 22/22)
// FUN_0001a050 @ 0x0001a050
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)

struct Actor_1a050;
struct Link_1a050 { Actor_1a050* FUN_00059a30(); };
struct Owner_1a050 {  };
struct Actor_1a050 {
 char pad0[0x12c]; int kind;
 char pad1[0x334-0x130]; Actor_1a050* related334; Actor_1a050* related338;
 char pad2[0x390-0x33c]; Actor_1a050* related390;
 char pad3[0x20b0-0x394]; int disabled;
 int FUN_00038f90(int,int,int);
};
struct Collection_1a050 { char pad[0xc]; int count; Actor_1a050* FUN_00024190(int); };
struct World { char pad[0x20]; Collection_1a050* collection; };
struct Config_1a050 { char pad[0x2c]; int value; };
struct Target_1a050 {
 char pad[0x1c]; Owner_1a050* owner; Config_1a050* config;
 void FUN_00019470(Actor_1a050*,int,int,int,float);
 bool FUN_00013ed0();
 void FUN_0001a050(hulk_intptr,hulk_intptr);
};
void Target_1a050::FUN_0001a050(hulk_intptr arg,hulk_intptr secondary) {
 Actor_1a050* self = ((Link_1a050 *)((owners::Object_592a0 *)owner)->FUN_000592a0())->FUN_00059a30();
 Collection_1a050* list = DAT_004dd700->collection;
 int count = list->count;
 for(int i=0;i<count;++i) {
  Actor_1a050* other = list->FUN_00024190(i);
  if(other == self || !other || other->disabled || other == self->related338 || other == self->related334 || other == self->related390) continue;
  if(((owners::Thing_35c30 *)self)->FUN_00035c30((hulk_intptr)(other->kind))) continue;
  int value = config->value;
  int result = other->FUN_00038f90(arg,value,0);
  if(result) {
   FUN_00019470(other,result,arg,secondary,1.0f);
   if(FUN_00013ed0()) break;
  }
 }
}
} // namespace fn_0001a050
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x0001a150 CCollisionAction::vfunc_6 (465 B): equivalent/0x0001a150.cpp [wrapped: conflict: CAction; CCollisionAction; World]
// sym: ?vfunc_6@CCollisionAction@fn_0001a150@@UAEDH@Z @94e284c0b74c @w7b16bee16821
namespace fn_0001a150 {
// STATUS: equivalent (tools/equiv.py level 3: 19828 inputs, branch coverage 15/16, incomplete)
// CCollisionAction::vfunc_6 @ 0x0001a150
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)

struct Vec3_1a150 { float x, y, z; };

struct Mat_1a150 {
    float m[16];
    void FUN_0022b980();
    void FUN_0022c2b0(const Vec3_1a150 *in, Vec3_1a150 *out);
};

struct Skeleton {
    char pad0[0x1c];
    Mat_1a150 *matrices;
};

struct Body_1a150 {
    char pad0[0x64];
    Skeleton *skeleton;
};

struct Fighter_1a150 { char pad[4]; };
Fighter_1a150 *__fastcall FUN_000592a0(void *owner);
extern "C" Body_1a150 *__fastcall FUN_00059a40(Fighter_1a150 *f);

class Link_1a150 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};

struct Stats_1a150 {
    char pad0[0x1b49];
    unsigned char hit;           // 0x1b49
    char pad1b4a[0x1d70 - 0x1b4a];
    unsigned int targetLo;       // 0x1d70
    unsigned int targetHi;       // 0x1d74
    bool FUN_00035ab0();
    void FUN_0003b580(int a, float b, float c);
};
extern "C" Stats_1a150 *__fastcall FUN_00059a30(Fighter_1a150 *f);

struct Data_1a150 {
    char pad0[0x20];
    Vec3_1a150 offset;                 // 0x20
    int handle;                  // 0x2c
    char pad30[0x39 - 0x30];
    unsigned char flag39;
    char pad3a[0x58 - 0x3a];
    float f58;                   // 0x58
    char pad5c[0x70 - 0x5c];
    unsigned int idLo;           // 0x70
    unsigned int idHi;           // 0x74
};

struct Flags_1a150 {
    char pad0[0x70];
    unsigned char on;
    char pad71;
    unsigned char off;
};

class CAction;
class Effect_1a150 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6(Mat_1a150 *m, int arg);
    char pad04[4];
    CAction *owner;
    int mode;
    char pad10[0x74 - 0x10];
    Flags_1a150 *flags;
};

struct CollisionSphere_1a150 {
    CollisionSphere_1a150 *FUN_002efe50(Vec3_1a150 *v, int handle);
};

void *__cdecl FUN_0008d690(unsigned int size);
extern "C" Effect_1a150 *__cdecl FUN_002efca0(CollisionSphere_1a150 *init, const char *name);

struct Sys_1a150 {
    char pad0[8];
    void FUN_001b4190(Effect_1a150 *e);
};
Sys_1a150 *__cdecl FUN_001b6580();

struct Actor_1a150 {
    Vec3_1a150 *FUN_001d6b40();
};

struct Table_1a150 {
    Actor_1a150 *FUN_001dee40(unsigned int lo, unsigned int hi);
};

struct World {
    char pad0[0xc];
    Table_1a150 *table;                // 0x0c
};

class CAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual char vfunc_6(int arg);
    virtual void vfunc_7();
    virtual void vfunc_8();
    char pad04[0x18];
    void *ownerObj;              // 0x1c
    Data_1a150 *data;                  // 0x20
    int matrixIndex;             // 0x24
    Vec3_1a150 pos;                    // 0x28
    char pad34[0x3c - 0x34];
    Effect_1a150 *effect;              // 0x3c
};

class CCollisionAction : public CAction {
public:
    virtual char vfunc_6(int arg);
};

char CCollisionAction::vfunc_6(int arg)
{
    Fighter_1a150 *fighter = FUN_000592a0(ownerObj);
    Stats_1a150 *stats = FUN_00059a30(fighter);
    Body_1a150 *body = FUN_00059a40(fighter);
    stats->hit = 1;
    if (data->flag39) {
        if (stats->FUN_00035ab0())
            stats->FUN_0003b580(1, 3.1415927f, data->f58);
    }

    Vec3_1a150 off = data->offset;
    body->skeleton->matrices[matrixIndex].FUN_0022c2b0(&off, &pos);

    if ((data->idLo | data->idHi) != 0) {
        if ((stats->targetLo | stats->targetHi) != 0) {
            Actor_1a150 *a = DAT_004dd700->table->FUN_001dee40(stats->targetLo, stats->targetHi);
            if (a) {
                pos = *a->FUN_001d6b40();
                off = data->offset;
                pos.x = off.x + pos.x;
                pos.y = off.y + pos.y;
                pos.z = off.z + pos.z;
            }
        }
    }

    CollisionSphere_1a150 *init = 0;
    void *mem = FUN_0008d690(0x48);
    if (mem != 0) {
        off.x = 0;
        off.y = 0;
        off.z = 0;
        int handle = data->handle;
        init = ((CollisionSphere_1a150 *)mem)->FUN_002efe50(&off, handle);
    }
    Effect_1a150 *e = FUN_002efca0(init, 0);
    e->mode = 3;
    e->owner = this;
    e->vfunc_0();
    if (effect != 0)
        ((Link_1a150 *)effect)->vfunc_1();
    effect = e;
    Flags_1a150 *fl = e->flags;
    fl->on = 1;
    fl->off = 0;
    Effect_1a150 * arg1_ = effect;
    FUN_001b6580()->FUN_001b4190(arg1_);
    Mat_1a150 t;
    t.FUN_0022b980();
    t.m[12] = pos.x;
    t.m[14] = pos.z;
    t.m[13] = pos.y;
    effect->vfunc_6(&t, 0);
    return 1;
}
} // namespace fn_0001a150
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x0001a330 CCollisionAction::vfunc_8 (850 B): equivalent/0x0001a330.cpp [wrapped: conflict: CCollisionAction; World]
// sym: ?vfunc_8@CCollisionAction@fn_0001a330@@UAE_NM@Z @26a36e6d7c19 @wbf39f603ad70
namespace fn_0001a330 {
// STATUS: equivalent (tools/equiv.py level 3: 3006 inputs, branch coverage 43/46, incomplete)
// CCollisionAction::vfunc_8 @ 0x0001a330
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)

struct V3_1a330 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};

struct Mat4_1a330 {
    float m[16];
    void FUN_0022b980();
    void FUN_0022c2b0(V3_1a330 *in, V3_1a330 *out);
};

struct Id64_1a330 {
    unsigned int lo, hi;
};

struct Obj6_1a330 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(Mat4_1a330 *m, float dt);
};

struct Inner_1a330 {
    char pad0[0x10];
    char flag10;
};

struct Timing_1a330 {
    char pad0[0x11c];
    Inner_1a330 *f11c;
    char pad120[0x1d70 - 0x120];
    Id64_1a330 id1d70;
};

struct Frames_1a330 {
    char pad0[0x1c];
    Mat4_1a330 *f1c;
};

struct SkelData {
    char pad0[0x64];
    Frames_1a330 *f64;
};

struct Cfg_1a330 {
    char pad0[0x20];
    V3_1a330 v20;
    float f2c;
    int f30;
    int f34;
    char pad38[0x44 - 0x38];
    int f44;
    char pad48[0x70 - 0x48];
    Id64_1a330 id70;
};

struct Placed {
    V3_1a330 *FUN_001d6b40();
};

struct WorldSys_1a330 {
    Placed *FUN_001dee40(unsigned int lo, unsigned int hi);
};

struct World {
    char pad0[0xc];
    WorldSys_1a330 *f0c;
};

struct Clock_1a330 {
    Timing_1a330 *FUN_00059a30();
    SkelData *FUN_00059a40();
};

struct Target_1a330 {
    Clock_1a330 *FUN_000592a0();
};

class CCollisionAction {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual bool vfunc_8(float dt);
    char pad04[0x1c - 4];
    Target_1a330 *target;        // 0x1c
    Cfg_1a330 *cfg;              // 0x20
    int f24;
    V3_1a330 pos;                // 0x28
    int f34x;
    int f38x;
    Obj6_1a330 *f3c;

    void FUN_0001a050(V3_1a330 *a, V3_1a330 *b);
    char FUN_00013ed0();
};

struct Frame_1a330 {
    int tmp10;             // 0x10
    float lim;             // 0x14
    float len;             // 0x18
    V3_1a330 hit;                // 0x1c
    V3_1a330 dir;                // 0x28
    V3_1a330 step;               // 0x34
    V3_1a330 acc;                // 0x40
    Mat4_1a330 mat;              // 0x4c
};

bool CCollisionAction::vfunc_8(float dt)
{
    Frame_1a330 f;
    Clock_1a330 *clock = target->FUN_000592a0();
    Timing_1a330 *timing = clock->FUN_00059a30();
    SkelData *skel = clock->FUN_00059a40();
    Mat4_1a330 *xf = &skel->f64->f1c[f24];
    Cfg_1a330 *c = cfg;
    Id64_1a330 *id = &c->id70;
    if (id && (id->lo | id->hi)) {
        unsigned int lo = timing->id1d70.lo;
        unsigned int hi = timing->id1d70.hi;
        if (lo | hi) {
            Placed *p = DAT_004dd700->f0c->FUN_001dee40(lo, hi);
            if (p) {
                V3_1a330 *v = p->FUN_001d6b40();
                f.hit.x = v->x;
                f.hit.y = v->y;
                f.hit.z = v->z;
                V3_1a330 *q = &cfg->v20;
                f.acc.x = q->x;
                f.acc.y = q->y;
                f.acc.z = q->z;
                f.hit.x = f.acc.x + f.hit.x;
                f.hit.y = f.acc.y + f.hit.y;
                f.hit.z = f.acc.z + f.hit.z;
            }
        }
    } else {
        V3_1a330 *q = &c->v20;
        f.acc.x = q->x;
        f.acc.y = q->y;
        f.acc.z = q->z;
        xf->FUN_0022c2b0(&f.acc, &f.hit);
    }

    f.dir.x = f.hit.x - pos.x;
    f.dir.y = f.hit.y - pos.y;
    f.dir.z = f.hit.z - pos.z;
    f.len = f.dir.FUN_0022d110();
    c = cfg;
    f.lim = c->f2c * 2.0f;
    if (c->f44 != 1) {
        float lenv = f.len;
        float a = f.lim;
        if (lenv < a) {
            FUN_0001a050(&f.hit, &f.dir);
        } else {
            f.tmp10 = *(int *)&f.lim & 0x7fffffff;
            if (*(float *)&f.tmp10 <= 1e-5f) {
                FUN_0001a050(&f.hit, &f.dir);
            } else {
                double q = f.len / f.lim;
                int n = (int)q;
                if (q - n > 0.0f)
                    n++;
                if (n > 0x40)
                    n = 0x40;
                double sl = f.len / n;
                f.acc.x = pos.x;
                f.step.x = f.dir.x;
                f.acc.y = pos.y;
                f.step.y = f.dir.y;
                f.acc.z = pos.z;
                f.step.z = f.dir.z;
                f.step.x = f.step.x * sl;
                f.step.y = f.step.y * sl;
                f.step.z = f.step.z * sl;
                for (int i = 0; i < n; i++) {
                    f.acc.x = f.acc.x + f.step.x;
                    f.acc.y = f.acc.y + f.step.y;
                    f.acc.z = f.acc.z + f.step.z;
                    FUN_0001a050(&f.acc, &f.dir);
                    if (FUN_00013ed0())
                        break;
                }
            }
        }
    }

    if (f24 && f3c) {
        f.mat.FUN_0022b980();
        f.mat.m[12] = f.hit.x;
        f.mat.m[13] = f.hit.y;
        f.mat.m[14] = f.hit.z;
        f3c->v6(&f.mat, dt);
    }
    pos.x = f.hit.x;
    pos.y = f.hit.y;
    pos.z = f.hit.z;

    Timing_1a330 *t = target->FUN_000592a0()->FUN_00059a30();
    if (t && t->f11c && t->f11c->flag10)
        return true;
    c = cfg;
    return !(c->f30 > 0 && f34x >= c->f30 && c->f34 > 0 && f38x >= c->f34);
}
} // namespace fn_0001a330
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x0001a690 CCollisionAction::vfunc_4 (119 B): matches/0x0001a690.cpp
// sym: ?vfunc_4@CCollisionAction@@UAEXXZ
void CCollisionAction::vfunc_4() {
    Game_1a690* g = (*(Owner_1a690 * *)&this->f_1c)->Get_000592a0()->Get_00059a30();
    if ((*(Ref_1a690 * *)&this->f_3c)) {
        Ref_1a690* arg = (*(Ref_1a690 * *)&this->f_3c);
        ((Tgt_1a690*)Conv_001b6580())->Fn_001b4200(arg);
        if ((*(Ref_1a690 * *)&this->f_3c)) {
            (*(Ref_1a690 * *)&this->f_3c)->Release();
            (*(Ref_1a690 * *)&this->f_3c) = 0;
        }
    }
    if ((*(Info_1a690 * *)&this->f_20)->flag) {
        if (g->Ready_00035ab0())
            g->Go_0003b580(0, 0, 0);
    }
    g->f1b49 = 0;
    g->f1e48 = 0;
    if ((*(Ref_1a690 * *)&this->f_48)) {
        (*(Ref_1a690 * *)&this->f_48)->Release();
        (*(Ref_1a690 * *)&this->f_48) = 0;
    }
}

