// cl-flags: /GS
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001eab10..0x001eecb0 (kind game, layer game, confidence high), dominant class CSoundRealTimeManager
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/engine/content.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/unknown.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f7674384 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f7674384 {} using namespace fn_f7674384;
#include "game/global.h"

// ---- declarations shared by the functions below
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int sprintf(char *buf, const char *fmt, ...);
#endif
namespace fn_f7674384 {
namespace core {
struct IRefCount_1eab10 {
    virtual void r0();
    virtual void r1();
    virtual void r2();
};
}
struct Pair_1eab10 {
    int a, b;
};
namespace audio {
class Sequence_1eab10 : public core::IRefCount_1eab10 {
public:
    Pair_1eab10 *FUN_00243390();
};
}
namespace audio {
class Mix_1eab10 : public core::IRefCount_1eab10 {
public:
    Pair_1eab10 *FUN_00243390();
};
}
namespace audio {
class Mixer_1eab10 : public core::IRefCount_1eab10 {
};
}
namespace audio {
class ListenerEffectXBox_1eab10 : public core::IRefCount_1eab10 {
public:
    Pair_1eab10 *FUN_00243390();
};
}
struct Handle_1eab10 {
    char FUN_00266750();
    struct Group_1eab10 *FUN_00266700();
    void FUN_00263e90();
};
struct Cursor_1eab10 {
    unsigned int a;
    int b;
    struct Group_1eab10 *c;
    void FUN_002314a0(unsigned int v);
    core::IRefCount_1eab10 *FUN_00231640();
    core::IRefCount_1eab10 *FUN_002314c0();
};
struct Group_1eab10 {
    char pad0[0xc];
    unsigned int f0c;
};
struct Loader_1eab10 {
    void FUN_00265920(const char *path, Handle_1eab10 **out, int flag);
    int FUN_00264870();
};
struct Flags_1eab10 {
    bool FUN_00092de0(int id);
};
} // namespace fn_f7674384
struct Singleton_4dd6ec {
};
namespace fn_f7674384 {
struct Item_1eab10 {
    void FUN_000bd1b0(int v);
};
struct Scene_1eab10 {
    Item_1eab10 *FUN_00086280();
};
} // namespace fn_f7674384
struct World {
    char pad0[0x54];
    Scene_1eab10 *scene;           // 0x54
};
namespace fn_f7674384 {
struct Track {
    char pad0[0x10];
    int f10;
    int f14;
    void FUN_001ea6b0(audio::Sequence_1eab10 *s, int v);
    void FUN_001e9bf0();
};
struct Voice_1eab10 {
    char pad0[8];
    audio::Mix_1eab10 *mix;        // 0x8
    int fc;                 // 0xc
};
struct Sink_1eab10 {
    virtual void k0(); virtual void k1(); virtual void k2(); virtual void k3();
    virtual void k4(int a, int b, core::IRefCount_1eab10 *e);
};
extern "C" void *FUN_00240750();
extern int __cdecl FUN_00242c30(void *mgr, hulk_intptr v);
extern "C" bool __cdecl FUN_001e9bc0(Pair_1eab10 p);
class Player_1eab10 {
public:
    char pad0[0x518];
    Sink_1eab10 *sink;             // 0x518
    int FUN_001e98b0(Pair_1eab10 *p);
    Track *FUN_001e97f0();
    Voice_1eab10 *FUN_001e8960();
    void FUN_001eab10(const char *name);
};
struct ScriptLoader {
    void FUN_001eef90(const char* path);
};
} // namespace fn_f7674384
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void *__cdecl memcpy(void *dst, const void *src, unsigned int n);
#endif
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void *__cdecl memset(void *dst, int c, unsigned int n);
#endif
namespace fn_f7674384 {
static inline int strcmp_inline(const char *a, const char *b)
{
    while (*a && *a == *b) {
        a++;
        b++;
    }
    return (unsigned char)*a - (unsigned char)*b;
}
static inline char *strcpy_inline(char *d, const char *s)
{
    char *r = d;
    while ((*d++ = *s++) != 0)
        ;
    return r;
}
struct Query_1ec100 {
    char data[0x44];
    void FUN_001ef370(const char *name);
};
struct Vec3_1ec100 { float x, y, z; };
struct Entity {
    char pad0[8];
    Vec3_1ec100 pos;                // 0x8
    char pad1[0x11c - 0x14];
    struct Info_1ec100 *info;       // 0x11c
};
struct Info_1ec100 {
    const char *FUN_000443b0();
    long long FUN_000443c0();
};
struct Flags_1ec100 {
    bool FUN_00092de0(int v);
};
struct Logic_1ec100 {
    bool FUN_00027fc0(const char *a, const char *b);
};
struct Env_1ec100 {
    char pad[0x20];
    Logic_1ec100 *logic;            // 0x20
};
struct Lookup_1ec100 {
};
struct Spawner_1ec100 {
    void FUN_001efe20(Query_1ec100 *q, Vec3_1ec100 *pos, const char *name, float radius);
};
struct SpawnGlobals_1ec100 {
    Spawner_1ec100 *spawner;        // 0x0
    char pad[4];
    char enabled;            // 0x8
};
extern "C" void FUN_001eb440(void *target, Query_1ec100 *q);
class Handler_1ec100 {
public:
    Env_1ec100 *env;                // 0x0
    Lookup_1ec100 *lookup;          // 0x4
    void FUN_001ec100(Entity *entity, const char *name);
};
struct Frame_1ec100 {
    int spill;
    Query_1ec100 q;
    int gap;
    char buf[0x40];
};
struct Item_1ec310 { unsigned int FUN_0008a2d0(); unsigned int FUN_000897f0(); };
struct Source_1ec310 {  };
struct Sink_1ec310 {  };
struct Handler_1ec310 {  };
struct Owner_1ec310 { Handler_1ec310* handler; Sink_1ec310* sink; void FUN_001efa40(int, unsigned int, unsigned int); };
struct Target_1ec310 { Owner_1ec310* owner; Source_1ec310* source; unsigned char enabled; char padding[3]; float value; void FUN_001ec310(unsigned int); };
struct Detail_1eca40 { char pad[0x14]; int type; };
struct Object { char pad[0x11c]; Detail_1eca40* detail; };
struct Controller_1eca40 { void FUN_001ec980(Object*, const char*); void FUN_001eca40(Object*,Object*,const char*); };
struct ImpactInfo { char pad[0x14]; int type; };
struct Source_1ecb60 { char pad[0x11c]; ImpactInfo* info; };
struct State_1ecb60 { int FUN_001d5040(); };
struct Recipient_1ecb60 { char pad[0xec]; State_1ecb60* state; };
struct Effects_1ecb60 {
 void FUN_001ec980(Source_1ecb60*, const char*);
 void FUN_001ebd80(Recipient_1ecb60*, const char*, float, int);
 void FUN_001ecb60(Source_1ecb60*, Recipient_1ecb60*, const char*);
};
struct V3_1ed0b0 {
    float x, y, z;
};
struct Anim_1ed0b0 {
    __int64 FUN_000443c0();
};
struct BoneEntry_1ed0b0 {
    char pad0[0x30];
    V3_1ed0b0 pos;                 // 0x30
    char pad3c[0x40 - 0x3c];
};
struct Skeleton {
    char pad0[0x1c];
    BoneEntry_1ed0b0 *bones;       // 0x1c
    int FUN_002843a0(__int64 hash);
};
struct Actor_1ed0b0 {
    char pad0[0x11c];
    Anim_1ed0b0 *anim;             // 0x11c
    Skeleton *skel;         // 0x120
    char pad124[0x1a64 - 0x124];
    float groundY;          // 0x1a64
    char pad1a68[0x1aa8 - 0x1a68];
    int leftDown;           // 0x1aa8
    int rightDown;          // 0x1aac
    void FUN_00035660(V3_1ed0b0 *out);
};
struct Frame_1ed0b0 {
    float scale;            // 0x00
    void *self;             // 0x04
    V3_1ed0b0 vel;                 // 0x08
    V3_1ed0b0 foot;                // 0x14
    float ground;           // 0x20
    float groundCopy;       // 0x24
    char buf[16];           // 0x28
};
class Footsteps {
public:
    void FUN_001ec980(Actor_1ed0b0 *a, char *name);
    void FUN_001ed0b0(Actor_1ed0b0 *a);
};


// 0x001eab10 FUN_001eab10 (733 B): equivalent/0x001eab10.cpp
// sym: ?FUN_001eab10@Player_1eab10@fn_f7674384@@QAEXPBD@Z @d2db7f64b4fb @w7ce27daf4d08
// STATUS: equivalent (tools/equiv.py level 3: 128 inputs, branch coverage 24/24)
// FUN_001eab10 @ 0x001eab10
void Player_1eab10::FUN_001eab10(const char *name)
{
    char buf[0x80];
    Handle_1eab10 *h = 0;
    for (int i = 0; i < 0x80; i++)
        buf[i] = 0;
    sprintf(buf, "sound\\%s", name);
    (*(Loader_1eab10**)&DAT_00527c58)->FUN_00265920(buf, &h, 1);
    int saved = (*(Loader_1eab10**)&DAT_00527c58)->FUN_00264870();
    ((owners::C_264860 *)((*(Loader_1eab10**)&DAT_00527c58)))->FUN_00264860(250000);
    while (!h->FUN_00266750()) {
        FUN_00087990();
        DAT_004dd700->scene->FUN_00086280()->FUN_000bd1b0(0);
    }
    ((owners::C_264860 *)((*(Loader_1eab10**)&DAT_00527c58)))->FUN_00264860(saved);
    if (h->FUN_00266700() != 0) {
        ((owners::A_266090 *)(h->FUN_00266700()))->FUN_00266090();
        Group_1eab10 *g = h->FUN_00266700();
        Cursor_1eab10 it;
        it.FUN_002314a0(g->f0c);
        it.c = g;
        core::IRefCount_1eab10 *e = it.FUN_00231640();
        while (e != 0) {
            audio::Sequence_1eab10 *seq = 0;
            audio::Mix_1eab10 *mix = 0;
            audio::ListenerEffectXBox_1eab10 *fx = 0;
            if (dynamic_cast<audio::Sequence_1eab10 *>(e)) {
                seq = dynamic_cast<audio::Sequence_1eab10 *>(e);
                Pair_1eab10 *pr = seq->FUN_00243390();
                Pair_1eab10 p;
                int ca = pr->a;
                p.a = ca;
                p.b = pr->b;
                if (FUN_001e98b0(&p) == 0) {
                    bool skip = false;
                    if (!((Flags_1eab10 *)((owners::A_86340 *)DAT_004dd6ec)->FUN_00086340())->FUN_00092de0(2)) {
                        Pair_1eab10 arg;
                        arg.a = ca;
                        arg.b = p.b;
                        if (FUN_001e9bc0(arg))
                            skip = true;
                    }
                    if (!skip) {
                        Track *t = FUN_001e97f0();
                        t->f14 = p.b;
                        t->f10 = p.a;
                        t->FUN_001ea6b0(seq, 0);
                        t->FUN_001e9bf0();
                        Pair_1eab10 *q = seq->FUN_00243390();
                        sink->k4(q->a, q->b, e);
                    }
                }
            } else if (dynamic_cast<audio::Mix_1eab10 *>(e)) {
                mix = dynamic_cast<audio::Mix_1eab10 *>(e);
                Voice_1eab10 *v = FUN_001e8960();
                v->mix = mix;
                void *mgr = FUN_00240750();
                v->fc = FUN_00242c30(mgr, (hulk_intptr)v->mix);
                Pair_1eab10 *q = mix->FUN_00243390();
                sink->k4(q->a, q->b, e);
            } else if (dynamic_cast<audio::Mixer_1eab10 *>(e)) {
                dynamic_cast<audio::Mixer_1eab10 *>(e);
            } else if (dynamic_cast<audio::ListenerEffectXBox_1eab10 *>(e)) {
                fx = dynamic_cast<audio::ListenerEffectXBox_1eab10 *>(e);
                Pair_1eab10 *q = fx->FUN_00243390();
                sink->k4(q->a, q->b, e);
            }
            e = it.FUN_002314c0();
        }
        h->FUN_00263e90();
    }
}

} // namespace fn_f7674384

// 0x001eb060 FUN_001eb060 (192 B): matches/0x001eb060.cpp
// sym: ?FUN_001eb060@Manager_1eb060@owners@@QAEXPBD0@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_001eb060 @ 0x001eb060
void owners::Manager_1eb060::FUN_001eb060(const char *first, const char *second) {
 char firstPath[32];
 char secondPath[32];
 (*(int*)&DAT_004e36ac) = 0;
 if (DAT_0049caa0 && !loaded) {
  if (!second) {
   FUN_001eab10("scripts\\frontend.p3d");
  } else {
   FUN_001eab10("scripts\\common.p3d");
   sprintf(firstPath, "scripts\\%s.p3d", first);
   FUN_001eab10(firstPath);
   sprintf(secondPath, "scripts\\%s.p3d", second);
   FUN_001eab10(secondPath);
  }
  loaded = 1;
 }
 mainMix = FUN_001e9960("main_mix");
 FUN_001e9a90("main_mix", 0);
}

namespace fn_f7674384 {

// 0x001eb2d0 FUN_001eb2d0 (357 B): equivalent/0x001eb2d0.cpp
// sym: ?FUN_001eb2d0@fn_f7674384@@YAXPBDPAUScriptLoader@1@@Z @51ede656f4b3 @w357ea0491c47
// STATUS: equivalent (tools/equiv.py level 3: 89 inputs, branch coverage 11/12, incomplete)
// FUN_001eb2d0 @ 0x001eb2d0
// Builds "sound\scripts\<xxx><yyy>.lua" from two 3-character fields of name.
void FUN_001eb2d0(const char* name, ScriptLoader* loader)
{
    struct {
        char field1[4];
        char path[0x20];
    } f;
    char field2[4];
    f.field1[0] = 0;
    f.field1[1] = 0;
    f.field1[2] = 0;
    f.field1[3] = 0;
    strncat(f.field1, name, 3);
    atol(f.field1 + 1);
    field2[0] = 0;
    field2[1] = 0;
    field2[2] = 0;
    field2[3] = 0;
    strncat(field2, name + 3, 3);
    atol(field2 + 1);
    for (int i = 0; i < 0x20; i++)
        f.path[i] = 0;
    strcat(f.path, "sound\\scripts\\");
    strcat(f.path, f.field1);
    strcat(f.path, field2);
    strcat(f.path, ".lua");
    loader->FUN_001eef90(f.path);
}

} // namespace fn_f7674384

// 0x001ebea0 FUN_001ebea0 (162 B): equivalent/0x001ebea0.cpp
// sym: ?FUN_001ebea0@Crusher_1ebea0@owners@@QAEXPBDH@Z @c77d4cf2a121 @w51afdf40c27f
// STATUS: equivalent (tools/equiv.py level 3: 16329 inputs, branch coverage 6/6)
// FUN_001ebea0 @ 0x001ebea0
// equiv-map: ___security_cookie = 0x004d9968
void owners::Crusher_1ebea0::FUN_001ebea0(const char *suffix, hulk_intptr arg2)
{
    struct Frame {
        char name[0x46];
    } fr = { "crush_" };
    if (suffix != 0) {
        strcat(fr.name, suffix);
        FUN_001ebd80(((int)arg2), fr.name, 100.0f, 0);
    }
}

namespace fn_f7674384 {

// 0x001ebf50 FUN_001ebf50 (124 B): matches/0x001ebf50.cpp
// sym: ?FUN_001ebf50@fn_f7674384@@YGXPBDH@Z
// STATUS: equivalent (tools/equiv.py level 3: 2795 inputs, branch coverage 6/6)
// FUN_001ebf50 @ 0x001ebf50
// FUN_001ebf50 @ 0x001ebf50
// Builds the debug name "crush_<name>" in a local buffer (the result is never used).
// The /GS cookie sits directly above the buffer, as in the original.
void __stdcall FUN_001ebf50(const char *name, int unused) {
    struct Frame {
        char buf[70];
        char pad[2];
    } f;
    if (name != 0) {
        memcpy(f.buf, "crush_", 7);
        memset(f.buf + 7, 0, 63);
        strcat(f.buf, name);
    }
}


// 0x001ec100 FUN_001ec100 (391 B): equivalent/0x001ec100.cpp
// sym: ?FUN_001ec100@Handler_1ec100@fn_f7674384@@QAEXPAUEntity@2@PBD@Z @f1ef534ef8e4 @w197b2412d71d
// STATUS: equivalent (tools/equiv.py level 3: 19662 inputs, branch coverage 20/20)
// FUN_001ec100 @ 0x001ec100
void Handler_1ec100::FUN_001ec100(Entity *entity, const char *name)
{
    Frame_1ec100 f;
    if (entity != 0 && entity->info != 0) {
        int i;
        for (i = 0; i < 0x40; i++) f.buf[i] = 0;
        bool flag = ((Flags_1ec100 *)((owners::A_86340 *)DAT_004dd6ec)->FUN_00086340())->FUN_00092de0(2);
        long long id = entity->info->FUN_000443c0();
        if ((int)(__int64)id == (*(int*)&DAT_004dc0e0) && (int)(__int64)(id >> 32) == (*(int*)((char*)&DAT_004dc0e0 + 4))) {
            if (!flag) {
                return;
            }
            strcpy_inline(f.buf, "joefixit");
        } else {
            strcpy_inline(f.buf, entity->info->FUN_000443b0());
        }
        if (strcmp_inline(name, "spawn") == 0) {
            if (env->logic->FUN_00027fc0("hulk", "//hulk/opening/holding/stealth_truck")) {
                return;
            }
        }
        ((Query_1ec100 *)((owners::Obj_1ef320 *)&(f.q))->FUN_001ef320());
        f.q.FUN_001ef370("Objects");
        f.q.FUN_001ef370("Dialogue");
        f.q.FUN_001ef370(f.buf);
        void *target = ((void *)((owners::C_86310 *)lookup)->FUN_00086310());
        if (target != 0)
            FUN_001eb440(target, &f.q);
        if ((*(SpawnGlobals_1ec100**)&DAT_004e36d8)->enabled)
            (*(SpawnGlobals_1ec100**)&DAT_004e36d8)->spawner->FUN_001efe20(&f.q, &entity->pos, name, 100.0f);
        ((owners::C_1ef350 *)&(f.q))->FUN_001ef350();
    }
}


// 0x001ec310 FUN_001ec310 (178 B): equivalent/0x001ec310.cpp
// sym: ?FUN_001ec310@Target_1ec310@fn_f7674384@@QAEXI@Z @36fbe05246ba @wca5372b8c93f
// STATUS: equivalent (tools/equiv.py level 3: 3006 inputs, branch coverage 8/8)
// FUN_001ec310 @ 0x001ec310
void Target_1ec310::FUN_001ec310(unsigned int) {
 char gs_unused[16]; /* dead stack buffer: MSVC /GS protects only functions with a char array */
 if (!(*(unsigned char*)&DAT_004e36e0) && enabled) {
  Item_1ec310* item = ((Item_1ec310 *)((owners::C_86310 *)source)->FUN_00086310());
  Sink_1ec310* sink = owner->sink;
  unsigned int a = item->FUN_0008a2d0();
  unsigned int b = item->FUN_000897f0();
  ((owners::Manager_1eb060 *)sink)->FUN_001eb060((const char *)(hulk_uintptr)(unsigned int)b, (const char *)(hulk_uintptr)(unsigned int)a);
  a = item->FUN_0008a2d0();
  b = item->FUN_000897f0();
  owner->FUN_001efa40(1,b,a);
  float v = value;
  if (!(v < 0.0f) && !(v > 100.0f)) ((owners::Obj_1f3950 *)(owner->handler))->FUN_001f3950(v);
  (*(unsigned char*)&DAT_004e36e0) = 1;
 }
}


// 0x001eca40 FUN_001eca40 (288 B): equivalent/0x001eca40.cpp
// sym: ?FUN_001eca40@Controller_1eca40@fn_f7674384@@QAEXPAUObject@2@0PBD@Z @3a74fed892e5 @wec201d533323
// STATUS: equivalent (tools/equiv.py level 3: 20014 inputs, branch coverage 16/16)
// FUN_001eca40 @ 0x001eca40
void Controller_1eca40::FUN_001eca40(Object* first, Object* second, const char* sound) {
 if (first && first->detail && second && second->detail) {
 FUN_001ec980(first,sound);
 char selected[16] = {0};
 int type = first->detail->type;
 const char* source;
 if (type != 1 && type != 2) source = "impact_sml";
 else {
 const char* match="whiff";
 int i;
 for(i=0;i<6;++i) if(sound[i]!=match[i]) break;
 source = i==6 ? sound : "impact_big";
 }
 int i=0;
 do { selected[i]=source[i]; } while(source[i++] != 0);
 FUN_001ec980(second,selected);
 }
}


// 0x001ecb60 FUN_001ecb60 (286 B): equivalent/0x001ecb60.cpp
// sym: ?FUN_001ecb60@Effects_1ecb60@fn_f7674384@@QAEXPAUSource_1ecb60@2@PAURecipient_1ecb60@2@PBD@Z @5c76fece0b68 @wda8bf319ce47
// STATUS: equivalent (tools/equiv.py level 3: 20008 inputs, branch coverage 18/18)
// FUN_001ecb60 @ 0x001ecb60
void Effects_1ecb60::FUN_001ecb60(Source_1ecb60* source, Recipient_1ecb60* recipient, const char* name) {
 if (source && source->info && recipient && recipient->state && recipient->state->FUN_001d5040()) {
 FUN_001ec980(source, name);
 char buffer[16];
 const char* chosen = "impact_sml";
 if (source->info->type == 2 || source->info->type == 1) {
  const char* whiff = "whiff";
  int i;
  for (i=0; i<6; ++i) if (name[i] != whiff[i]) break;
  chosen = i == 6 ? name : "impact_big";
 }
 int j=0;
 do { buffer[j] = chosen[j]; } while (chosen[j++]);
 FUN_001ebd80(recipient, buffer, 100.0f, 0);
 }
}

} // namespace fn_f7674384

// 0x001ecd00 FUN_001ecd00 (155 B): equivalent/0x001ecd00.cpp
// sym: ?FUN_001ecd00@Crusher_1ecd00@owners@@QAEXPBDH@Z @caf8284aa7bb @w18462f7d2f83
// STATUS: equivalent (tools/equiv.py level 3: 16479 inputs, branch coverage 6/6)
// FUN_001ecd00 @ 0x001ecd00
// equiv-map: ___security_cookie = 0x004d9968
// FUN_001ecd00: build "crush_<name>" and hand it to FUN_001ec980
void owners::Crusher_1ecd00::FUN_001ecd00(const char *name, hulk_intptr a)
{
    struct Frame {
        char buf[70];
        char pad[2];
    } f = { "crush_" };
    if (name != 0) {
        strcat(f.buf, name);
        FUN_001ec980(((int)a), f.buf);
    }
}

namespace fn_f7674384 {

// 0x001ed0b0 FUN_001ed0b0 (613 B): equivalent/0x001ed0b0.cpp
// sym: ?FUN_001ed0b0@Footsteps@fn_f7674384@@QAEXPAUActor_1ed0b0@2@@Z @81b155f9b3c2 @w47dc0e7a085f
// STATUS: equivalent (tools/equiv.py level 3: 20012 inputs, branch coverage 34/34)
// FUN_001ed0b0 @ 0x001ed0b0
void Footsteps::FUN_001ed0b0(Actor_1ed0b0 *a)
{
    Frame_1ed0b0 f;
    f.self = this;
    f.scale = 2.0f;
    __int64 id = a->anim->FUN_000443c0();
    if (id == DAT_004dc068) {
        f.scale = 15.0f;
    } else if (a->anim->FUN_000443c0() == DAT_004dc0a8) {
        f.scale = 7.5f;
    } else if (a->anim->FUN_000443c0() == DAT_004dc0c8) {
        f.scale = 5.0f;
    }

    Skeleton *skel = a->skel;
    BoneEntry_1ed0b0 *e = &skel->bones[skel->FUN_002843a0(FUN_002672f0("Ball_L", 0, 0))];
    f.foot.x = e->pos.x;
    f.foot.y = e->pos.y - a->groundY;
    f.foot.z = e->pos.z;
    f.groundCopy = a->groundY;
    f.buf[0] = 's';
    f.buf[1] = 't';
    f.buf[2] = 'e';
    f.buf[3] = 'p';
    f.buf[4] = '_';
    f.buf[5] = 0;
    for (int i = 6; i < 16; i++)
        f.buf[i] = 0;
    a->FUN_00035660(&f.vel);
    double len = sqrt(f.vel.z * f.vel.z + f.vel.y * f.vel.y + f.vel.x * f.vel.x);
    if (len < 5.0f) {
        strcat(f.buf, "slow");
    } else if (len < 12.0f) {
        strcat(f.buf, "mid");
    } else {
        strcat(f.buf, "fast");
    }
    hulk_freg thr = f.scale * 0.1f;
    if (a->leftDown == 0) {
        if (f.foot.y < thr) {
            a->leftDown = 1;
            FUN_001ec980(a, f.buf);
        }
    } else if (f.foot.y > thr) {
        a->leftDown = 0;
    }

    hulk_freg ry = skel->bones[skel->FUN_002843a0(FUN_002672f0("Ball_R", 0, 0))].pos.y - f.groundCopy;
    if (a->rightDown == 0) {
        if (ry < thr) {
            a->rightDown = 1;
            FUN_001ec980(a, f.buf);
        }
    } else if (ry > thr) {
        a->rightDown = 0;
    }
}

} // namespace fn_f7674384
