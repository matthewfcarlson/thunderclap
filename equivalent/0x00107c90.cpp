// STATUS: equivalent (tools/equiv.py level 3: 20145 inputs, branch coverage 249/256, incomplete)
// CRangedAgent::vfunc_4 @ 0x00107c90
// CRangedAgent::vfunc_4 (ret 0xc, three stack args: ctx, dt, flags): the per-frame update of a ranged enemy
// (the "m_launcher" state). It reads what the fighter's aim info says about the target, then
//   1. works out the vector and distances to the aim point and a set of state flags (launcher state, phase 5, ...);
//   2. decides whether a shot is lined up (nearby agents, a line test, a sweep test) and, if so, either starts the
//      attack (cooldown timers, the fighter's attack call) or schedules the next one;
//   3. steers: a ranged shot when the aim is clear, a charge shot, or else keep-distance movement (back off when too
//      close, close in when too far, strafe along the right vector otherwise) with the heading smoothed through the
//      mover object;
//   4. fills the fighter's action block (`AimOut`, fighter + 0x1f58): move direction, move speed, facing direction.
// The frame struct below is the original's stack frame in slot order: callees' out-parameters live in it and the
// checker's stubs write through those pointers, so the layout is part of the behaviour.
#include "compat/ptr.h"
#include "decls/data/engine/physics.h"
#include "decls/data/game/global.h"

struct Agent;
struct Mat;
struct Fighter;
struct Target;

struct Vec3 {
    float x, y, z;
    double FUN_00018990();                               // length
    double FUN_0022d110();                               // normalise (returns the old length)
    double FUN_000111f0();                               // squared length
    void FUN_000111b0(const Vec3 *a, const Vec3 *b);     // cross product into this
    bool FUN_0022d2b0(const Vec3 *other, float eps);     // nearly equal
    void FUN_000344b0(float s);                          // scale in place
    Vec3 *FUN_00078750(Vec3 *out, Vec3 *rhs);            // this + rhs
};
struct Quat {
    float q[4];
    void FUN_0022b170(float angle, Vec3 *axis);          // from axis and angle
    void FUN_0022b650(struct Mat *m);                    // to matrix
};
struct Mat {
    float m[16];
    void FUN_0022b980();                                 // identity
    void FUN_0022c3b0(Vec3 *in, Vec3 *out);              // transform
};
struct NameObj {
    unsigned lo, hi;
    unsigned FUN_0027b0e0(const char *name);
    unsigned FUN_0027af50();
};
struct NameSlot {
    char raw[8];
    void FUN_0027b040(const char *name);
};
struct AnimSet {
    char raw[336];
    bool FUN_0027af90(unsigned handle);
};

struct Rng {
    double FUN_00078780();                               // random float in [0, 1)
};
Rng *__cdecl FUN_000964d0();
double __cdecl FUN_000964e0();                           // random float in [0, 1) from the global generator

struct Session {
    bool FUN_00099730();
    bool FUN_00099750();
    bool FUN_00099760();
    bool FUN_00099790();
};
struct World {
    char pad0[8];
    Session *session;
};
extern World *DAT_004dd700;

struct Flagged {
    char pad0[114];
    unsigned char disabled;
};
struct Body {
    void FUN_00059a50(Vec3 *outPos);
};
struct Obj220 {
    char raw[64];
    unsigned FUN_00231ee0();
};
struct Sub {
    char pad0[116];
    Flagged *flagged;
};
struct StateEntry {
    char pad0[8];
    unsigned __int64 key;
};
struct FState {
    char pad0[20];
    unsigned phase;                                      // +0x14
    char pad24[408];
    unsigned group;                                      // +0x1b0
    char pad436[496];
    float f932;                                          // +0x3a4
    unsigned f936;                                       // +0x3a8 (copied as bits)
    float f940;                                          // +0x3ac
    StateEntry *FUN_000446c0(unsigned index);
    unsigned __int64 FUN_000443c0();
};
struct ModeObj {
    virtual void vf0(); virtual void vf1(); virtual void vf2(); virtual void vf3(); virtual void vf4();
    virtual void vf5(); virtual void vf6(); virtual void vf7(); virtual void vf8();
    virtual unsigned Mode();
};

// The action block the fighter reads (fighter + 0x1f58).
struct AimOut {
    unsigned act0;                                       // +0
    char pad4[8];
    unsigned act12;                                      // +12
    char pad16[8];
    unsigned act24;                                      // +24
    char pad28[32];
    unsigned act60;                                      // +60
    char pad64[8];
    unsigned act72;                                      // +72
    char pad76[192];
    Vec3 moveDir;                                        // +268
    float moveSpeed;                                     // +280
    Vec3 faceDir;                                        // +284
    Vec3 reach;                                          // +296
    char pad308[12];
    NameSlot nameSlot;                                   // +320
    bool flag328;                                        // +328
    void FUN_00060170();                                 // reset
};

struct Fighter {
    char pad0[16];
    Body *body;                                          // +16
    char pad20[200];
    Obj220 obj220;                                       // +220
    FState *fstate;                                      // +284
    char pad288[12];
    Sub *sub;                                            // +300
    char pad304[6688];
    AnimSet anim;                                        // +6992
    ModeObj *mode;                                       // +7328
    char pad7332[24];
    unsigned shotParam;                                  // +7356
    char pad7360[16];
    unsigned burstBits;                                  // +7376 (copied as bits)
    char pad7380[644];
    AimOut out;                                          // +8024
    void FUN_00036ac0(Vec3 *outPos);
    void *FUN_00035ef0(unsigned index);
    void FUN_0003ffa0(Target *t, unsigned arg);
};
struct GrabObj {
    Vec3 *FUN_001d6b40();
};
struct Target {
    char pad0[8];
    Fighter *entity;                                     // +8
    int kind;                                            // +12
    char pad16[48];
    Vec3 pos;                                            // +64
    char pad76[40];
    Flagged *flagged;                                    // +116
};
struct Info {
    char pad0[8];
    Target *target;                                      // +8
    char pad12[58];
    unsigned char flag70;                                         // +70
    char pad71[41];
    unsigned char flag112;                                        // +112
    bool FUN_000fc800();
    bool FUN_000fc850();
    double FUN_000fc830();                               // range
    void FUN_000fde40(Vec3 *outPos);
    void FUN_000fde60(Vec3 *pos);
};
struct Weapon {
    virtual void vf0(); virtual void vf1(); virtual void vf2(); virtual void vf3();
    virtual unsigned Vf4(void *ctx, unsigned dtBits, unsigned arg);
    virtual void vf5(); virtual void vf6();
    virtual void Vf7(unsigned arg);
    void FUN_001048d0(Agent *agent);
    void FUN_00104c60(void *ctx, Vec3 *from, Vec3 *to, float a, unsigned b, float c, float d);
};
struct Owner {
    virtual void vf0(); virtual void vf1(); virtual void vf2(); virtual void vf3(); virtual void vf4();
    virtual void vf5();
    virtual Fighter *GetFighter();
    char pad4[293];
    unsigned char latch;                                          // +297
    Weapon *FUN_000fefc0();
};
struct Mover {
    virtual void vf0(); virtual void vf1(); virtual void vf2();
    virtual bool Update(void *world, Fighter *f, Vec3 *vel, unsigned dtBits, unsigned zero);
    char pad4[12];
    Vec3 desired;                                        // +16
};
struct Mgr {
    char pad0[12];
    int count;                                           // +12
    Fighter *FUN_00024190(int index);
    bool FUN_00025d30(Fighter *f);
    bool FUN_00024300(Fighter *f);
    void FUN_00029250(Target *t, Vec3 *pos, unsigned a, unsigned b);
};
struct Caster {
    void FUN_00202460(Vec3 *from, Vec3 *to, float len, unsigned a, Vec3 *hit, Vec3 *end, int *result, unsigned b);
};
struct Ctx {
    char pad0[32];
    Mgr *mgr;                                            // +32
    Caster *caster;                                      // +36
};
struct DebugDraw {
    void FUN_0023f820(Vec3 *p, int color, unsigned argb, unsigned flag);
    unsigned FUN_0023f7b0(Vec3 *a, Vec3 *b, unsigned argb, unsigned flag);
};
struct Raycaster {
    bool FUN_002ee140(unsigned id, Vec3 *from, Vec3 *to, unsigned flag);
};

struct Agent {
    char pad0[88];
    Owner *owner;                                        // +88
    Mover *mover;                                        // +92
    Vec3 heading;                                        // +96
    unsigned char fireNow;                                        // +108
    char pad109[3];
    float cooldown;                                      // +112
    float burstTimer;                                    // +116
    float strafeTimer;                                   // +120
    float strafeSign;                                    // +124
    unsigned char tooCloseLatch;                                  // +128
    unsigned char tooFarLatch;                                    // +129
    char pad130[2];
    float minRange;                                      // +132
    float maxRange;                                      // +136
    float nearDist;                                      // +140
    float farDist;                                       // +144
    float cooldownMax;                                   // +148
    float fireWindow;                                    // +152
    float meleeCooldown;                                 // +156
    float awestruckTimer;                                // +160
    char pad164[8];
    float holdTime;                                      // +172
    void FUN_00107c90(void *a1, float a2, int a3);
    unsigned FUN_00107410(AimOut *out, unsigned dtBits);
    bool FUN_00107760(Ctx *ctx, Fighter *fighter, Vec3 *base, Vec3 *step);
};

double __cdecl FUN_000186f0(float *a, float *b);
double __cdecl FUN_00018710(float *a, float *b);
bool __cdecl FUN_00036b10(World *w, Vec3 *from, Vec3 *to, Vec3 *hit, Vec3 *normal, unsigned char *flagA, unsigned char *flagB);
bool __cdecl FUN_00065870(Vec3 *a, Vec3 *b);
Vec3 *__cdecl FUN_00083dd0(Vec3 *out, float s, Vec3 *v);
Vec3 *__cdecl FUN_00083e00(Vec3 *out, Vec3 *v, float s);
void __cdecl FUN_00096a40(Target *t, Vec3 *outPos);
double __cdecl FUN_0010ae50(World *w, Fighter *f, float limit, Vec3 *probe, Vec3 *steer, unsigned a, unsigned b);
double __cdecl FUN_0010b1c0(Ctx *ctx, Fighter *f, float limit, Vec3 *steer);
unsigned __cdecl FUN_00202f00();
unsigned __int64 __cdecl FUN_0027b020(const char *name);

// The original's stack frame, locals S+0x40 .. S+0x18c (offsets in the comments are from S).
struct Frame {
    bool inLauncherState;                                // 64
    bool shotReady;                                      // 65
    bool canMove;                                        // 66
    union { bool bradley; bool inRange; } w67;           // 67
    Vec3 moveDir;                                        // 68
    char pad80[3];
    bool phaseFive;                                      // 83
    Vec3 tmpA;                                           // 84
    float dist;                                          // 96
    char pad100[3];
    bool rangeAdjust;                                    // 103
    float f104;                                          // 104
    char pad108[3];
    bool aiming;                                         // 111
    Vec3 tmpB;                                           // 112
    union { void *spill; float step; } w124;             // 124
    Vec3 flatDir;                                        // 128
    union { void *spill; float limit; } w140;            // 140
    char pad144[2];
    unsigned char b146;                                           // 146
    unsigned char b147;                                           // 147
    Vec3 aimPos;                                         // 148
    Vec3 steer;                                          // 160
    Vec3 tmpC;                                           // 172
    Vec3 vel;                                            // 184
    void *spill196;                                      // 196
    union { Vec3 v; NameObj name; unsigned __int64 key; } w200;                // 200
    char pad212[3];
    bool animPlaying;                                    // 215
    Vec3 myPos;                                          // 216
    union { int count; float lenMinus2; int hit; } w228; // 228
    Vec3 moveResult;                                     // 232
    Vec3 toTarget;                                       // 244
    void *spill256;                                      // 256
    Vec3 right;                                          // 260
    Vec3 base;                                           // 272
    float flatDist;                                      // 284
    void *spill288;                                      // 288
    Vec3 scratchA;                                       // 292
    union { Quat q; Vec3 v; } w304;                      // 304
    Vec3 scratchC;                                       // 320
    Mat mat;                                             // 332
};

#define SET3(v, a, b, c) ((v).x = (a), (v).y = (b), (v).z = (c))

// Heading smoothing shared by four branches: heading = (1 - k) * heading + k * steer, k = DAT_004a1e38.
#define BLEND_HEADING(p1Out, p2Out)                                                      \
    do {                                                                                 \
        Vec3 *damped = FUN_00083dd0((p1Out), DAT_004a1e38, &fr.steer);                   \
        Vec3 *kept = FUN_00083dd0((p2Out), 1.0f - DAT_004a1e38, &this->heading);         \
        this->heading = *kept->FUN_00078750(&fr.scratchC, damped);                       \
    } while (0)

void Agent::FUN_00107c90(void *a1, float a2, int a3)
{
    Ctx *ctx = (Ctx *)a1;
    float dt = a2;
    unsigned dtBits = *(unsigned *)&a2;  // dt is passed on as raw bits (a NaN must not be quieted by a float push)
    Frame fr;

    Rng *rng = FUN_000964d0();
    fr.spill288 = rng;
    Fighter *fighter = this->owner->GetFighter();
    fr.w140.spill = fighter;
    if (!fighter)
        return;
    FState *fstate = fighter->fstate;
    fr.w124.spill = fstate;
    if (!fstate)
        return;
    Info *info = (Info *)((char *)this->owner + 88);
    fr.spill256 = info;
    if (!info)
        return;
    Target *target = info->target;
    fr.spill196 = target;
    if (!target)
        return;
    if ((a3 & 0xff) != 0) {
        this->fireNow = false;
        this->holdTime = 0.0f;
    }
    if (fighter->mode->Mode() == 4)
        return;

    AimOut *out = &fighter->out;
    out->FUN_00060170();
    fr.shotReady = false;
    fr.aiming = info->FUN_000fc800();
    fr.canMove = info->FUN_000fc850();
    Session *session = DAT_004dd700->session;
    fr.b146 = info->flag112;
    if (session) {
        if (session->FUN_00099730() || session->FUN_00099750() || session->FUN_00099760() || session->FUN_00099790())
            fr.canMove = false;
    }

    // Aim point: the target's position, or what the info block says when it is a close target.
    SET3(fr.myPos, 0.0f, 0.0f, 0.0f);
    fighter->FUN_00036ac0(&fr.myPos);
    SET3(fr.aimPos, 0.0f, 0.0f, 0.0f);
    if (info->FUN_000fc830() < 3.0f) {
        fr.tmpC = target->pos;
        info->FUN_000fde40(&fr.tmpA);
        fr.tmpB.x = fr.tmpA.x - fr.tmpC.x;
        fr.tmpB.y = fr.tmpA.y - fr.tmpC.y;
        fr.tmpB.z = fr.tmpA.z - fr.tmpC.z;
        FUN_00096a40(target, &fr.aimPos);
        double aimY = fr.aimPos.y;
        if (target->kind == 1)
            aimY = aimY - 1.0f;
        fr.aimPos.x = fr.tmpB.x + fr.aimPos.x;
        fr.aimPos.y = fr.tmpB.y + aimY;
        fr.aimPos.z = fr.aimPos.z + fr.tmpB.z;
    } else {
        info->FUN_000fde40(&fr.aimPos);
        SET3(fr.tmpA, 0.0f, 0.0f, 0.0f);
        if (FUN_00065870(&fr.aimPos, &fr.tmpA) && info->FUN_000fc830() < 7.0f)
            fr.shotReady = true;
        SET3(fr.tmpA, 0.0f, 0.0f, 0.0f);
        if (fr.aimPos.FUN_0022d2b0(&fr.tmpA, 1e-5f))
            info->FUN_000fde60(&fr.aimPos);
        SET3(fr.tmpA, 0.0f, 0.0f, 0.0f);
        if (fr.aimPos.FUN_0022d2b0(&fr.tmpA, 1e-5f))
            fr.aimPos = target->pos;
    }

    // Distances and unit vectors to the aim point (full and flattened to the ground plane).
    fr.toTarget.x = fr.aimPos.x - fr.myPos.x;
    fr.toTarget.y = fr.aimPos.y - fr.myPos.y;
    fr.toTarget.z = fr.aimPos.z - fr.myPos.z;
    fr.dist = (float)fr.toTarget.FUN_00018990();
    fr.flatDir.z = fr.toTarget.z;
    fr.flatDir.x = fr.toTarget.x;
    fr.flatDir.y = 0.0f;
    fr.flatDist = (float)fr.flatDir.FUN_00018990();
    fr.toTarget.FUN_0022d110();
    fr.flatDir.FUN_0022d110();

    // State flags from the fighter's state machine.
    if (fstate->FUN_000446c0(0)) {
        StateEntry *entry = fstate->FUN_000446c0(0);
        fr.w200.key = entry->key;
        fr.inLauncherState = (fr.w200.key == FUN_0027b020("m_launcher_m_launcher"));
    } else {
        fr.inLauncherState = false;
    }
    fr.rangeAdjust = ctx->mgr->FUN_00024300(fighter);
    fr.phaseFive = (fstate->phase == 5);
    if (!(DAT_004e0ac0[0] & 1)) {
        *(unsigned *)DAT_004e0ac0 |= 1;
        unsigned __int64 hash = FUN_0027b020("bradley");
        DAT_004e0ab8 = (unsigned)hash;
        DAT_004e0abc = (unsigned)(hash >> 32);
    }
    unsigned __int64 stateKey = fstate->FUN_000443c0();
    fr.w67.bradley = (stateKey == ((unsigned __int64)DAT_004e0abc << 32 | DAT_004e0ab8));

    // Timers tick down.
    fighter->obj220.FUN_00231ee0();
    this->cooldown = this->cooldown - dt;
    fr.b147 = info->flag70;
    this->burstTimer = this->burstTimer - dt;
    this->strafeTimer = this->strafeTimer - dt;
    this->FUN_00107410(out, dtBits);
    if (this->awestruckTimer > 0.0f && this->awestruckTimer - dt <= 0.0f) {
        out->nameSlot.FUN_0027b040("awestruck");
        out->flag328 = true;
    }
    this->awestruckTimer = this->awestruckTimer - dt;
    out->faceDir = fr.flatDir;

    // Reach point: where the fighter would be sent to get at the target.
    Vec3 *dirForReach;
    if (fighter->FUN_00035ef0(0)) {
        GrabObj *grab = (GrabObj *)fighter->FUN_00035ef0(0);
        Vec3 *grabPos = grab->FUN_001d6b40();
        fr.w200.v = *grabPos;
        fr.tmpB.x = fr.aimPos.x - fr.w200.v.x;
        fr.tmpB.y = fr.aimPos.y - fr.w200.v.y;
        fr.tmpB.z = fr.aimPos.z - fr.w200.v.z;
        fr.tmpB.FUN_0022d110();
        if (*(unsigned *)DAT_004e0ab0 != 0) {
            DebugDraw *draw = *(DebugDraw **)DAT_004dd6e8;
            draw->FUN_0023f820(&fr.aimPos, DAT_004a1e54, 0xffff0000u, *(unsigned *)DAT_004e0ab0);
            draw = *(DebugDraw **)DAT_004dd6e8;
            draw->FUN_0023f7b0(&fr.w200.v, &fr.aimPos, 0xffff0000u, *(unsigned *)DAT_004e0ab0);
        }
        if (fr.inLauncherState && fr.aimPos.y > fr.w200.v.y && fr.tmpB.y < 0.7f) {
            fr.f104 = 0.0f;
            if (fr.dist > DAT_004a1e50 && !(fr.dist < DAT_004a1e4c))
                fr.f104 = 0.61086524f;
            SET3(fr.tmpA, 0.0f, 1.0f, 0.0f);
            fr.tmpC.FUN_000111b0(&fr.tmpB, &fr.tmpA);
            fr.w304.q.FUN_0022b170(fr.f104, &fr.tmpC);
            fr.mat.FUN_0022b980();
            fr.w304.q.FUN_0022b650(&fr.mat);
            fr.tmpA = fr.tmpB;
            fr.mat.FUN_0022c3b0(&fr.tmpA, &fr.tmpB);
        }
        dirForReach = &fr.tmpB;
    } else {
        dirForReach = &fr.toTarget;
    }
    fr.moveResult = *FUN_00083e00(&fr.tmpA, dirForReach, fr.dist);

    if (fr.phaseFive) {
        Fighter *fighter2 = this->owner->GetFighter();
        bool playing = fighter2->anim.FUN_0027af90(fr.w200.name.FUN_0027b0e0("gethit"));
        fr.animPlaying = playing;
        fr.w200.name.FUN_0027af50();
        if (fr.animPlaying)
            this->cooldown = 0.0f;
    }

    //---- Decide whether to take the shot ----------------------------------------------------------------------
    do {
        if (!(fr.aiming || (fr.shotReady && -this->fireWindow > this->cooldown)))
            break;
        if (!(fr.dist >= this->minRange) && !(this->holdTime > 2.0f))
            break;
        if (!(fr.dist <= this->maxRange))
            break;
        if (!fr.canMove)
            break;
        fr.shotReady = false;
        if (fr.inLauncherState) {
            // Another agent of the same group close to the aim point also counts as a clear shot.
            bool nearAgent = false;
            fr.w228.count = ctx->mgr->count;
            for (int i = 0; i < fr.w228.count; i++) {
                Fighter *other = ctx->mgr->FUN_00024190(i);
                if (!other)
                    continue;
                if (ctx->mgr->FUN_00025d30(other))
                    continue;
                if (other == fighter)
                    continue;
                if (other->fstate->group != fighter->fstate->group)
                    continue;
                other->body->FUN_00059a50(&fr.tmpA);
                fr.tmpC.x = fr.tmpA.x - fr.aimPos.x;
                fr.tmpC.y = fr.tmpA.y - fr.aimPos.y;
                fr.tmpC.z = fr.tmpA.z - fr.aimPos.z;
                if (fr.tmpC.FUN_00018990() < 3.0f) {
                    nearAgent = true;
                    break;
                }
            }
            if (nearAgent) {
                fr.shotReady = true;
            } else if (target->kind == 1 && ctx->mgr->FUN_00025d30(target->entity) && fighter->FUN_00035ef0(0)) {
                // Line test from the fighter towards the aim point, with the two shadow flags switched off.
                fr.tmpC = fr.myPos;
                fr.tmpA.z = fr.aimPos.z - fr.myPos.z;
                fr.tmpB.z = fr.tmpA.z;
                fr.tmpB.x = fr.aimPos.x - fr.myPos.x;
                fr.tmpB.y = fr.aimPos.y - fr.myPos.y;
                fr.f104 = (float)fr.tmpB.FUN_00018990();
                fr.tmpA = fr.tmpB;
                fr.tmpA.FUN_0022d110();
                fr.w228.lenMinus2 = fr.f104 - 2.0f;
                fr.w200.v.x = 1.0f;
                double clamped = FUN_00018710(&fr.w200.v.x, &fr.w228.lenMinus2);
                fr.tmpB = *FUN_00083e00(&fr.w200.v, &fr.tmpA, (float)clamped);
                if (target->flagged)
                    target->flagged->disabled = false;
                if (fighter->sub && fighter->sub->flagged)
                    fighter->sub->flagged->disabled = false;
                unsigned rayId = FUN_00202f00();
                DAT_00554c18 = DAT_004e0aac;
                fr.w200.v.x = fr.tmpB.x + fr.tmpC.x;
                fr.w200.v.y = fr.tmpB.y + fr.tmpC.y;
                DAT_004d2a3c = 2;
                DAT_00554c1c[0] = 0;
                fr.w200.v.z = fr.tmpB.z + fr.tmpC.z;
                if (((Raycaster *)*(hulk_uintptr *)DAT_00554c14)->FUN_002ee140(rayId, &fr.tmpC, &fr.w200.v, 0))
                    fr.shotReady = true;
                if (target->flagged)
                    target->flagged->disabled = true;
                if (fighter->sub && fighter->sub->flagged)
                    fighter->sub->flagged->disabled = true;
                if (!fr.shotReady && !(fr.tmpB.y == 0.0f)) {
                    fr.w228.hit = 0;
                    ctx->caster->FUN_00202460(&fr.tmpC, &fr.tmpB, fr.f104, 1, &fr.scratchA, &fr.w200.v, &fr.w228.hit, 0);
                    if (fr.w228.hit != 0)
                        fr.shotReady = true;
                }
            }
        }

        if (this->cooldown > 0.0f && fr.shotReady && fr.inLauncherState)
            this->cooldown = 0.0f;
        if (this->cooldown > 0.0f) {
            // Cooling down: stand still facing the target and queue the fighter's attack.
            out->moveSpeed = 0.0f;
            out->faceDir = fr.flatDir;
            out->reach = fr.moveResult;
            out->moveDir.z = 0.0f;
            out->moveDir.y = 0.0f;
            out->moveDir.x = 0.0f;
            if (fr.w67.bradley && FUN_000964e0() > 0.5f)
                out->act24 = 1;
            else
                out->act0 = 1;
            if (fr.phaseFive || fr.rangeAdjust || fr.inLauncherState)
                this->cooldown = 0.0f;
            out->act72 = 2;
            fighter->FUN_0003ffa0(target, 0);
        } else {
            out->faceDir = fr.flatDir;
            out->reach = fr.moveResult;
            if (fr.aiming && -this->fireWindow > this->cooldown) {
                // Roll the next attack window from the fighter's state block.
                *(unsigned *)&this->fireWindow = fstate->f936;
                double roll = rng->FUN_00078780();
                this->fireWindow = (float)(((roll * 0.5f) + 1.0f) * this->fireWindow);
                this->cooldownMax = fstate->f932;
                float denom = fstate->f940;
                if (denom <= 0.0f)
                    denom = 1.0f;
                this->cooldown = fstate->f932 / denom;
                ctx->mgr->FUN_00029250(target, &fr.myPos, fighter->shotParam, 1);
            }
        }
    } while (0);

    //---- Movement ------------------------------------------------------------------------------------------
    SET3(fr.steer, 0.0f, 0.0f, 0.0f);
    SET3(fr.vel, 0.0f, 0.0f, 0.0f);
    SET3(fr.base, 0.0f, 0.0f, 0.0f);
    SET3(fr.right, 0.0f, 0.0f, 0.0f);
    SET3(fr.moveDir, 0.0f, 0.0f, 0.0f);
    fr.w67.inRange = fr.aiming && fr.canMove && fr.dist >= this->minRange && fr.dist <= this->maxRange;

    fr.w140.limit = this->owner->latch ? 1.5f : 0.75f;
    double reachRatio = FUN_0010b1c0(ctx, fighter, fr.w140.limit, &fr.steer);
    fr.f104 = (float)reachRatio;
    if (!(reachRatio < 0.0f) && !(fr.f104 > fr.w140.limit)) {
        this->owner->latch = true;
        fr.steer.FUN_0022d110();
        if (!fr.inLauncherState && fr.f104 > 0.75f && fr.w67.inRange &&
            ((fr.steer.x * fr.flatDir.x + fr.steer.z * fr.flatDir.z) + fr.steer.y * fr.flatDir.y) > 0.9f) {
            this->fireNow = true;
            this->owner->latch = false;
            this->tooCloseLatch = false;
            this->tooFarLatch = false;
            SET3(fr.steer, 0.0f, 0.0f, 0.0f);
        } else {
            fr.w124.step = 1.0f;
            fr.w200.v.x = (fr.w140.limit - fr.f104) / fr.w140.limit;
            fr.steer.FUN_000344b0((float)FUN_000186f0(&fr.w124.step, &fr.w200.v.x));
            this->fireNow = false;
        }
    } else {
        this->owner->latch = false;
        SET3(fr.steer, 0.0f, 0.0f, 0.0f);
    }

    if (this->strafeTimer <= 0.0f) {
        volatile float flip = -1.0f;  // a multiply, not a negation: x87 keeps a NaN's sign, clang's fchs flips it
        this->strafeSign = this->strafeSign * flip;
        this->strafeTimer = (float)(rng->FUN_00078780() * 3.0f + 4.0f);
    }
    SET3(fr.tmpA, 0.0f, 1.0f, 0.0f);
    fr.right.FUN_000111b0(&fr.flatDir, &fr.tmpA);
    {
        float sign = this->strafeSign;
        fr.right.x = fr.right.x * sign;
        fr.right.y = fr.right.y * sign;
        fr.right.z = sign * fr.right.z;
    }
    fr.right.FUN_0022d110();
    SET3(fr.tmpB, 0.0f, 0.0f, 0.0f);
    fr.w124.step = (this->farDist - this->nearDist) * 0.25f;

    if (fr.b147 && this->FUN_00107760(ctx, fighter, &fr.base, &fr.tmpB) && !fr.phaseFive) {
        // Walk towards the planned cover point unless something blocks the line.
        fr.tmpA.x = fr.myPos.x - fr.tmpB.x;
        fr.tmpA.y = fr.myPos.y - fr.tmpB.y;
        fr.tmpA.z = fr.myPos.z - fr.tmpB.z;
        this->holdTime = 0.0f;
        fr.tmpC = fr.myPos;
        double stepLen = fr.tmpA.FUN_00018990();
        Vec3 *reach = FUN_00083e00(&fr.scratchA, &fr.base, (float)stepLen);
        fr.tmpA.x = fr.tmpC.x + reach->x;
        fr.tmpA.z = fr.tmpC.z + reach->z;
        fr.tmpC.y = fr.tmpC.y + 1.25f;
        fr.tmpA.y = fr.tmpC.y;
        if (!FUN_00036b10(DAT_004dd700, &fr.tmpC, &fr.tmpA, &fr.moveResult, &fr.scratchA, &fr.b147, &fr.b146)) {
            Weapon *weapon = this->owner->FUN_000fefc0();
            weapon->FUN_001048d0(this);
            weapon->FUN_00104c60(DAT_004dd700, &fr.myPos, &fr.tmpA, 1.0f, 0, 0.5f, 1.0f);
            weapon->Vf4(DAT_004dd700, dtBits, 0);
        } else {
            SET3(fr.steer, 0.0f, 0.0f, 0.0f);
            fr.w124.step = this->owner->latch ? 1.5f : 0.99f;
            double probe = FUN_0010ae50(DAT_004dd700, fighter, 1.5f, &fr.w200.v, &fr.steer, 1, 0);
            if (!(probe < 0.0f) && !(probe > fr.w124.step)) {
                this->owner->latch = true;
            } else {
                this->owner->latch = false;
                SET3(fr.steer, 0.0f, 0.0f, 0.0f);
            }
            this->mover->desired = fr.base;
            this->mover->Update(DAT_004dd700, fighter, &fr.vel, dtBits, 0);
            fr.vel.x = fr.vel.x + fr.vel.x;
            fr.vel.y = fr.vel.y + fr.vel.y;
            fr.vel.z = fr.vel.z + fr.vel.z;
            BLEND_HEADING(&fr.tmpB, &fr.w304.v);
            fr.moveDir.y = 0.0f;
            fr.tmpB.z = fr.base.z + this->heading.z;
            fr.moveDir.x = (fr.base.x + this->heading.x) + fr.vel.x;
            fr.moveDir.z = fr.tmpB.z + fr.vel.z;
            double speed = fr.moveDir.FUN_0022d110();
            if (speed > 1.0f)
                out->moveSpeed = 1.0f;
            else
                out->moveSpeed = (float)speed;
            out->faceDir = fr.flatDir;
            out->moveDir = fr.moveDir;
        }
    } else if (info->FUN_000fc830() >= 2.5 && fr.b146 && !fr.phaseFive) {
        // Charge shot: hold still and fire the weapon from the fighter towards the target.
        this->fireNow = false;
        this->holdTime = 0.0f;
        fighter->body->FUN_00059a50(&fr.tmpC);
        fr.tmpA = target->pos;
        Weapon *weapon = this->owner->FUN_000fefc0();
        weapon->FUN_001048d0(this);
        weapon->FUN_00104c60(ctx, &fr.tmpC, &fr.tmpA, 1.0f, 1, 2.0f, 1.0f);
        weapon->Vf4(ctx, dtBits, a3);
        weapon->Vf7(1);
    } else if (((fr.dist < this->nearDist) || this->tooCloseLatch) && !fr.phaseFive) {
        // Too close: back off (or, in the launcher state's melee window, stop and strike).
        if ((fr.w124.step + this->nearDist) < fr.dist)
            this->tooCloseLatch = false;
        else if (fr.dist < this->nearDist)
            this->tooCloseLatch = true;
        this->fireNow = false;
        if (!fr.inLauncherState && fr.dist < 2.0f && fr.flatDist < 2.0f && this->burstTimer <= 0.0f) {
            *(unsigned *)&this->meleeCooldown = fighter->burstBits;
            double roll = rng->FUN_00078780();
            this->cooldown = 0.0f;
            float scaled = (float)(((roll * 0.5f) + 1.0f) * this->meleeCooldown);
            this->meleeCooldown = scaled;
            this->burstTimer = scaled;
            out->moveSpeed = 0.0f;
            out->faceDir = fr.toTarget;
            out->moveDir.z = 0.0f;
            out->moveDir.y = 0.0f;
            out->moveDir.x = 0.0f;
            out->act12 = 1;
            ctx->mgr->FUN_00029250(target, &fr.myPos, fighter->shotParam, 1);
        } else {
            fr.tmpA.y = -fr.flatDir.y;
            fr.tmpA.z = -fr.flatDir.z;
            fr.moveDir.z = fr.tmpA.z;
            double negX = -fr.flatDir.x;  // kept in a register: a NaN's sign must survive the add below
            fr.moveDir.x = (float)negX;
            fr.moveDir.y = -fr.flatDir.y;
            if (!fr.canMove) {
                fr.moveDir.x = negX + fr.right.x;
                fr.moveDir.y = fr.tmpA.y + fr.right.y;
                fr.moveDir.z = fr.tmpA.z + fr.right.z;
            }
            this->mover->desired = fr.moveDir;
            bool moved = this->mover->Update(ctx, fighter, &fr.vel, dtBits, 0);
            if (!moved && fr.inLauncherState)
                this->holdTime = dt + this->holdTime;
            else
                this->holdTime = 0.0f;
            BLEND_HEADING(&fr.w304.v, &fr.scratchA);
            fr.moveDir.z = fr.moveDir.z + this->heading.z;
            fr.moveDir.x = ((fr.moveDir.x + this->heading.x) + fr.base.x);
            fr.moveDir.x = fr.moveDir.x + fr.vel.x;
            fr.moveDir.y = (((fr.moveDir.y + this->heading.y) + fr.base.y) + fr.vel.y);
            fr.moveDir.z = ((fr.moveDir.z + fr.base.z) + fr.vel.z);
            fr.moveDir.FUN_0022d110();
            out->faceDir = fr.toTarget;
            out->moveDir = fr.moveDir;
            out->moveSpeed = 1.0f;
        }
    } else if (((fr.dist > this->farDist) || this->tooFarLatch) && !fr.phaseFive) {
        // Too far: close in.
        if ((this->farDist - fr.w124.step) > fr.dist)
            this->tooFarLatch = false;
        else if (fr.dist > this->farDist)
            this->tooFarLatch = true;
        this->fireNow = false;
        this->holdTime = 0.0f;
        fr.moveDir.z = fr.base.z + fr.flatDir.z;
        fr.moveDir.x = (fr.base.x + fr.flatDir.x) + fr.vel.x;
        fr.moveDir.y = (fr.base.y + fr.flatDir.y) + fr.vel.y;
        fr.moveDir.z = fr.moveDir.z + fr.vel.z;
        fr.moveDir.FUN_0022d110();
        out->faceDir = fr.toTarget;
        out->moveDir = fr.moveDir;
        out->moveSpeed = 1.0f;
    } else if (!fr.canMove && !fr.phaseFive) {
        // In the comfortable band: strafe.
        this->fireNow = false;
        this->holdTime = 0.0f;
        fr.moveDir.x = fr.right.x + fr.flatDir.x;
        fr.moveDir.y = fr.right.y + fr.flatDir.y;
        fr.moveDir.z = fr.right.z + fr.flatDir.z;
        this->mover->desired = fr.moveDir;
        this->mover->Update(DAT_004dd700, fighter, &fr.vel, dtBits, 0);
        BLEND_HEADING(&fr.w304.v, &fr.scratchA);
        fr.moveDir.z = fr.moveDir.z + this->heading.z;
        fr.moveDir.x = (fr.moveDir.x + this->heading.x) + fr.vel.x;
        fr.moveDir.y = (fr.moveDir.y + this->heading.y) + fr.vel.y;
        fr.moveDir.z = fr.moveDir.z + fr.vel.z;
        fr.moveDir.FUN_0022d110();
        out->faceDir = fr.flatDir;
        out->reach = fr.moveResult;
        out->moveSpeed = 1.0f;
        out->moveDir = fr.moveDir;
    } else {
        out->faceDir = fr.flatDir;
        out->reach = fr.moveResult;
        out->moveSpeed = 0.0f;
        out->moveDir.z = 0.0f;
        out->moveDir.y = 0.0f;
        out->moveDir.x = 0.0f;
        this->holdTime = 0.0f;
        if (!this->fireNow && !fr.rangeAdjust && fr.steer.FUN_000111f0() > 0.01f) {
            this->mover->desired = fr.steer;
            this->mover->Update(DAT_004dd700, fighter, &fr.vel, dtBits, 0);
            BLEND_HEADING(&fr.w304.v, &fr.scratchA);
            fr.w200.v.x = 1.0f;
            fr.moveDir.z = fr.moveDir.z + this->heading.z;
            fr.moveDir.x = (fr.moveDir.x + this->heading.x) + fr.vel.x;
            fr.moveDir.y = (fr.moveDir.y + this->heading.y) + fr.vel.y;
            fr.moveDir.z = fr.moveDir.z + fr.vel.z;
            fr.w124.step = (float)fr.moveDir.FUN_00018990();
            out->moveSpeed = (float)FUN_000186f0(&fr.w124.step, &fr.w200.v.x);
            fr.moveDir.FUN_0022d110();
            out->moveDir = fr.moveDir;
        }
    }

    //---- Common tail ---------------------------------------------------------------------------------------
    if (fr.rangeAdjust) {
        // Long-range adjustment: lean the heading up or down with the target's elevation.
        if (fr.flatDist < 80.0f) {
            double lift = -(fr.toTarget.y * fr.dist);
            fr.f104 = (float)lift;
            if (lift < 3.0f) {
                out->moveDir.y = (((80.0f - fr.flatDist) * 0.0125f) + out->moveDir.y);
                out->moveDir.FUN_0022d110();
                if (out->moveSpeed <= 0.0f) {
                    double k = ((3.0f - fr.f104) * 0.33333334f);
                    out->moveSpeed = (float)k;
                    if (k > 1.0f)
                        out->moveSpeed = 1.0f;
                }
            } else if (fr.f104 > 5.0f) {
                out->moveDir.y = (out->moveDir.y - (((80.0f - fr.flatDist) * 0.0125f)));
                out->moveDir.FUN_0022d110();
                if (out->moveSpeed <= 0.0f) {
                    double k = ((fr.f104 - 5.0f) * 0.2f);
                    out->moveSpeed = (float)k;
                    if (k > 1.0f)
                        out->moveSpeed = 1.0f;
                }
            }
        }
    } else {
        out->moveDir.y = 0.0f;
    }
    if (this->fireNow)
        out->act60 = 2;
}
