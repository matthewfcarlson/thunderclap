// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000ff230..0x00102a50 (kind game, layer game, confidence high), dominant class CHand2HandAgent
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#define TREE_TU_BEGIN namespace fn_f3aa029d {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f3aa029d {} using namespace fn_f3aa029d;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f3aa029d {
struct Thing_ff240 {
    virtual void f0();
    virtual void f1();
};
class Obj_ff260 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
};
struct Status_ff2d0 {
    char pad[0x3a0];
    float value;
    int FUN_000446c0(int);
};
struct Actor_ff2d0 {
    char pad[0x11c];
    Status_ff2d0* status;
    int FUN_00035ef0(int);
};
struct Context {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual Actor_ff2d0* slot6();
    virtual void slot7();
    virtual void slot8();
    virtual int slot9();
    char pad04[0x5c];
    void* active;
    char pad64[0x39];
    unsigned char flag9d;
    unsigned char flag9e;
};
struct NameHolder_ff650 {
    void FUN_0027b040(const char *name);
};
struct Clock_ff650 {
    hulk_freg FUN_00078780();
};
Clock_ff650 *__cdecl FUN_000964d0();
struct Player_ff650 {
    char pad0[0x1ccc];
    float limit;
    char pad1cd0[0x2098 - 0x1cd0];
    NameHolder_ff650 evadeName;
    char pad2099[0x20a0 - 0x2099];
    unsigned char evading;
};
class CCharacterAgent_ff650 {
public:
    virtual void v0();
    virtual void v1();
};
struct Thing_ffeb0 {
    virtual void a();
    virtual void b();
};
extern int hulk_at_0040d1f4;
struct CHand2HandAgent_ffeb0 {
    void run_000fc630();
};
void __cdecl thunk_FUN_00267090(void*);
struct Vec3_101fe0 {
    float x, y, z;
    float FUN_0022d110();
    char FUN_0022d2b0(const Vec3_101fe0 *z, float eps);
};
struct V2_101fe0 {
    float a, b;
};
class CHand2HandAgent : public CCharacterAgent_ff650 {
  public:
    virtual CHand2HandAgent* vfunc_2(unsigned char);
    virtual float vfunc_3(int, int);
    virtual void _m_vf4();
    virtual void _m_vf5();
    virtual void _m_vf6();
    virtual void _m_vf7();
    virtual void _m_vf8();
    virtual void _m_vf9();
    virtual void _m_vf10();
    virtual void _m_vf11();
    virtual char vfunc_12(Player_ff650 *player);
    virtual void _m_vf13();
    virtual void _m_vf14();
    virtual char vfunc_15(World *a1, Ctx *a2);
    virtual void _m_vf16();
    virtual void _m_vf17();
    virtual void _m_vf18();
    virtual void _m_vf19();
    virtual void _m_vf20();
    virtual void _m_vf21();
    virtual void _m_vf22();
    virtual void _m_vf23();
    char _m_pad_4[0x4];
    union { int m8; float score; };
    char _m_pad_c[0x4c];
    union { Context* context; Obj_ff260* obj; };
    union { Thing_ff240* mThing; Thing_ffeb0* thing; };
    union { char b60; unsigned char flag60; char m60; };
    char _m_pad_61[0x3];
    union { float f64; int m64; };
    float m68;
    int m6c;
    float m70;
    float m74;
    char m78;
    char m79;
    union { unsigned char active; char m7a; };
    char m7b;
    char m7c;
    char m7d;
    char _m_pad_7e[0x6];
    float timer;
    Vec3_101fe0 v88;
    float dirX;
    float dirY;
    float dirZ;
    char _m_pad_a0[0x4];
    Vec3_101fe0 va4;
    float ax;
    float ay;
    float az;
    union { float bx; float velX; };
    union { float by; float velY; };
    union { float bz; float velZ; };
    union { float fc8; float speed; };
    char _m_pad_cc[0x7];
    unsigned char flagd3;
    V2_101fe0 vd4;
    V2_101fe0 vdc;
    char _m_pad_e4[0x4];
    float fe8;
    Vec3_101fe0 vec;
    Vec3_101fe0 vf8;
    Vec3_101fe0 v104;
    Vec3_101fe0 v110;
    float f11c;
    float f120;
    char _m_pad_124[0x20];
    Vec3_101fe0 v144;
    float resultX;
    float resultY;
    float resultZ;
    char _m_pad_15c[0x18];
    int x174;
    int x178;
    int x17c;
    float f180;
    int x184;
    int x188;
    int x18c;
    void go();
    void cleanup_000fc630();
    void vfunc_9();
    float FUN_000fc4e0(int, int);
    void vfunc_16();
};
union FloatBits_101fe0 {
    float f;
    unsigned int u;
};
float __cdecl FUN_0010ae50(World *w, Ctx *c, float thr, Vec3_101fe0 *a, Vec3_101fe0 *b, int p, int q);


// 0x000ff240 FUN_000ff240 (32 B): matches/0x000ff240.cpp
// sym: ?go@CHand2HandAgent@fn_f3aa029d@@QAEXXZ
void CHand2HandAgent::go() {
    *(void**)this = &handvtable;
    mThing->f1();
    mThing = 0;
    cleanup_000fc630();
}


// 0x000ff260 CHand2HandAgent::vfunc_9 (105 B): matches/0x000ff260.cpp
// sym: ?vfunc_9@CHand2HandAgent@fn_f3aa029d@@QAEXXZ
void CHand2HandAgent::vfunc_9() {
    m8 = 0;
    obj->g();
    m60 = 0;
    m64 = 0;
    m6c = 0;
    m7a = 0;
    m7b = 0;
    m7c = 0;
    m78 = 0;
    m79 = 0;
    m68 = 999.0f;
    m70 = -1.0f;
    m7d = 1;
    m74 = 10.0f;
    _ReadWriteBarrier();
    x17c = 0;
    x178 = 0;
    x174 = 0;
    x18c = 0;
    x188 = 0;
    x184 = 0;
}


// 0x000ff2d0 CHand2HandAgent::vfunc_3 (224 B): matches/0x000ff2d0.cpp
// sym: ?vfunc_3@CHand2HandAgent@fn_f3aa029d@@UAEMHH@Z
float CHand2HandAgent::vfunc_3(int a, int b) {
    FUN_000fc4e0(a, b);
    Actor_ff2d0* actor = context->slot6();
    Context* saved = context;
    score = 0.0f;
    if (!saved->flag9e) {
        if (saved->slot9() < 3)
            return score;
        if (!saved->flag9d)
            return score;
    }
    if (!context->active)
        return score;
    if (actor->FUN_00035ef0(0)) {
        if (actor->status->FUN_000446c0(0)) {
            if (!(actor->status->value < 4.0f))
                return score;
        }
    }
    if (saved->flag9e && !flag60)
        score = 60.0f;
    else if (flagd3)
        score = 55.0f;
    else
        score = 40.0f;
    return score;
}

} // namespace fn_f3aa029d

// 0x000ff3b0 CHand2HandAgent::vfunc_11 (663 B): equivalent/0x000ff3b0.cpp [wrapped: on include/gen/, and its TU merges more functions without the headers]
// sym: ?vfunc_11@CHand2HandAgent@fn_000ff3b0@@UAEDPAUPlayer_ff3b0@2@MM@Z @0ea376520c14 @w5511ccf573e4
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_000ff3b0 {
// STATUS: equivalent (tools/equiv.py level 3: 19994 inputs, branch coverage 36/36)
// CHand2HandAgent::vfunc_11 @ 0x000ff3b0
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

struct NameKey_ff3b0 {
    unsigned lo;
    unsigned hi;
    void FUN_0027af30(const NameKey_ff3b0 *src);
    void FUN_0027af50();
    void FUN_0027af60(unsigned long long key);
};

struct Gate_ff3b0 {
    char FUN_00099730();
    char FUN_00099750();
    char FUN_00099760();
    char FUN_00099790();
};

struct World {
    char pad[8];
    Gate_ff3b0 *gate;
};

struct RandState_ff3b0 {
    unsigned s0;
    unsigned s1;
    hulk_freg FUN_00078780();
};
RandState_ff3b0 *__cdecl FUN_000964d0();

struct Check_ff3b0 {
    char FUN_00231ee0();
};

struct Zone_ff3b0 {
    char pad[0x3a0];
    float level;
};

struct Player_ff3b0 {
    char pad0[0xdc];
    Check_ff3b0 check;
    char pad1[0x11c - 0xdd];
    Zone_ff3b0 *zone;
    char pad2[0x1cac - 0x120];
    float limitA;
    char pad3[0x1cd0 - 0x1cb0];
    float scale;
    float chance;
    char pad4[0x1d68 - 0x1cd8];
    NameKey_ff3b0 key;
    char pad5[0x1f58 - 0x1d70];
    int flagA;
    char pad6[0x1f64 - 0x1f5c];
    int flagB;
    char pad7[0x1f7c - 0x1f68];
    int flagC;
    char pad8[0x2098 - 0x1f80];
    NameKey_ff3b0 lastKey;
    unsigned char active;

    void FUN_00035140(int a);
    int FUN_00035ef0(int a);
};

class CCharacterAgent_ff3b0 {
public:
    virtual void v0();
    virtual void v1();
};

class CHand2HandAgent : public CCharacterAgent_ff3b0 {
public:
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual char vfunc_11(Player_ff3b0 *player, float a, float b);
    char pad04[0x64 - 4];
    float rv;
    int f68;
    char pad6c[0x7a - 0x6c];
    char r7a;
    char r7b;
    char r7c;
    char pad7d[0xcd - 0x7d];
    char blocked;
};

char CHand2HandAgent::vfunc_11(Player_ff3b0 *player, float a, float b)
{
    char result = 0;
    RandState_ff3b0 *rng = FUN_000964d0();
    hulk_freg scale = player->scale;
    hulk_freg limitA = player->limitA;
    rng->s0 = (rng->s0 & 0xffff) * 0x9069 + (rng->s0 >> 16);
    rng->s1 = (rng->s1 & 0xffff) * 0x4650 + (rng->s1 >> 16);
    union {
        unsigned u;
        float f;
    } bits;
    bits.u = (((rng->s0 << 16) + (rng->s1 & 0xffff)) & 0x7fffff) | 0x3f800000;
    hulk_freg rv0 = (bits.f - 1.0f + 1.0f) * scale;
    char ready = player->check.FUN_00231ee0();
    hulk_freg chance = player->chance;
    Gate_ff3b0 *gate = DAT_004dd700->gate;
    if (gate) {
        if (gate->FUN_00099730() || gate->FUN_00099750() || gate->FUN_00099760() || gate->FUN_00099790())
            return 0;
    }
    if (b > 0.7f && a <= limitA && rv <= 0.0f && !ready && !blocked) {
        NameKey_ff3b0 q;
        q.FUN_0027af30(&player->key);
        if (player->key.lo != 0 || player->key.hi != 0) {
            player->lastKey.FUN_0027af60(*(unsigned long long *)&player->key);
            player->active = 1;
            player->FUN_00035140(0);
            rv = rv0;
            r7a = 0;
            r7b = 0;
            r7c = 0;
            result = 1;
        } else if (player->FUN_00035ef0(0)) {
            if (player->zone->level < 4.0f) {
                if (a < 2.0f)
                    player->flagA = 1;
                else
                    player->flagB = 1;
                rv = rv0;
                f68 = 0;
                r7a = 1;
                r7b = 1;
                r7c = rng->FUN_00078780() < chance;
                result = 1;
            }
        } else {
            hulk_freg rnd = rng->FUN_00078780();
            if (rnd < 0.33f) {
                player->flagA = 1;
            } else if (rnd < 0.66f) {
                player->flagB = 1;
            } else {
                player->flagC = 1;
            }
            rv = rv0;
            f68 = 0;
            r7a = 1;
            r7b = 1;
            r7c = rng->FUN_00078780() < chance;
            result = 1;
        }
        q.FUN_0027af50();
    }
    return result;
}
} // namespace fn_000ff3b0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f3aa029d {

// 0x000ff650 CHand2HandAgent::vfunc_12 (329 B): equivalent/0x000ff650.cpp
// sym: ?vfunc_12@CHand2HandAgent@fn_f3aa029d@@UAEDPAUPlayer_ff650@2@@Z @e0c30b3d3906 @w829df26e52f7
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 16/16)
// CHand2HandAgent::vfunc_12 @ 0x000ff650
char CHand2HandAgent::vfunc_12(Player_ff650 *player)
{
    char result = 0;
    if (timer < 1.0f)
        return 0;
    Clock_ff650 *clock = FUN_000964d0();
    if (speed < 5.5f) {
        float limit = player->limit;
        if (clock->FUN_00078780() < limit) {
            result = 1;
            float dot = velZ * dirZ + velY * dirY + velX * dirX;
            float cross = dirZ * velX - velZ * dirX;
            if (dot > 0.7f) {
                if (clock->FUN_00078780() < 0.33f)
                    player->evadeName.FUN_0027b040("evade_s");
                else if (cross < 0.0f)
                    player->evadeName.FUN_0027b040("evade_e");
                else
                    player->evadeName.FUN_0027b040("evade_w");
                player->evading = result;
            } else if (dot > -0.7f) {
                if (cross < 0.0f)
                    player->evadeName.FUN_0027b040("evade_e");
                else
                    player->evadeName.FUN_0027b040("evade_w");
                player->evading = result;
            }
        }
        timer = 0.0f;
    }
    return result;
}

} // namespace fn_f3aa029d

// 0x000ff7a0 CHand2HandAgent::vfunc_13 (275 B): equivalent/0x000ff7a0.cpp [wrapped: conflict: FUN_000964d0]
// sym: ?vfunc_13@CHand2HandAgent@fn_000ff7a0@@QAE_NPAURecipient_ff7a0@2@@Z @75a091156597 @w049e99c33e07
namespace fn_000ff7a0 {
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 6/6)
// CHand2HandAgent::vfunc_13 @ 0x000ff7a0
struct RandomState_ff7a0 { unsigned first, second; };
extern RandomState_ff7a0* FUN_000964d0();
struct EventName { void FUN_0027b040(const char*); };
struct Recipient_ff7a0 { char pad[0x2098]; EventName event; char pad2[7]; unsigned char active; };
struct CHand2HandAgent {
 char pad[0x84]; unsigned state; char pad2[0xc]; float x,y,z; char pad3[0x1c]; float dx,dy,dz;
 bool vfunc_13(Recipient_ff7a0*);
};
bool CHand2HandAgent::vfunc_13(Recipient_ff7a0* recipient) {
 RandomState_ff7a0* random = FUN_000964d0();
 random->first = (random->first & 0xffffu)*0x9069u + (random->first >> 16);
 random->second = (random->second & 0xffffu)*0x4650u + (random->second >> 16);
 float dot = dz*z + dy*y + dx*x;
 double cross = (double)z*dx - (double)dz*x;
 if (dot > 0.7f || dot > -0.7f) {
  if (cross < 0.0f) recipient->event.FUN_0027b040("evade_e");
  else recipient->event.FUN_0027b040("evade_w");
  recipient->active = 1;
 }
 state = 0;
 return true;
}
} // namespace fn_000ff7a0


// 0x000ff8c0 CHand2HandAgent::vfunc_17 (891 B): equivalent/0x000ff8c0.cpp [wrapped: conflict: CHand2HandAgent; FUN_000964d0]
// sym: ?vfunc_17@CHand2HandAgent@fn_000ff8c0@@UAEDPAUTarget_ff8c0@2@M@Z @5cd8ce86d0b8 @wfdb1dc210656
namespace fn_000ff8c0 {
// STATUS: equivalent (tools/equiv.py level 3: 3024 inputs, branch coverage 43/44, incomplete)
// CHand2HandAgent::vfunc_17 @ 0x000ff8c0
struct Id64_ff8c0 {
    unsigned int lo;
    unsigned int hi;
    void FUN_0027af30(Id64_ff8c0 *src);
    Id64_ff8c0 *FUN_0027b0e0(const char *s);
    char FUN_0027af90(Id64_ff8c0 *other);
    void FUN_0027af50();
    void FUN_0027b040(const char *s);
};

struct Clock_ff8c0 {
    hulk_freg FUN_00078780();
};
Clock_ff8c0 *__cdecl FUN_000964d0();

struct Owner_ff8c0 {
    char pad0[8];
    char *base;
};

struct Target_ff8c0 {
    char pad0[0x140];
    Id64_ff8c0 id;                // 0x140
    char b148;
};

struct Frame_ff8c0 {
    char pad0c;
    char flag3;             // 0xd
    char result;            // 0xe
    char matched;           // 0xf
    Id64_ff8c0 a;                 // 0x10
    Id64_ff8c0 t1;                // 0x18
    Id64_ff8c0 t2;                // 0x20
    Id64_ff8c0 t3;                // 0x28
    Id64_ff8c0 t4;                // 0x30
    Id64_ff8c0 t5;                // 0x38
};

class CCharacterAgent_ff8c0 {
public:
    virtual void v0();
    virtual void v1();
};

class CHand2HandAgent : public CCharacterAgent_ff8c0 {
public:
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual char vfunc_17(Target_ff8c0 *target, float dt);
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    char pad04[0x6c - 4];
    float timer;            // 0x6c
    float f70;
    float f74;
    char b78;
    char pad79[0x94 - 0x79];
    float dirX;
    float dirY;
    float dirZ;
    Owner_ff8c0 *owner;           // 0xa0
    char pada4[0xb0 - 0xa4];
    float velX;
    float velY;
    float velZ;
    char padbc[0xcf - 0xbc];
    char bcf;
    char padd0[3];
    char bd3;
};

char CHand2HandAgent::vfunc_17(Target_ff8c0 *target, float dt)
{
    Frame_ff8c0 f;
    f.a.lo = 0;
    f.result = 0;
    Clock_ff8c0 *clock = FUN_000964d0();
    if (bd3 != 0 || bcf == 0) {
        timer = 0.0f;
        return f.result;
    }
    f.a.FUN_0027af30((Id64_ff8c0 *)(owner->base + 0x1b50));
    char same = f.a.FUN_0027af90(f.t1.FUN_0027b0e0(""));
    f.t1.FUN_0027af50();
    if (same) {
        f.a.FUN_0027af50();
        return 0;
    }
    f.flag3 = 0;
    if (dirZ * velZ + dirY * velY + dirX * velX < -0.7f) {
        unsigned int live = 1;
        f.matched = 1;
        char hit = f.a.FUN_0027af90(f.t5.FUN_0027b0e0("jump_punch_charge"));
        if (!hit) {
            live = 3;
            hit = f.a.FUN_0027af90(f.t4.FUN_0027b0e0("jump_stomp_charge"));
            if (!hit) {
                live = 7;
                hit = f.a.FUN_0027af90(f.t3.FUN_0027b0e0("sonic_clap_hold"));
                if (!hit) {
                    live = 0xf;
                    hit = f.a.FUN_0027af90(f.t2.FUN_0027b0e0("hook_l_hold"));
                    if (!hit) {
                        live = 0x1f;
                        hit = f.a.FUN_0027af90(f.t1.FUN_0027b0e0("hook_r_hold"));
                        f.matched = 0;
                        if (hit)
                            f.matched = 1;
                    }
                }
            }
        }
        if (hit)
            f.matched = 1;
        if (live & 0x10) {
            live &= ~0x10;
            f.t1.FUN_0027af50();
        }
        if (live & 8) {
            live &= ~8;
            f.t2.FUN_0027af50();
        }
        if (live & 4) {
            live &= ~4;
            f.t3.FUN_0027af50();
        }
        if (live & 2) {
            live &= ~2;
            f.t4.FUN_0027af50();
        }
        if (live & 1)
            f.t5.FUN_0027af50();
        if (!f.matched) {
            timer = 0.0f;
            f.a.FUN_0027af50();
            return f.result;
        }
        f.result = 1;
        if (dirZ * velZ + dirY * velY + dirX * velX < -0.98f)
            f.flag3 = 1;
    } else {
        char stomp = f.a.FUN_0027af90(f.t5.FUN_0027b0e0("jump_stomp_charge"));
        f.t5.FUN_0027af50();
        if (stomp) {
            f.result = 1;
        } else {
            char rage = f.a.FUN_0027af90(f.t5.FUN_0027b0e0("rage"));
            f.t5.FUN_0027af50();
            if (!rage) {
                timer = 0.0f;
                f.a.FUN_0027af50();
                return f.result;
            }
            f.result = 1;
            f.flag3 = 1;
            if (!(clock->FUN_00078780() < 0.5f))
                f.flag3 = 0;
        }
    }
    double t = (double)dt + timer;
    timer = (float)t;
    if (!(t > 0.2f)) {
        f.a.FUN_0027af50();
        return f.result;
    }
    f70 = 2.0f - clock->FUN_00078780() * 0.5f;
    f74 = clock->FUN_00078780() * 3.5f + 7.0f;
    bd3 = 1;
    if (f.flag3) {
        target->id.FUN_0027b040("awestruck");
        target->b148 = 1;
        b78 = 0;
        f.a.FUN_0027af50();
        return f.result;
    }
    if (clock->FUN_00078780() < 0.5f)
        b78 = 0;
    else
        b78 = 1;
    f.a.FUN_0027af50();
    return f.result;
}
} // namespace fn_000ff8c0

namespace fn_f3aa029d {

// 0x000ffc40 CHand2HandAgent::vfunc_16 (239 B): equivalent/0x000ffc40.cpp
// sym: ?vfunc_16@CHand2HandAgent@fn_f3aa029d@@QAEXXZ @960ad452454d @w4d3297a3260d
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// CHand2HandAgent::vfunc_16 @ 0x000ffc40
void CHand2HandAgent::vfunc_16() {
    float negativeX = -bx;
    float negativeZ = -bz;
    if ((bx * az + negativeZ * ax + ay * 0.0f) >
        (negativeX * az + bz * ax + ay * 0.0f)) {
        resultX = bz;
        resultZ = negativeX;
    } else {
        resultX = negativeZ;
        resultZ = bx;
    }
    resultY = 0.0f;
    if ((az * bz + ay * by + ax * bx) > 0.8f) {
        resultX = 0.0f;
        resultY = 0.0f;
        resultZ = 0.0f;
        active = 0;
    }
}

} // namespace fn_f3aa029d

// 0x000ffd30 CHand2HandAgent::vfunc_19 (172 B): equivalent/0x000ffd30.cpp [wrapped: on include/gen/, and its TU merges more functions without the headers]
// sym: ?vfunc_19@CHand2HandAgent@fn_000ffd30@@QAEXXZ @0bfb908943de @w4a4bf95c57f2
namespace fn_000ffd30 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 18/18)
// CHand2HandAgent::vfunc_19 @ 0x000ffd30

struct CHand2HandAgent {
 char pad0[0x64];
 float value64;
 char pad68[0xc];
 float value74;
 char pad78[1];
 unsigned char flag79;
 char pad7a[0x53];
 unsigned char flagcd, flagce;
 char padcf[2];
 unsigned char flagd1, flagd2, flagd3;
 float lower, upper, adjusted, previous;
 char pade4[0x44];
 int count;
 void vfunc_19();
};
void CHand2HandAgent::vfunc_19() {
 if (!flagd1 && !flagd2) {
  if (flagcd || flagce || value64 > 0.0f || flag79 || count >= 3 || (*(unsigned char*)&DAT_004e0a99)) {
   previous = upper;
   adjusted = upper - (upper - lower) * 0.25f;
  }
 }
 if (flagd3) {
  float base = value74;
  lower = base;
  adjusted = base;
  upper = base + 2.0f;
  previous = base + 2.0f;
 }
}
} // namespace fn_000ffd30


// 0x000ffde0 CHand2HandAgent::vfunc_7 (186 B): equivalent/0x000ffde0.cpp [wrapped: conflict: CHand2HandAgent]
// sym: ?vfunc_7@CHand2HandAgent@fn_000ffde0@@UAEXE@Z @706e516ee6d9 @w444859a26849
namespace fn_000ffde0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// CHand2HandAgent::vfunc_7 @ 0x000ffde0
struct Display_ffde0 {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5();
 virtual int vfunc_6(const char*, unsigned int);
 virtual void vfunc_7(); virtual void vfunc_8(); virtual int vfunc_9();
};
struct CHand2HandAgent {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(unsigned char enabled); virtual void vfunc_8(int);
 char pad04[0x54]; Display_ffde0* display; char pad5c[0x134]; unsigned int state;
};
void CHand2HandAgent::vfunc_7(unsigned char enabled) {
 if (!enabled) return;
 unsigned int color=0xffffffff;
 if(display->vfunc_9()==1) color=0xffffffff;
 else if(display->vfunc_9()==2) color=0xff0000ff;
 else if(display->vfunc_9()>=3) color=0xffff0000;
 switch(state) {
 case 0: vfunc_8(display->vfunc_6("H2H - D",color)); break;
 case 1: vfunc_8(display->vfunc_6("H2H - O",color)); break;
 case 2: vfunc_8(display->vfunc_6("H2H - I",color)); break;
 case 3: vfunc_8(display->vfunc_6("H2H - A",color)); break;
 }
}
} // namespace fn_000ffde0

namespace fn_f3aa029d {

// 0x000ffeb0 CHand2HandAgent::vfunc_2 (53 B): matches/0x000ffeb0.cpp
// sym: ?vfunc_2@CHand2HandAgent@fn_f3aa029d@@UAEPAV12@E@Z
CHand2HandAgent* CHand2HandAgent::vfunc_2(unsigned char param) {
    Thing_ffeb0* t = thing;
    *(hulk_intptr*)this = (hulk_intptr)&hulk_at_0040d1f4;
    t->b();
    thing = 0;
    ((CHand2HandAgent_ffeb0*)this)->run_000fc630();
    if (param & 1)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_f3aa029d

// 0x000ffef0 CHand2HandAgent::vfunc_14 (1731 B): equivalent/0x000ffef0.cpp [wrapped: macros]
// sym: ?vfunc_14@CHand2HandAgent@fn_000ffef0@@UAEXPAUEnv@2@H@Z @64f4e53a40c9 @wf59fc56b577e
namespace fn_000ffef0 {
// STATUS: equivalent (tools/equiv.py level 3: 927 inputs, branch coverage 122/122)
// CHand2HandAgent::vfunc_14 @ 0x000ffef0
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

typedef unsigned __int64 u64;

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double sqrt(double);
#endif


struct V3 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};

struct Src {
    void FUN_00059a50(V3 *out);
};

struct Ev {
    char pad0[8];
    u64 id;                        // 8
};

struct Sub231 {
    Ev *ev;
    char FUN_00231ee0();
};

struct Sec {
    char pad0[0x14];
    int f14;
};

struct Fighter {
    char pad0[8];
    u64 id;                        // 8
    Src *f10;                      // 0x10
    char pad14[0xdc - 0x14];
    Sub231 sub;                    // 0xdc
    char pade0[0x11c - 0xe0];
    Sec *f11c;
    char pad120[0x1ca8 - 0x120];
    int f1ca8;
    float f1cac;
    int f1cb0;
    int f1cb4;
    void FUN_00035550(V3 *out);
};

struct Mid {
    char pad0[8];
    Fighter *f08;
    int f0c;
    char pad10[0x40 - 0x10];
    float f40, f44, f48;
};

struct Ctrl {
    virtual void c0(); virtual void c1(); virtual void c2(); virtual void c3(); virtual void c4(); virtual void c5();
    virtual Fighter *v6();
    char pad4[0x60 - 0x4];
    Mid *f60;
    char pad64[0x9c - 0x64];
    unsigned char b9c;
    char pad9d;
    unsigned char b9e;
    char pad9f[0xa8 - 0x9f];
    int fa8, fac, fb0, fb4, fb8, fbc, fc0, fc4;
};

struct Reg {
    char pad0[0xc];
    int f0c;
    char FUN_000242d0(Fighter *t);
    char FUN_000242f0(Fighter *t);
    Fighter *FUN_00024190(int i);
};

struct Env {
    char pad0[0x20];
    Reg *f20;
};


#define NAMEHIT(var, str) if (!var) { u64 k_ = ev->id; var = (k_ == FUN_0027b020(str)); }

struct Frame {
    Ctrl *c2;                      // S+0x10
    int count;                     // 0x14
    V3 v;                          // 0x18
};

class CHand2HandAgent {
public:
    virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4(); virtual void a5(); virtual void a6(); virtual void a7(); virtual void a8(); virtual void a9(); virtual void a10(); virtual void a11(); virtual void a12(); virtual void a13();
    virtual void vfunc_14(Env *env, int unused);
    char pad04[0x58 - 0x4];
    Ctrl *f58;
    char pad5c[0x70 - 0x5c];
    float f70;
    char pad74[0x88 - 0x74];
    V3 f88;
    V3 f94;
    Mid *fa0;
    V3 fa4;
    V3 fb0;
    V3 fbc;
    float fc8;
    unsigned char bcc, bcd, bce, bcf, bd0, bd1, bd2, bd3;
    int fd4, fd8, fdc;
    float fe0;
    int fe4, fe8, fec, ff0, ff4, ff8, ffc, f100;
    char pad104[0x11c - 0x104];
    int f11c, f120;
    int f124;
    int f128;
    unsigned char b12c;
    char pad12d[3];
    float f130;
    Ev *f134;
};

void CHand2HandAgent::vfunc_14(Env *env, int unused)
{
    Frame f;
    Fighter *P = f58->v6();
    P->f10->FUN_00059a50(&f88);
    P->FUN_00035550(&f94);
    f94.y = 0.0f;
    f94.FUN_0022d110();
    Ctrl *c2 = f58;
    f.c2 = c2;
    Mid *q = c2->f60;
    fa0 = q;
    if (q->f0c == 1) {
        Fighter *t = q->f08;
        t->f10->FUN_00059a50(&fa4);
        t->FUN_00035550(&fb0);
        fb0.y = 0.0f;
        fb0.FUN_0022d110();
        bd1 = P->sub.FUN_00231ee0();
        bcf = env->f20->FUN_000242d0(t);
        bd0 = env->f20->FUN_000242f0(t);
    } else {
        fa4.x = q->f40;
        fa4.y = q->f44;
        fa4.z = q->f48;
        fb0 = (*(V3*)&DAT_004a1c24);
        bd1 = 0;
        bcf = 0;
        bd0 = 0;
    }
    bcc = c2->b9c;
    fbc.x = fa4.x - f88.x;
    fbc.y = fa4.y - f88.y;
    f.v.z = fa4.z - f88.z;
    fbc.z = f.v.z;
    fbc.y = 0.0f;
    fc8 = (float)sqrt(fbc.x * fbc.x + fbc.y * fbc.y + fbc.z * fbc.z);
    fbc.FUN_0022d110();
    bd2 = c2->b9e;
    if (f70 > 0.0f && f70 <= 2.0f)
        bd3 = 1;
    else
        bd3 = 0;
    bcd = 0;
    bce = 0;
    if (bcf != 0) {
        Ev *ev = fa0->f08->sub.ev;
        if (ev != 0) {
            bool a = false;
            NAMEHIT(a, "idle");
            NAMEHIT(a, "getup");
            NAMEHIT(a, "force_on_ground");
            NAMEHIT(a, "idle_s");
            NAMEHIT(a, "getup_s");
            NAMEHIT(a, "vert");
            NAMEHIT(a, "back_n");
            NAMEHIT(a, "flip_s");
            NAMEHIT(a, "hit_wall_ground");
            NAMEHIT(a, "hit_n");
            NAMEHIT(a, "hit_s");
            NAMEHIT(a, "hit_slide");
            NAMEHIT(a, "land_base");
            NAMEHIT(a, "knockdown_n");
            NAMEHIT(a, "knockdown_s");
            NAMEHIT(a, "knockdown_e");
            NAMEHIT(a, "knockdown_w");
            if (a)
                bcd = 1;
            bool b = false;
            NAMEHIT(b, "lockup");
            NAMEHIT(b, "struggle_base");
            NAMEHIT(b, "break");
            NAMEHIT(b, "default");
            NAMEHIT(b, "pickup");
            if (b)
                bce = 1;
        }
    }
    fd4 = P->f1cb0;
    fd8 = P->f1cb4;
    fdc = P->f1ca8;
    fe0 = P->f1cac;
    fe4 = fd4;
    fe8 = fd8;
    if (bd2 != 0) {
        fec = c2->fa8;
        ff0 = c2->fac;
        ff4 = c2->fb0;
        ff8 = c2->fb4;
        ffc = c2->fb8;
        f100 = c2->fbc;
        f11c = c2->fc0;
        f120 = c2->fc4;
    }
    f124 = 0;
    f128 = 0;
    b12c = 1;
    f130 = -1.0f;
    f.count = env->f20->f0c;
    if (f.count > 0) {
        int i;
        for (i = 0; i < f.count; i++) {
            Fighter *it = env->f20->FUN_00024190(i);
            if (it == 0)
                continue;
            if (it->id == (*(u64*)&DAT_004dc0e0))
                continue;
            if (it == P)
                continue;
            f124++;
            it->f10->FUN_00059a50(&f.v);
            double dx = f.v.x - fa4.x;
            double dy = f.v.y - fa4.y;
            double dz = f.v.z - fa4.z;
            double len1 = sqrt(dz * dz + dy * dy + dx * dx);
            if (len1 < fc8)
                b12c = 0;
            if (len1 <= fe0)
                f128++;
            double ex = f.v.x - f88.x;
            double ey = f.v.y - f88.y;
            double ez = f.v.z - f88.z;
            double len2 = sqrt(ez * ez + ey * ey + ex * ex);
            if (f130 < 0.0f || len2 < f130)
                f130 = (float)len2;
            if (it->f11c->f14 > P->f11c->f14)
                f128++;
        }
    }
    f134 = P->sub.ev;
}
} // namespace fn_000ffef0
#undef NAMEHIT
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001005c0 CHand2HandAgent::vfunc_20 (1391 B): equivalent/0x001005c0.cpp [wrapped: on include/gen/, and its TU merges more functions without the headers]
// sym: ?vfunc_20@CHand2HandAgent@fn_001005c0@@UAEXPAUCtx1_1005c0@2@PAUOut_1005c0@2@TArg3_1005c0@2@@Z @30d153ecdb1e @wf6ec8327d549
namespace fn_001005c0 {
// STATUS: equivalent (tools/equiv.py level 3: 19831 inputs, branch coverage 28/28)
// CHand2HandAgent::vfunc_20 @ 0x001005c0


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double sqrt(double);
#endif


struct Vec3_1005c0 {
    float x, y, z;
    float FUN_0022d110();
    char FUN_0022d2b0(const Vec3_1005c0 *z, float eps);
};

struct Obj104;

class CHand2HandAgent;

struct World;
struct List_1005c0 {
    void FUN_00029250(int a, Vec3_1005c0 *p, int b, int c);
};
struct World2_1005c0 {
    char pad00[0x20];
    List_1005c0 *list;
};

struct Ctx1_1005c0 {
    char pad[0x1cbc];
    int f1cbc;
};

struct Out_1005c0 {
    char pad00[0x10c];
    float v10c[3];
    float f118;
    float v11c[3];
};

union Arg3_1005c0 {
    float f;
    unsigned int u;
};

class Obj104 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4(World2_1005c0 *w, Arg3_1005c0 a3, int z);
    void FUN_001048d0(CHand2HandAgent *a);
    void FUN_00104c60(World2_1005c0 *w, Vec3_1005c0 *a, Vec3_1005c0 *b, float c, int d, float e, float f);
};

struct Obj58_1005c0 {
    char pad[0x129];
    char b129;
    Obj104 *FUN_000fefc0();
};

class Obj5c {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3(World2_1005c0 *w, Ctx1_1005c0 *c, Vec3_1005c0 *out, Arg3_1005c0 a3, int z);
    char pad04[0xc];
    Vec3_1005c0 v10;
};


#define DAT_004dd700 (*(World2_1005c0 * *)&::DAT_004dd700)


extern "C" char __cdecl FUN_00036b10(World2_1005c0 *w, Vec3_1005c0 *a, Vec3_1005c0 *b, Vec3_1005c0 *c, Vec3_1005c0 *d, char *e, char *f);
float __cdecl FUN_0010ae50(World2_1005c0 *w, Ctx1_1005c0 *c, float thr, Vec3_1005c0 *out, Vec3_1005c0 *v138, int a, int b);

class CHand2HandAgent {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual char vfunc_11(Ctx1_1005c0 *c, int a, Arg3_1005c0 b);
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual char vfunc_18(float f);
    virtual void vfunc_19();
    virtual void vfunc_20(Ctx1_1005c0 *c, Out_1005c0 *o, Arg3_1005c0 a3);
    char pad04[0x54];
    Obj58_1005c0 *f58;
    Obj5c *f5c;
    char pad60[0x28];
    Vec3_1005c0 v88;
    Vec3_1005c0 v94;
    int fa0;
    char pada4[0x18];
    Vec3_1005c0 vbc;
    int fc8;
    char padcc[5];
    char bd1;
    char padd2;
    char bd3;
    char padd4[0x104 - 0xd4];
    Vec3_1005c0 v104;
    char pad110[0x138 - 0x110];
    Vec3_1005c0 v138;
    Vec3_1005c0 v144;
    char pad150[0x15c - 0x150];
    Vec3_1005c0 v15c;
    Vec3_1005c0 v168;
    Vec3_1005c0 v174;
    float f180;
    Vec3_1005c0 v184;
};

void CHand2HandAgent::vfunc_20(Ctx1_1005c0 *a1, Out_1005c0 *a2, Arg3_1005c0 a3)
{
    struct Frame {
        char pad0[2];
        char b12;
        char b13;
        float thr;
        Vec3_1005c0 V;
        float tmp[3];
        Vec3_1005c0 P;
        Vec3_1005c0 Zv;
        Vec3_1005c0 F48;
        Vec3_1005c0 F54;
        Vec3_1005c0 O50;
    } f;

    f.V = v88;
    double dx = v88.x - v104.x;
    double dy = v88.y - v104.y;
    double dz = v88.z - v104.z;
    double L = sqrt(dz * dz + dy * dy + dx * dx);
    volatile float Lz = (float)(L * v144.z);
    f.P.x = f.V.x + L * v144.x;
    f.P.z = f.V.z + Lz;
    f.V.y = f.V.y + 1.25f;
    f.P.y = f.V.y;
    if (!FUN_00036b10(DAT_004dd700, &f.V, &f.P, &f.F54, &f.F48, &f.b13, &f.b12)) {
        Obj104 *o = f58->FUN_000fefc0();
        o->FUN_001048d0(this);
        o->FUN_00104c60(DAT_004dd700, &v88, &f.P, 1.0f, 0, 0.5f, 1.0f);
        o->v4(DAT_004dd700, a3, 0);
        return;
    }
    v168.z = 0.0f;
    v168.y = 0.0f;
    v168.x = 0.0f;
    v15c.z = 0.0f;
    v15c.y = 0.0f;
    v15c.x = 0.0f;
    v138.z = 0.0f;
    v138.y = 0.0f;
    v138.x = 0.0f;
    f.thr = 1.5f;
    if (f58->b129 == 0)
        f.thr = 0.99f;
    float r = FUN_0010ae50(DAT_004dd700, a1, 1.5f, &f.O50, &v138, 1, 0);
    if (r < 0.0f || r > f.thr) {
        f58->b129 = 0;
        v138.z = 0.0f;
        v138.y = 0.0f;
        v138.x = 0.0f;
    } else {
        f58->b129 = 1;
    }
    // member by member: f5c may point into this object, and the original copies one word at a time
    Vec3_1005c0 *dst = &f5c->v10;
    dst->x = v144.x;
    dst->y = v144.y;
    dst->z = v144.z;
    f5c->v3(DAT_004dd700, a1, &v15c, a3, 0);
    v15c.x = v15c.x + v15c.x;
    v15c.y = v15c.y + v15c.y;
    v15c.z = v15c.z + v15c.z;
    double bx = DAT_004a1c08 * v138.x;
    volatile float by = DAT_004a1c08 * v138.y;
    volatile float bz = DAT_004a1c08 * v138.z;
    double w = 1.0f - DAT_004a1c08;
    volatile float t0 = w * v174.x;
    volatile float t1 = w * v174.y;
    volatile float t2 = w * v174.z;
    float nx = bx + t0;
    volatile float ny = t1 + by;
    volatile float nz = t2 + bz;
    v174.z = nz;
    v174.x = nx;
    v174.y = ny;
    double x1 = v174.x + v144.x;
    volatile float y1 = v144.y + v174.y;
    volatile float z1 = v144.z + v174.z;
    double x2 = x1 + v15c.x;
    double y2 = y1 + v15c.y;
    volatile float z2 = z1 + v15c.z;
    f.Zv.x = 0.0f;
    f.Zv.y = 0.0f;
    v168.z = z2;
    v168.x = (float)x2;
    v168.y = (float)y2;
    v168.y = 0.0f;
    f.Zv.z = 0.0f;
    float clamp;
    if (!v144.FUN_0022d2b0(&f.Zv, 1e-05f)) {
        if (1.0f < f180) {
            a3.f = 1.0f;
        } else {
            float v = f180;
            if (0.0f < v)
                a3.f = v;
            else
                a3.u = 0;
        }
    } else {
        double l3 = sqrt(v168.x * v168.x + v168.y * v168.y + v168.z * v168.z);
        a3.f = (float)l3;
        if (1.0f < a3.f) {
            a3.f = 1.0f;
        } else {
            float v = a3.f;
            if (0.0f < v)
                a3.f = v;
            else
                a3.u = 0;
        }
    }
    double l4 = sqrt(v168.x * v168.x + v168.y * v168.y + v168.z * v168.z);
    if (l4 < DAT_004a1c04) {
        v168.z = 0.0f;
        v168.y = 0.0f;
        v168.x = 0.0f;
        a2->v10c[2] = 0.0f;
        a2->v10c[1] = 0.0f;
        a2->v10c[0] = 0.0f;
        a2->f118 = 0.0f;
    } else {
        v168.FUN_0022d110();
        a2->f118 = a3.f;
        a2->v10c[0] = v168.x;
        a2->v10c[1] = v168.y;
        a2->v10c[2] = v168.z;
    }
    double z0 = DAT_004a1c0c * 0.0f;
    a2->v11c[0] = vbc.x;
    a2->v11c[1] = vbc.y;
    a2->v11c[2] = vbc.z;
    f.Zv.x = (float)z0;
    f.Zv.y = (float)z0;
    double w2 = 1.0f - DAT_004a1c0c;
    volatile float u0 = w2 * v184.x;
    volatile float u1 = w2 * v184.y;
    volatile float u2 = w2 * v184.z;
    double ax = u0 + f.Zv.x;
    double ay = u1 + f.Zv.y;
    volatile float az = u2 + z0;
    v184.z = az;
    v184.x = (float)ax;
    v184.y = (float)ay;
    a3.f = v94.z * vbc.z + v94.y * vbc.y + vbc.x * v94.x;
    if ((*(char*)&DAT_004e0a99) != 0)
        return;
    if (bd1)
        return;
    if (bd3)
        return;
    if (!vfunc_18(1.5f))
        return;
    if (!vfunc_11(a1, fc8, a3))
        return;
    DAT_004dd700->list->FUN_00029250(fa0, &v88, a1->f1cbc, 1);
}
} // namespace fn_001005c0
#undef DAT_004dd700


// 0x00100b30 CHand2HandAgent::vfunc_21 (1846 B): equivalent/0x00100b30.cpp [wrapped: on include/gen/, and its TU merges more functions without the headers]
// sym: ?v21@CHand2HandAgent@fn_00100b30@@UAEXPAUArg1_100b30@2@PAUOut_100b30@2@M@Z @69612841d7d6 @w3d35274ddc69
namespace fn_00100b30 {
// STATUS: equivalent (tools/equiv.py level 3: 19818 inputs, branch coverage 68/72, incomplete)
// CHand2HandAgent::vfunc_21 @ 0x00100b30
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


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double sqrt(double);
#endif


struct V3_100b30 {
    float x, y, z;
    hulk_freg FUN_0022d110();
    void Add(const V3_100b30 &o) { x = x + o.x; y = o.y + y; z = o.z + z; }
};

struct Name_100b30 {
    void FUN_0027b040(const char *s);
};

struct Obj58_100b30 {
    char pad0[0x129];
    char b129;
};

struct World;
struct Arg1_100b30 {
    char pad0[0x1cbc];
    int f1cbc;
};

class P5c_100b30 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual char v3(World *hub, Arg1_100b30 *a1, V3_100b30 *out, float a3, int z);
    char pad04[0xc];
    V3_100b30 v10;
};

struct Hub20_100b30 {
    void FUN_00029250(int a, V3_100b30 *v, int b, int c);
};
struct World {
    char pad0[0x20];
    Hub20_100b30 *p20;
};

float __cdecl FUN_0010ae50(World *h, Arg1_100b30 *a, float f, V3_100b30 *v1, V3_100b30 *v2, int z1, int z2);

struct Out_100b30 {
    char pad0[0x10c];
    V3_100b30 v10c;
    float f118;
    V3_100b30 v11c;
    V3_100b30 v128;
    char pad134[0x140 - 0x134];
    Name_100b30 name;
    char pad141[7];
    char b148;
};

struct Frame_100b30 {
    char pad0[2];
    char b2;
    char b3;
    float s4;
    float s8;
    float sc;
    volatile float Tx, Ty, Tz;
    V3_100b30 U;
    volatile float Wx, Wy, Wz;
};

class CHand2HandAgent {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual char v11(Arg1_100b30 *a, float b, float c);
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual char v18(float f);
    virtual void v19();
    virtual void v20();
    virtual void v21(Arg1_100b30 *a0, Out_100b30 *a1, float a2);
    virtual void v22();
    virtual void v23();
    char pad04[0x58 - 4];
    Obj58_100b30 *p58;
    P5c_100b30 *p5c;
    char pad60[4];
    float f64;
    char pad68[0x70 - 0x68];
    float f70;
    char pad74[4];
    char b78;
    char pad79[4];
    char b7d;
    char pad7e;
    char b7f;
    float f80;
    char pad84[4];
    V3_100b30 v88;
    V3_100b30 v94;
    int fa0;
    char pada4[0xb0 - 0xa4];
    V3_100b30 vb0;
    V3_100b30 vbc;
    float fc8;
    char padcc[0xd1 - 0xcc];
    char bd1;
    char bd2;
    char bd3;
    float fd4, fd8, fdc, fe0;
    char pade4[0x124 - 0xe4];
    int f124;
    char pad128[0x130 - 0x128];
    float f130;
    char pad134[0x138 - 0x134];
    V3_100b30 v138;
    V3_100b30 v144;
    char pad150[0x15c - 0x150];
    V3_100b30 v15c;
    V3_100b30 v168;
    V3_100b30 v174;
    float f180;
    V3_100b30 v184;
};

void CHand2HandAgent::v21(Arg1_100b30 *a0, Out_100b30 *a1, float a2)
{
    Frame_100b30 f;

    f.s8 = (fe0 - fdc) * 0.25f;
    if (fd8 - f.s8 > fc8)
        b7f = 0;
    else if (fc8 > fd8)
        b7f = 1;
    f.s4 = 1.0f;
    if (fc8 > fd4 && fc8 < fd8 && !(*(char*)&DAT_004a1bfc))
        f.s4 = (fd8 - fc8) / f.s8;

    v15c.z = 0.0f;
    v15c.y = 0.0f;
    v15c.x = 0.0f;
    v168.z = 0.0f;
    v168.y = 0.0f;
    v168.x = 0.0f;
    f.b2 = 0;
    f.sc = vbc.z * v94.z + vbc.y * v94.y + vbc.x * v94.x;

    if (fc8 < fd4) {
        if (!bd2) {
            f.b2 = 1;
            v168.x = vbc.x * -1.0f;
            v168.y = vbc.y * -1.0f;
            v168.z = vbc.z * -1.0f;
        }
    } else {
        if (!bd1 && !bd3 && b7d && f130 > 2.0f && fc8 > 7.0f && fc8 < 10.0f && f124 > 0) {
            a1->name.FUN_0027b040("gesture_1");
            a1->b148 = 1;
            b7d = 0;
            return;
        }
        v168 = vbc;
    }
    if (f80 > 0.0f) {
        v168.z = 0.0f;
        v168.y = 0.0f;
        v168.x = 0.0f;
    }
    v138.z = 0.0f;
    v138.y = 0.0f;
    v138.x = 0.0f;
    f.U.x = vbc.x;
    f.U.y = vbc.y;
    f.U.z = vbc.z;
    f.s8 = 1.5f;
    if (!p58->b129)
        f.s8 = 0.9900000095367432f;
    float r = FUN_0010ae50(DAT_004dd700, a0, 1.5f, &f.U, &v138, 0, 0);
    if (r < 0.0f || r > f.s8) {
        p58->b129 = 0;
        v138.z = 0.0f;
        v138.y = 0.0f;
        v138.x = 0.0f;
    } else {
        p58->b129 = 1;
    }
    p5c->v10.x = v168.x;
    p5c->v10.y = v168.y;
    p5c->v10.z = v168.z;
    char hit = p5c->v3(DAT_004dd700, a0, &v15c, a2, 0);
    f.b3 = hit;
    v15c.x = v15c.x + v15c.x;
    v15c.y = v15c.y + v15c.y;
    v15c.z = v15c.z + v15c.z;

    f.Wy = DAT_004a1c08 * v138.y;
    f.Wz = DAT_004a1c08 * v138.z;
    double m = 1.0f - DAT_004a1c08;
    f.Tx = m * v174.x;
    f.Ty = m * v174.y;
    f.Tz = m * v174.z;
    v174.z = f.Tz + f.Wz;
    v174.x = DAT_004a1c08 * v138.x + f.Tx;
    v174.y = f.Ty + f.Wy;

    v168.Add(v174);
    v168.Add(v144);
    v168.Add(v15c);

    if (!hit && f.b2) {
        v168.z = 0.0f;
        v168.y = 0.0f;
        v168.x = 0.0f;
        f64 = f64 - a2;
    } else {
        f.b2 = 0;
    }

    double len = sqrt(v168.x * v168.x + v168.y * v168.y + v168.z * v168.z);
    if (1.0f < len)
        a2 = 1.0f;
    else
        a2 = (float)len;

    if (sqrt(v168.x * v168.x + v168.y * v168.y + v168.z * v168.z) < DAT_004a1c04) {
        v168.z = 0.0f;
        v168.y = 0.0f;
        v168.x = 0.0f;
        a1->v10c.z = 0.0f;
        a1->v10c.y = 0.0f;
        a1->v10c.x = 0.0f;
        a1->f118 = 0.0f;
    } else {
        v168.FUN_0022d110();
        a1->f118 = a2;
        a1->v10c.x = v168.x;
        a1->v10c.y = v168.y;
        a1->v10c.z = v168.z;
    }

    float z0 = DAT_004a1c0c * 0.0f;
    f.Wx = z0;
    f.Wy = z0;
    double m2 = 1.0f - DAT_004a1c0c;
    f.Tx = m2 * v184.x;
    f.Ty = m2 * v184.y;
    f.Tz = m2 * v184.z;
    v184.z = f.Tz + z0;
    v184.x = f.Tx + f.Wx;
    v184.y = f.Ty + f.Wy;

    if (b78 && bd3 && fc8 < fd4) {
        if (f.b2 && !hit) {
            if (vb0.z * v94.z + vb0.y * v94.y + vb0.x * v94.x < -0.98f && f70 > 0.75f) {
                a1->name.FUN_0027b040("awestruck");
                a1->b148 = 1;
                bd1 = 1;
            }
            a1->f118 = 0.0f;
            a1->v11c.x = vbc.x;
            a1->v11c.y = vbc.y;
            a1->v11c.z = vbc.z;
            b78 = 0;
        } else {
            a1->f118 = 1.0f;
            a1->v11c.x = -vbc.x;
            a1->v11c.y = -vbc.y;
            a1->v11c.z = -vbc.z;
        }
    } else {
        a1->v11c.x = vbc.x;
        a1->v11c.y = vbc.y;
        a1->v11c.z = vbc.z;
    }
    a1->v10c.x = v168.x;
    a1->v10c.y = v168.y;
    a1->v10c.z = v168.z;
    a1->f118 = (f.s4 < a1->f118) ? f.s4 : a1->f118;

    if ((*(char*)&DAT_004e0a99) || bd1 || bd3)
        return;
    if (!v18(1.5f))
        return;
    if (!(fc8 < fd4))
        return;
    if (!v11(a0, fc8, f.sc))
        return;
    DAT_004dd700->p20->FUN_00029250(fa0, &v88, a0->f1cbc, 1);
}
} // namespace fn_00100b30
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00101270 CHand2HandAgent::vfunc_22 (1977 B): equivalent/0x00101270.cpp [wrapped: on include/gen/, and its TU merges more functions without the headers]
// sym: ?v22@CHand2HandAgent@fn_00101270@@UAEXPAUArg1_101270@2@PAUOut_101270@2@M@Z @21b783e912e4 @wb790ad617d1b
namespace fn_00101270 {
// STATUS: equivalent (tools/equiv.py level 3: 19807 inputs, branch coverage 75/76, incomplete)
// CHand2HandAgent::vfunc_22 @ 0x00101270
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


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double sqrt(double);
#endif

struct V3_101270 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};
struct Name_101270 {
    void FUN_0027b040(const char*);
};
struct Obj58_101270 {
    char pad[0x129];
    char b129;
};
struct World;
struct Arg1_101270 {
    char pad[0x1cbc];
    int f1cbc;
};
class P5c_101270 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual char v3(World*, Arg1_101270*, V3_101270*, float, int);
    char pad[12];
    V3_101270 v10;
};
struct Hub20_101270 {
    void FUN_00029250(int, V3_101270*, int, int);
};
struct World {
    char pad[0x20];
    Hub20_101270* p20;
};
struct Rng_101270 {
    hulk_freg FUN_00078780();
};
Rng_101270* __cdecl FUN_000964d0();
float __cdecl FUN_0010ae50(World*, Arg1_101270*, float, V3_101270*, V3_101270*, int, int);
struct Out_101270 {
    char pad[0x10c];
    V3_101270 v10c;
    float f118;
    V3_101270 v11c, v128;
    char pad134[12];
    Name_101270 name;
    char pad141[7];
    char b148;
};
class CHand2HandAgent {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual char v11(Arg1_101270*, float, float);
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual char v18(float);
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22(Arg1_101270*, Out_101270*, float);
    virtual void v23();
    char pad04[0x54];
    Obj58_101270* p58;
    P5c_101270* p5c;
    char pad60[4];
    float f64;
    char pad68[8];
    float f70;
    char pad74[4];
    char b78, pad79, b7a, b7b;
    char pad7c[2];
    char b7e, pad7f;
    float f80;
    char pad84[4];
    V3_101270 v88, v94;
    int fa0;
    char pada4[12];
    V3_101270 vb0, vbc;
    float fc8;
    char padcc[5];
    char bd1, bd2, bd3;
    char padd4[8];
    float fdc, fe0;
    char pade4[0x54];
    V3_101270 v138, v144, v150, v15c, v168, v174;
    float f180;
    V3_101270 v184;
};
void CHand2HandAgent::v22(Arg1_101270* actor, Out_101270* out, float timeStep) {
    bool approaching = fc8 < fdc || b7e != 0;
    volatile float quarterRange = (fe0 - fdc) * 0.25f;
    if ((double)(fe0 - fdc) * 0.25f + fdc < fc8)
        b7e = 0;
    else if (fc8 < fdc)
        b7e = 1;
    hulk_freg limit = 1.0f;
    if (fc8 > fdc && fc8 < fe0 && !(*(char*)&DAT_004a1bfc))
        limit = (fdc - fc8) / quarterRange;
    Rng_101270* rng = FUN_000964d0();
    v15c.z = 0;
    v15c.y = 0;
    v15c.x = 0;
    v168.z = 0;
    v168.y = 0;
    v168.x = 0;
    out->v11c.x = vbc.x;
    out->v11c.y = vbc.y;
    out->v11c.z = vbc.z;
    out->v128.x = vbc.x;
    out->v128.y = vbc.y;
    out->v128.z = vbc.z;
    bool recoiling = false;
    volatile float facing = vbc.z * v94.z + vbc.y * v94.y + vbc.x * v94.x;
    if (approaching) {
        if (!bd2) {
            recoiling = true;
            v168.x = vbc.x * -1.0f;
            v168.y = vbc.y * -1.0f;
            v168.z = vbc.z * -1.0f;
            f64 = f64 - timeStep;
        }
        if (facing > 0.7f && rng->FUN_00078780() < 0.33f && !bd1 && b7b) {
            out->name.FUN_0027b040("evade_s");
            out->b148 = 1;
            b7b = 0;
            return;
        }
    } else {
        v168.x = vbc.x;
        v168.y = vbc.y;
        v168.z = vbc.z;
    }
    if (f80 > 0.0f) {
        v168.z = 0;
        v168.y = 0;
        v168.x = 0;
    }
    if (!(*(char*)&DAT_004e0a99) && !bd1 && !bd3 && v18(1.5f)) {
        if (v11(actor, fc8, facing))
            DAT_004dd700->p20->FUN_00029250(fa0, &v88, actor->f1cbc, 1);
    }
    if (!bd1 && !bd3 && f64 > 0.0f && b7a)
        v16();
    v138.z = 0;
    v138.y = 0;
    v138.x = 0;
    hulk_freg threshold = p58->b129 ? 1.5f : 0.9900000095367432f;
    hulk_freg result = FUN_0010ae50(DAT_004dd700, actor, 1.5f, &v150, &v138, 0, 0);
    if (result < 0.0f || result > threshold) {
        p58->b129 = 0;
        v138.z = 0;
        v138.y = 0;
        v138.x = 0;
    } else
        p58->b129 = 1;
    p5c->v10.x = v168.x;
    p5c->v10.y = v168.y;
    p5c->v10.z = v168.z;
    char hit = p5c->v3(DAT_004dd700, actor, &v15c, timeStep, 0);
    volatile float forceX = DAT_004a1c08 * v138.x;
    volatile float forceY = DAT_004a1c08 * v138.y;
    volatile float forceZ = DAT_004a1c08 * v138.z;
    double retention = 1.0f - DAT_004a1c08;
    volatile float oldX = retention * v174.x;
    volatile float oldY = retention * v174.y;
    volatile float oldZ = retention * v174.z;
    v174.z = oldZ + forceZ;
    v174.x = DAT_004a1c08 * v138.x + oldX;
    v174.y = oldY + forceY;
    volatile float* motion = &v168.x;
    motion[0] = v174.x + motion[0];
    motion[1] = v174.y + motion[1];
    motion[2] = v174.z + motion[2];
    motion[0] = motion[0] + v144.x;
    motion[1] = v144.y + motion[1];
    motion[2] = v144.z + motion[2];
    double impactX = v15c.x + v15c.x;
    double impactY = v15c.y + v15c.y;
    volatile float impactZ = v15c.z + v15c.z;
    motion[0] = impactX + motion[0];
    motion[1] = impactY + motion[1];
    motion[2] = impactZ + motion[2];
    motion[0] = v150.x + motion[0];
    motion[1] = v150.y + motion[1];
    motion[2] = v150.z + motion[2];
    if (!hit && recoiling) {
        v168.z = 0;
        v168.y = 0;
        v168.x = 0;
        f64 = f64 - timeStep;
    } else
        recoiling = false;
    double magnitude = sqrt(v168.x * v168.x + v168.y * v168.y + v168.z * v168.z);
    hulk_freg strength = 1.0f < magnitude ? 1.0f : (float)magnitude;
    if (sqrt(v168.x * v168.x + v168.y * v168.y + v168.z * v168.z) < DAT_004a1c04) {
        v168.z = 0;
        v168.y = 0;
        v168.x = 0;
        out->v10c.z = 0;
        out->v10c.y = 0;
        out->v10c.x = 0;
        out->f118 = 0;
    } else {
        v168.FUN_0022d110();
        out->f118 = strength;
        out->v10c.x = v168.x;
        out->v10c.y = v168.y;
        out->v10c.z = v168.z;
    }
    hulk_freg zeroForce = DAT_004a1c0c * 0.0f;
    volatile float smoothX = zeroForce;
    volatile float smoothY = zeroForce;
    double damping = 1.0f - DAT_004a1c0c;
    volatile float dampX = damping * v184.x;
    volatile float dampY = damping * v184.y;
    volatile float dampZ = damping * v184.z;
    v184.z = dampZ + zeroForce;
    v184.x = dampX + smoothX;
    v184.y = dampY + smoothY;
    if (b78 && bd3 && fc8 < fdc) {
        if (recoiling && !hit) {
            if (vb0.z * v94.z + vb0.y * v94.y + vb0.x * v94.x < -0.98f && f70 > 0.75f) {
                out->name.FUN_0027b040("awestruck");
                out->b148 = 1;
            }
            out->f118 = 0;
            out->v11c.x = vbc.x;
            out->v11c.y = vbc.y;
            out->v11c.z = vbc.z;
            b78 = 0;
        } else {
            out->f118 = 1.0f;
            out->v11c.x = -vbc.x;
            out->v11c.y = -vbc.y;
            out->v11c.z = -vbc.z;
        }
    } else {
        out->v11c.x = vbc.x;
        out->v11c.y = vbc.y;
        out->v11c.z = vbc.z;
    }
    out->v10c.x = v168.x;
    out->v10c.y = v168.y;
    out->v10c.z = v168.z;
    out->f118 = limit < out->f118 ? limit : out->f118;
}
} // namespace fn_00101270
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00101a30 CHand2HandAgent::vfunc_23 (1452 B): equivalent/0x00101a30.cpp [wrapped: on include/gen/, and its TU merges more functions without the headers]
// sym: ?v23@CHand2HandAgent@fn_00101a30@@UAEXPAUArg1_101a30@2@PAUOut_101a30@2@H@Z @24db106cb9bd @w84f25c2c1abf
namespace fn_00101a30 {
// STATUS: equivalent (tools/equiv.py level 3: 19780 inputs, branch coverage 44/44)
// CHand2HandAgent::vfunc_23 @ 0x00101a30
// checked with equiv.py --time-budget 1200 at 20000 inputs (the default budget stops near 8300)
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


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double sqrt(double);
#endif


struct V3_101a30 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};

struct Name_101a30 {
    void FUN_0027b040(const char *s);
};

struct Rng_101a30 {
    hulk_freg FUN_00078780();
};
Rng_101a30 *FUN_000964d0();

struct Obj58_101a30 {
    char pad0[0x129];
    char b129;
};

struct Pos10_101a30 {
    V3_101a30 v;
};

class P5c_101a30 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3(struct World *hub, struct Arg1_101a30 *a1, V3_101a30 *out, int a3, int z);
    char pad04[0xc];
    V3_101a30 v10;
};

struct Arg1_101a30 {
    char pad0[0x1cbc];
    int f1cbc;
};

struct Hub20_101a30 {
    void FUN_00029250(int a, V3_101a30 *v, int b, int c);
};
struct World {
    char pad0[0x20];
    Hub20_101a30 *p20;
};

float FUN_0010ae50(World *h, Arg1_101a30 *a, float f, V3_101a30 *v1, V3_101a30 *v2, int z1, int z2);

struct Out_101a30 {
    char pad0[0x10c];
    V3_101a30 v10c;
    float f118;
    V3_101a30 v11c;
    V3_101a30 v128;
    char pad134[0x140 - 0x134];
    Name_101a30 name;
    char pad141[7];
    char b148;
};

class CHand2HandAgent {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual char v11(Arg1_101a30 *a, int b, float c);
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual char v18(float f);
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23(Arg1_101a30 *a1, Out_101a30 *out, int a3);
    char pad04[0x58 - 4];
    Obj58_101a30 *p58;
    P5c_101a30 *p5c;
    char pad60[4];
    float f64;
    char pad68[0x78 - 0x68];
    char b78;
    char pad79;
    char b7a;
    char pad7b;
    char b7c;
    char pad7d[3];
    float f80;
    char pad84[4];
    V3_101a30 v88;
    float f94, f98, f9c;
    int pa0;
    char pada4[0xb0 - 0xa4];
    V3_101a30 vB0;
    V3_101a30 vBC;
    int c8;
    char padcc[0xd1 - 0xcc];
    char d1;
    char padd2;
    char d3;
    char padd4[0x128 - 0xd4];
    int i128;
    char pad12c[0x138 - 0x12c];
    V3_101a30 v138;
    char pad144[0x150 - 0x144];
    V3_101a30 v150;
    V3_101a30 v15c;
    V3_101a30 v168;
    V3_101a30 v174;
    char pad180[4];
    V3_101a30 v184;
};

void CHand2HandAgent::v23(Arg1_101a30 *a1, Out_101a30 *out, int a3)
{
    Rng_101a30 *rng = FUN_000964d0();
    v168.z = 0;
    v168.y = 0;
    v168.x = 0;
    v15c.z = 0;
    v15c.y = 0;
    v15c.x = 0;
    b78 = 0;
    out->v11c.x = vBC.x;
    out->v11c.y = vBC.y;
    out->v11c.z = vBC.z;
    out->v128.x = vBC.x;
    out->v128.y = vBC.y;
    out->v128.z = vBC.z;
    if (!d1 && !d3 && f64 > 0.0f && b7a)
        v16();
    v138.z = 0;
    v138.y = 0;
    v138.x = 0;
    float thr = 1.5f;
    if (!p58->b129)
        thr = 0.99f;
    float t = FUN_0010ae50(DAT_004dd700, a1, 1.5f, &v150, &v138, 0, 0);
    if (!(t < 0.0f) && !(t > thr)) {
        p58->b129 = 1;
    } else {
        p58->b129 = 0;
        v138.z = 0;
        v138.y = 0;
        v138.x = 0;
    }
    {
        double lx = (double)DAT_004a1c08 * v138.x;
        volatile float ly = DAT_004a1c08 * v138.y;
        volatile float lz = DAT_004a1c08 * v138.z;
        double m = (double)1.0f - DAT_004a1c08;
        volatile float a0 = (float)(m * v174.x);
        volatile float a1_ = (float)(m * v174.y);
        volatile float a2 = (float)(m * v174.z);
        v174.z = a2 + lz;
        v174.x = (float)(lx + a0);
        v174.y = a1_ + ly;
    }
    v168.z = *(volatile float *)&v174.z + v150.z;
    v168.x = v150.x + *(volatile float *)&v174.x;
    v168.y = *(volatile float *)&v174.y + v150.y;
    p5c->v10.x = v168.x;
    p5c->v10.y = v168.y;
    p5c->v10.z = v168.z;
    p5c->v3(DAT_004dd700, a1, &v15c, a3, 0);
    v168.x = v15c.x + v168.x;
    v168.y = v15c.y + v168.y;
    v168.z = v15c.z + v168.z;
    V3_101a30 W;
    double P0 = (double)vBC.y * 0.0f;
    W.x = (float)(P0 - vBC.z);
    W.y = (float)((double)vBC.z * 0.0f - (double)vBC.x * 0.0f);
    W.z = (float)(vBC.x - P0);
    W.FUN_0022d110();
    double d = W.z * v168.z + W.y * v168.y + W.x * v168.x;
    W.x = (float)(W.x * d);
    W.y = (float)(W.y * d);
    W.z = (float)(W.z * d);
    {
        double lx = W.x * (double)DAT_004a1c0c;
        volatile float by = W.y * DAT_004a1c0c;
        volatile float bz = W.z * DAT_004a1c0c;
        double m = (double)1.0f - DAT_004a1c0c;
        volatile float c0 = (float)(m * v184.x);
        volatile float c1 = (float)(m * v184.y);
        volatile float c2 = (float)(m * v184.z);
        v184.z = c2 + bz;
        v184.x = (float)(lx + c0);
        v184.y = c1 + by;
    }
    v168.x = v184.x;
    v168.y = v184.y;
    v168.z = v184.z;
    volatile float *pv = &v168.x;
    float lz1 = pv[2];
    float ly1 = pv[1];
    float lx1 = pv[0];
    double len = sqrt(lx1 * lx1 + ly1 * ly1 + lz1 * lz1);
    float cap = (float)len;
    if (1.0f < len)
        cap = 1.0f;
    float lz2 = pv[2];
    float ly2 = pv[1];
    float lx2_ = pv[0];
    if (sqrt(lx2_ * lx2_ + ly2 * ly2 + lz2 * lz2) < DAT_004a1c04) {
        v168.x = 0;
        v168.y = 0;
        v168.z = 0;
        out->v10c.z = 0;
        out->v10c.y = 0;
        out->v10c.x = 0;
        out->f118 = 0;
    } else {
        v168.FUN_0022d110();
        out->f118 = cap;
        out->v10c.x = v168.x;
        out->v10c.y = v168.y;
        out->v10c.z = v168.z;
    }
    char d1v = d1;
    float D1 = (vBC.z * f9c + vBC.y * f98) + vBC.x * f94;
    if (!d1v && !d3 && f64 > 0.0f && b7c) {
        int i = i128;
        const char *nm = 0;
        if ((vB0.z * f9c + vB0.y * f98) + vB0.x * f94 < -0.93f) {
            if (i <= 0)
                nm = "taunt";
            else if (rng->FUN_00078780() < 0.5f)
                nm = "taunt";
            else
                nm = "gesture_2";
        } else if (i > 0) {
            nm = "gesture_2";
        }
        if (nm) {
            out->name.FUN_0027b040(nm);
            out->b148 = 1;
            b7c = 0;
            return;
        }
    }
    if (!(*(char*)&DAT_004e0a99) && !d1v && !d3) {
        if (v18(1.5f)) {
            if (v11(a1, c8, D1))
                DAT_004dd700->p20->FUN_00029250(pa0, &v88, a1->f1cbc, 1);
        }
    }
    *(int *)&f80 = *(int *)&(*(float*)&DAT_004a1c00);
}
} // namespace fn_00101a30
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f3aa029d {

// 0x00101fe0 CHand2HandAgent::vfunc_15 (1388 B): equivalent/0x00101fe0.cpp
// sym: ?vfunc_15@CHand2HandAgent@fn_f3aa029d@@UAEDPAUWorld@@PAUCtx@2@@Z @30b10eb35822 @w0effa438134e
// STATUS: equivalent (tools/equiv.py level 3: 20008 inputs, branch coverage 28/28)
// CHand2HandAgent::vfunc_15 @ 0x00101fe0
char CHand2HandAgent::vfunc_15(World *a1, Ctx *a2)
{
    struct Frame {
        char pad0[3];
        char res;
        float L2;
        float Lb;
        float absTmp;
        Vec3_101fe0 C;
        Vec3_101fe0 B;
        Vec3_101fe0 E;
        Vec3_101fe0 A;
        Vec3_101fe0 D;
        Vec3_101fe0 O;
    } f;

    f.res = 1;
    f.A.y = 0.0f;
    f.A.x = vec.x - v88.x;
    f.B.y = 0.0f;
    f.A.z = vec.z - v88.z;
    f.B.x = vec.x - va4.x;
    f.B.z = vec.z - va4.z;
    f.Lb = (float)sqrt(f.B.x * f.B.x + f.B.z * f.B.z);
    f.B.FUN_0022d110();
    f.A.FUN_0022d110();
    hulk_freg t = f11c + 5.0f;
    b60 = 0;
    if (t > f.Lb) {
        hulk_freg v = f.Lb - 2.0f;
        f11c = (1.5f < v) ? v : 1.5f;
        b60 = 1;
    }
    v104.z = 0.0f;
    v104.y = 0.0f;
    v104.x = 0.0f;
    if (f.Lb > f120) {
        volatile float tx = f11c * vf8.x;
        volatile float ty = f11c * vf8.y;
        double z80 = f11c * vf8.z;
        v104.z = (float)(z80 + vec.z);
        v104.x = tx + vec.x;
        v104.y = ty + vec.y;
    } else {
        volatile float bx = f.B.x * f11c;
        volatile float by = f.B.y * f11c;
        double bz = f11c * f.B.z;
        v104.z = (float)(vec.z - bz);
        v104.x = vec.x - bx;
        v104.y = vec.y - by;
    }
    v110.x = v104.x - v88.x;
    v110.y = v104.y - v88.y;
    v110.z = v104.z - v88.z;
    v110.y = 0.0f;
    const volatile Vec3_101fe0 &r110 = v110;
    f.L2 = (float)sqrt(r110.x * r110.x + r110.y * r110.y + r110.z * r110.z);
    v110.FUN_0022d110();
    f.C.y = 0.0f;
    f.C.x = v104.x - vec.x;
    f.C.z = v104.z - vec.z;
    f.C.FUN_0022d110();
    f.E.x = f.C.z;
    f.E.z = -f.C.x;
    f.D.y = 0.0f;
    f.D.x = v104.x - va4.x;
    f.D.z = v104.z - va4.z;
    f.D.FUN_0022d110();
    FloatBits_101fe0 dp;
    dp.f = f.E.z * v110.z + f.E.x * v110.x + v110.y * 0.0f;
    dp.u &= 0x7fffffff;
    Vec3_101fe0 *edi;
    if (dp.f < 0.97 && f.L2 > 2.0f) {
        edi = &v144;
        v144 = v110;
        f180 = f.L2;
        FUN_0010ae50(a1, a2, 1.875f, edi, &f.O, 0, 0);
        if (f.L2 > 5.0f) {
            v144 = v110;
            f180 = f.L2;
        }
        f.E.x = 0.0f;
        f.E.y = 0.0f;
        f.E.z = 0.0f;
        if (v144.FUN_0022d2b0(&f.E, 1e-05f)) {
            if (f.C.z * v110.z + f.C.y * v110.y + f.C.x * v110.x > 0.0f) {
                v144 = f.C;
            } else {
                v144.z = -f.C.z;
                v144.x = -f.C.x;
                v144.y = -f.C.y;
            }
            f180 = -1.0f;
            FUN_0010ae50(a1, a2, 1.875f, edi, &f.O, 0, 0);
        }
    } else {
        FloatBits_101fe0 d3;
        d3.f = f.A.z * f.C.z + f.A.x * f.C.x + f.C.y * f.A.y;
        d3.u &= 0x7fffffff;
        if (d3.f < 0.97f) {
            hulk_freg dot4 = f.E.z * v110.z + v110.y * 0.0f + f.E.x * v110.x;
            v144.y = 0.0f;
            if (dot4 > 0.0f) {
                v144.x = f.E.x;
                v144.z = f.E.z;
            } else {
                v144.x = -f.E.x;
                v144.z = -f.E.z;
            }
            f180 = -1.0f;
        }
        edi = &v144;
        FUN_0010ae50(a1, a2, 1.9499999f, edi, &f.O, 0, 0);
    }
    if (b60 != 0) {
        vd4 = vdc;
        edi->x = 0.0f;
        edi->y = 0.0f;
        edi->z = 0.0f;
        f.res = 0;
    } else if (f.Lb < f120 && fc8 < fe8 && f64 < 0.0f) {
        vd4 = vdc;
        edi->x = 0.0f;
        edi->y = 0.0f;
        edi->z = 0.0f;
        f.res = 0;
    }
    v144.y = 0.0f;
    edi->FUN_0022d110();
    return f.res;
}

} // namespace fn_f3aa029d
