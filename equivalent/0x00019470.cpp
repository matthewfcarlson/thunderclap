// STATUS: equivalent (tools/equiv.py level 3: 3096 inputs, branch coverage 99/100, incomplete)
// FUN_00019470 @ 0x00019470
#include "decls/address.h"
#include "decls/data/game/unknown.h"

struct Vec3_19470 {
    float x, y, z;
    float FUN_0022d110();
    float FUN_000111f0();
    void FUN_00011160(float s, const Vec3_19470* d);
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
    char pad00[0x30];
    int f30;
    int f34;
    char b38;
    char pad39[2];
    unsigned char b3b;
    char pad3c[0x44 - 0x3c];
    int f44;
    char pad48[0x4c - 0x48];
    Chooser_19470* f4c;
    char pad50[0x58 - 0x50];
    Chooser_19470* f58;
    char pad5c[0x68 - 0x5c];
    int f68;
    int f6c;
    char pad70[0x78 - 0x70];
    char s78[0x20];
    char pad98[0xd8 - 0x98];
    int mode;
    int fdc;
    char pade0[0xec - 0xe0];
    int fec;
    unsigned char bf0;
    char padf1[3];
    float ff4;
    float ff8;
    float ffc;
    float f100;
    float f104;
    unsigned char b108;
    char pad109[3];
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
    void FUN_00035230(Vec3_19470* out);
    char FUN_0003a590(void* world, Fighter_19470* t);
    float FUN_0003ebb0(int a);
    char FUN_000373d0();
    char FUN_000360f0();
    char FUN_000437a0(Gear_19470* g, CFightParamsCollision_19470* req, int a, int b, int c);
    char FUN_00043350(int a, RefObj_19470* b, int c, float d, int e, int f);
    void FUN_00035b70(float x, float a, float b);
    void FUN_0003ffa0(RefObj_19470* o, int z);
    void FUN_00035c70(RefObj_19470* o);
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
    Anchor_19470* FUN_000592a0();
};

struct Fx_19470 {
    void FUN_001eca40(Fighter_19470* a, Fighter_19470* b, const char* s);
};

struct World {
    char pad00[0x34];
    Fx_19470* f34;
};

void* __cdecl FUN_0008d690(unsigned int size);
void __cdecl FUN_00018810(RefObj_19470** slot, RefObj_19470* obj);
void __cdecl FUN_000187a0(void* slot, int v);
void __cdecl FUN_00018840(void* slot, int v);
void __cdecl FUN_00096a90(RefObj_19470* obj, Vec3_19470* out);
float __cdecl FUN_00224f10(Mat* m);
void __cdecl FUN_00224d70(float angle, Vec3_19470* axis);
char __cdecl FUN_000444f0(int v);
float __cdecl FUN_000445a0();
float __cdecl FUN_000445b0();
float __cdecl FUN_000964e0();
// equiv-conv: FUN_00014210 eax ecx edx esi
void FUN_00014210(int mode, Fighter_19470* frame, void* obj, Vec3_19470* out);

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

void Attack::FUN_00019470(Fighter_19470* t, int a2, Vec3_19470* P, Vec3_19470* N, int a5) {
    if (params->f44 == 1)
        return;

    Anchor_19470* anchor = owner->FUN_000592a0();
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
    attacker->FUN_00035230(&request.scratchAttacker);

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
        request.target.FUN_00011160(1.0f, &displacement);
    }

    request.aim = *N;
    settings = params;
    request.r00 = settings->f68;
    request.r04 = settings->f6c;
    request.r91 = settings->b3b;
    request.r54 = settings->fdc;
    Vec3_19470 outputVector;
    FUN_00014210(settings->mode, attacker, t->f12c, &outputVector);

    Params* directionSettings = params;
    Vec3_19470 direction;
    Vec3_19470 alternateDirection;
    Vec3_19470 directionDifference;
    directionSettings->FUN_00012f50(&direction);
    directionSettings->FUN_00012f80(&alternateDirection);
    if (alternateDirection.FUN_000111f0() > 0.0f) {
        float blend = attacker->FUN_0003ebb0(1);
        directionDifference.x = alternateDirection.x - direction.x;
        directionDifference.y = alternateDirection.y - direction.y;
        directionDifference.z = alternateDirection.z - direction.z;
        direction.FUN_00011160(blend, &directionDifference);
    }

    float angle = FUN_00224f10((Mat*)&outputVector);
    FUN_00224d70(angle, &direction);
    request.v38 = direction;
    request.f7c = attacker->FUN_0003ebb0(1);
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
            CFightParamsCollision_19470* allocated = (CFightParamsCollision_19470*)FUN_0008d690(0xb0);
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
        t->FUN_00035b70(directionDifference.x, f40, f44);
        f40 = f40 * 0.75f;
        f44 = f44 * 0.75f;
    }

    Chooser_19470* attackerChooser = params->f58;
    if (attackerChooser) {
        CFightParamsCollision_19470* allocated = (CFightParamsCollision_19470*)FUN_0008d690(0xb0);
        RefObj_19470* copy = allocated ? (RefObj_19470*)allocated->FUN_000598e0(owner->f8, &request) : 0;
        copy->AddRef();
        RefObj_19470* result = attackerChooser->v8(copy, 0);
        if (result && !((Key231*)&attacker->fdc)->FUN_00231e80(result))
            ((Slot231*)result)->FUN_00231ad0(&attacker->fdc, copy, -1);
        copy->Release();
    }
    if (attacker->f328 == 0)
        attacker->FUN_0003ffa0(t->f12c, 0);
    attacker->FUN_00035c70(t->f12c);
    request.FUN_00059300();
}
