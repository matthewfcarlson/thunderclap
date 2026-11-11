// cl-flags: /GS
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001f9530..0x001fa960 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/unknown.h"
#define TREE_TU_BEGIN namespace fn_f326376d {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f326376d {} using namespace fn_f326376d;
#include "game/unknown.h"

// ---- declarations shared by the functions below
namespace fn_f326376d {
struct Msg_1fa1c0 {
    int size;                 // 0x00
    int kind;                 // 0x04
    int pad08[3];
    char text[0x20];          // 0x14
    char text2[0x20];         // 0x34
    Msg_1fa1c0 *FUN_001ca020(const char *a, const char *b);
};
class Selector_1fa1c0 {
public:
    int FUN_001d2b10(int a, int b);
    bool FUN_001d1930(int v);
    void FUN_001d1a50(const char *v);
    void FUN_001d1ac0(float v);
    void FUN_001d19d0(int v);
    bool FUN_001d1ae0(unsigned char *out);
};
struct Queue_1fa1c0 {
    bool FUN_001cbc20(Msg_1fa1c0 *m);
};
} // namespace fn_f326376d
struct World {
    char pad00[0x30];
    Queue_1fa1c0 *queue;             // 0x30
};
namespace fn_f326376d {
Selector_1fa1c0 *FUN_001d4c90();
struct Item_1fa1c0 {
    const char *FUN_001fba60();
};
struct Target_1fa1c0 {
    char pad00[0x10];
    int *data;                // 0x10
};
struct Panel_1fa1c0;
struct Copyable {
    char pad00[9];
    unsigned char index;      // 0x09
    char pad0a[6];
    void FUN_001f8940(const Copyable *src);
    Copyable(const Copyable &o) { FUN_001f8940(&o); }
};
struct Slot_1fa1c0 {
    char pad00[0x30];
    Copyable value;           // 0x30
    char pad40[0x51 - 0x40];
    unsigned char flag51;     // 0x51
    char pad52[6];
    void FUN_001f9230();
    void FUN_001f9710(Panel_1fa1c0 *owner, const char *name, int a, int b);
};
struct Entry_1fa1c0 {
    unsigned char active;
    char pad01[0x27];
};
class Panel_1fa1c0 {
public:
    char pad000[0x41c];
    char label[0x20];         // 0x41c
    int f43c;
    char pad440[0x44c - 0x440];
    int f44c;
    char pad450[0x484 - 0x450];
    Entry_1fa1c0 entries[15];        // 0x484
    char pad6dc[4];
    int entryCount;           // 0x6e0
    char pad6e4[4];
    Slot_1fa1c0 slots[16];           // 0x6e8
    int count;                // 0xc68

    void FUN_001f9fc0(Copyable value);
    void FUN_001fa1c0(Target_1fa1c0 *target, Item_1fa1c0 *item);
};

} // namespace fn_f326376d

// 0x001f9810 FUN_001f9810 (1814 B): equivalent/0x001f9810.cpp [wrapped: macros]
// sym: ?FUN_001f9810@Self@fn_001f9810@@QAEXM@Z
namespace fn_001f9810 {
// STATUS: equivalent (tools/equiv.py level 3: 3138 inputs, branch coverage 84/94, incomplete)
// FUN_001f9810 @ 0x001f9810
// cl-flags: /GS
// equiv-map: ___security_cookie = 0x004d9968

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
extern "C" int memcmp(const void *a, const void *b, unsigned int n);
#endif

#pragma intrinsic(memcmp)
#if defined(__clang__)
static inline int hulk_memcmp(const void *pa, const void *pb, unsigned int n) { const unsigned char *a = (const unsigned char *)pa, *b = (const unsigned char *)pb; for (; n; --n, ++a, ++b) if (*a != *b) return *a < *b ? -1 : 1; return 0; }
#define memcmp hulk_memcmp
#endif

struct V3 {
    float x, y, z;
    hulk_freg FUN_00018990();
};

struct Name {
    char d[8];
    void FUN_0027b0e0(const char *s);
    void FUN_0027af50();
};

struct Key {
    char name[8];
    unsigned char b8;
    unsigned char idx;               // this+0x39
    char pad_a[6];
    Key(const Key &o);
};

struct NameObj {
    char *FUN_00044400();
    char *FUN_00044360();
};

struct Obj {
    virtual void o0(); virtual void o1(); virtual void o2(); virtual void o3();
    virtual void o4(); virtual void o5(); virtual void o6(); virtual void o7();
    virtual void v8(V3 *out);
    virtual float v9();
    char pad_o[0xc - 4];
    char name[4];
    hulk_intptr FUN_001fba60();
};

struct Finder {
    Obj *FUN_001fc8c0(u64 id);
};

struct Inst {
    char FUN_001d1cb0();
    char FUN_001d2ba0(const char *s, int a, int b);
    void FUN_001d1d50(const char *key, const void *v);
    void FUN_001d19d0(int a);
    void FUN_001d1d30();
    char FUN_001d1930(int a);
    void FUN_001d2b10(int a, int b);
};

struct Actor {
    char pad0[0x1d7c];
    int f1d7c;
    void FUN_00037180(V3 v);
    void FUN_000371b0(int a);
    void FUN_0003ec70(void *p);
    void FUN_00037160(int a);
    void FUN_00037170(int a);
};

struct Q1 {
    char d[0x58];
    void FUN_001ca000(const char *a, const char *b);
};

struct Spawner {
    void FUN_001cbc20(Q1 *q);
};

struct ZObj {
    char pad;
};

struct Entry {
    NameObj *obj;                    // 0
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    char pad24[4];
    char FUN_001f8aa0(ZObj *z, Obj *r);
};

struct Cfg {
    char pad0[0x41c];
    char name[12];                   // 0x41c
    char pad428[0x448 - 0x428];
    int f448;
    char pad44c[0x454 - 0x44c];
    int f454;
    char pad458[0x460 - 0x458];
    Entry entries[1];                // 0x460
    char pad_tail[0x6e0 - 0x460 - 0x28];
    int count;                       // 0x6e0
    short FUN_001f9630(Key o);
    void FUN_001f9670(Key o, short s);
};

struct Zone {
    char FUN_00099d60(float x, float y, float z, float w, int a);
};

struct Fighter {
    int FUN_00024b00(void *p);
    Actor *FUN_00024280(u64 id);
    char FUN_0002bf80(const char *nm, V3 v, float rr, const char *name, const char *none, int z, char *buf);
    Actor *FUN_000259f0(char *buf);
};

struct Y {
    ZObj *FUN_00059a30();
    char FUN_00059a50(V3 *out);
};

struct X {
    Y *FUN_00059ba0(int id);
};

struct World {
    char pad0[8];
    Zone *f8;
    char pad0c[0x20 - 0xc];
    Fighter *f20;
    char pad24[0x28 - 0x24];
    Finder *f28;
    char pad2c[0x30 - 0x2c];
    Spawner *f30;
    char pad34[0x44 - 0x34];
    X *f44;
};
   // tvm_SetSpawnDistanceOffCamera (FUN_001fd4c0), 20 at load
   // tvm_SetSpawnDistanceOnCamera (FUN_001fd4d0), 70 at load

struct Hold2 {
    int FUN_001c59d0(Name *n);
};
struct HolderObj {
    char pad0[0xc];
    Hold2 *f0c;
};
HolderObj *__cdecl FUN_001c3d90();
Inst *__cdecl FUN_001d4c90();
void __cdecl FUN_00267760(char *buf, int n, const char *fmt, ...);
void __cdecl FUN_00224d70(float a, V3 *v);
hulk_freg __cdecl FUN_0004af40(float a, float b, float c);

class Self;

union FS {
    int i;
    float f;
};

struct Frame {
    unsigned char pad0c[3];
    unsigned char strike;            // S'+0x0f
    FS s10;                          // 0x10
    Self *self;                      // 0x14
    int s;                           // 0x18
    int off;                         // 0x1c
    int n;                           // 0x20
    int i;                           // 0x24
    Obj *r2;                         // 0x28
    V3 tmp;                          // 0x2c
    Fighter *W;                      // 0x38
    Obj *R;                          // 0x3c
    V3 v40;                          // 0x40
    V3 pos;                          // 0x4c
    ZObj *Zp;                        // 0x58
    float rr;                        // 0x5c
    Name nm;                         // 0x60
    V3 v68;                          // 0x68
    V3 d;                            // 0x74
    char buf2[256];                  // 0x80
    Q1 q;                            // 0x180
    char buf1[256];                  // 0x1d8
    int pad2d8;
};

class Self {
public:
    char pad0[8];
    Cfg *f8;
    char name[0x30 - 0xc];           // 0xc
    Key key;                         // 0x30
    int f40;
    float f44;
    float f48;
    float f4c;
    unsigned char b50;
    unsigned char b51;
    short f52;

    Obj *FUN_001f8b40(int a, Obj *r, V3 pos);
    void FUN_001f9810(float dt);
};

void Self::FUN_001f9810(float dt)
{
    Frame f;
    f48 = dt + f48;
    f.self = this;
    do {
        if (b50 != 0)
            break;
        if (b51 == 0)
            break;
        float t = f4c - dt;
        f4c = t;
        f.W = DAT_004dd700->f20;
        if (f8 == 0)
            break;
        if (!(t <= 0.0f))
            break;
        f4c = f44;
        Y *y = DAT_004dd700->f44->FUN_00059ba0(f40);
        f.Zp = y->FUN_00059a30();
        if (f.Zp == 0)
            break;
        if (y == 0)
            break;
        if (!y->FUN_00059a50(&f.pos))
            break;
        u64 id = FUN_0027b020(name);
        f.R = DAT_004dd700->f28->FUN_001fc8c0(id);
        f.i = 0;
        if (f8->count <= 0)
            break;
        f.off = 0x460;
        bool finish = false;
        do {
            do {
                if (!(f52 & (1 << f.i)))
                    break;
                if (!((Entry *)((char *)f8 + f.off))->FUN_001f8aa0(f.Zp, f.R))
                    break;
                key.idx = (unsigned char)f.i;
                f.s10.i = f.W->FUN_00024b00(&key);
                short s = f8->FUN_001f9630(key);
                if (s == 0) {
                    if (f.s10.i != 0)
                        break;
                    b50 = 1;
                    Spawner *sp = DAT_004dd700->f30;
                    if (sp == 0)
                        break;
                    f.q.FUN_001ca000(f8->name, name);
                    sp->FUN_001cbc20(&f.q);
                    break;
                }
                if (!(s > 0 || s == -1 || s == -2))
                    break;

                Cfg *c = f8;
                f.strike = memcmp(c->name, "strike_team", 12) == 0;
                Entry *E = (Entry *)((char *)c + f.off);
                char *entryName = E->obj->FUN_00044400();
                FUN_00267760(f.buf1, 0x100, "%s+%s+%d+%s", f8->name, name, f.i, entryName);
                if (f.s10.i >= E->f4)
                    break;
                f.n = E->f8 - f.s10.i;
                if (s > 0 && f.n > s)
                    f.n = s;
                f.r2 = FUN_001f8b40(E->f10, f.R, f.pos);
                if (f.r2 == 0 || f.r2 == f.R) {
                    if (f.strike) {
                        int j;
                        for (j = 1; j < 6; j++) {
                            f.r2 = FUN_001f8b40(j, f.R, f.pos);
                            if (f.r2 != 0 && f.r2 != f.R)
                                break;
                        }
                    }
                }
                if (f.r2 == 0) {
                    finish = true;
                    break;
                }
                f.r2->v8(&f.v40);
                f.rr = f.r2->v9();
                if (!f.strike) {
                    f.d.x = f.v40.x - f.pos.x;
                    f.d.y = f.v40.y - f.pos.y;
                    f.d.z = f.v40.z - f.pos.z;
                    f.s10.f = f.d.FUN_00018990();
                    Zone *zone = DAT_004dd700->f8;
                    char near_ = zone->FUN_00099d60(f.v40.x, f.v40.y, f.v40.z, 1.0f, 0);
                    float thr = near_ ? DAT_004c83ec : DAT_004c83e8;
                    if (f.s10.f < thr) {
                        finish = true;
                        break;
                    }
                }

                if (f.n > 0) {
                    do {
                        int k = 0;
                        Actor *a;
                        int r3;
                        for (;;) {
                            if (s != -1 && s != -2)
                                FUN_00267760(f.buf2, 0x100, "%s+%d.%d", f.buf1, (int)s, k);
                            else
                                FUN_00267760(f.buf2, 0x100, "%s+%d", f.buf1, k);
                            u64 hid = FUN_002672f0(f.buf2, 0, 0);
                            a = f.W->FUN_00024280(hid);
                            f.nm.FUN_0027b0e0(f.buf2);
                            r3 = FUN_001c3d90()->f0c->FUN_001c59d0(&f.nm);
                            f.nm.FUN_0027af50();
                            k++;
                            if (a == 0 && r3 == 0)
                                break;
                        }
                        float ang = (*(float*)&DAT_004e58e0);
                        f.tmp.x = 2.0f;
                        f.tmp.y = 0.0f;
                        f.tmp.z = 0.0f;
                        FUN_00224d70(ang, &f.tmp);
                        f.tmp.x = f.tmp.x + f.v40.x;
                        f.tmp.y = f.tmp.y + f.v40.y;
                        f.tmp.z = f.tmp.z + f.v40.z;
                        (*(float*)&DAT_004e58e0) = (*(float*)&DAT_004e58e0) + 1.7453293f;
                        (*(float*)&DAT_004e58e0) = FUN_0004af40(0.0f, 6.2831855f, (*(float*)&DAT_004e58e0));
                        if (!f.W->FUN_0002bf80(E->obj->FUN_00044360(), f.tmp, f.rr, name, "none", 0, f.buf2))
                            continue;
                        if (s > 0)
                            s = s - 1;
                        Actor *na = f.W->FUN_000259f0(f.buf2);
                        if (na == 0)
                            continue;
                        f.R->v8(&f.v68);
                        na->FUN_00037180(f.v68);
                        na->FUN_000371b0(E->f1c);
                        na->FUN_0003ec70(&key);
                        na->FUN_00037160(E->f14);
                        na->FUN_00037170(E->f18);
                        na->f1d7c = f8->f454;
                        Inst *inst = FUN_001d4c90();
                        if (inst == 0)
                            continue;
                        if (!inst->FUN_001d1cb0())
                            continue;
                        char nb = inst->FUN_001d2ba0("newborn", 0, 1);
                        f.strike = nb;
                        if (nb) {
                            inst->FUN_001d1d50("name", f.buf2);
                            inst->FUN_001d1d50("locator_eg", name);
                            inst->FUN_001d1d50("locator_spawn", (const void *)f.r2->FUN_001fba60());
                            inst->FUN_001d19d0(1);
                        }
                        inst->FUN_001d1d30();
                        if (!nb)
                            continue;
                        if (inst->FUN_001d1930(f8->f448))
                            inst->FUN_001d2b10(-1, -1);
                        if (inst->FUN_001d1930(E->f20))
                            inst->FUN_001d2b10(-1, -1);
                    } while (--f.n != 0);
                }
                if (s >= 0)
                    f8->FUN_001f9670(key, s);
            } while (0);
            if (finish)
                break;
            f.i++;
            f.off += 0x28;
        } while (f.i < f8->count);
    } while (0);
}
} // namespace fn_001f9810
#undef memcmp
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f326376d {

// 0x001fa1c0 FUN_001fa1c0 (465 B): equivalent/0x001fa1c0.cpp
// sym: ?FUN_001fa1c0@Panel_1fa1c0@fn_f326376d@@QAEXPAUTarget_1fa1c0@2@PAUItem_1fa1c0@2@@Z
// STATUS: equivalent (tools/equiv.py level 3: 3012 inputs, branch coverage 28/28)
// FUN_001fa1c0 @ 0x001fa1c0
void Panel_1fa1c0::FUN_001fa1c0(Target_1fa1c0 *target, Item_1fa1c0 *item)
{
    if (count >= 16 || !item) {
        return;
    }

    slots[count].FUN_001f9230();
    slots[count].FUN_001f9710(this, item->FUN_001fba60(), target->data[0], f43c);
    count++;

    Selector_1fa1c0 *sel = FUN_001d4c90();
    do {
        if (!sel)
            break;
        if (!sel->FUN_001d1930(f44c))
            break;
        sel->FUN_001d1a50(label);
        sel->FUN_001d1ac0((float)(count - 1));
        sel->FUN_001d1a50(item->FUN_001fba60());
        int r = sel->FUN_001d2b10(-4, 3);
        unsigned char ok = 1;
        unsigned char out;
        if (r == -1) {
            sel->FUN_001d19d0(1);
        } else if (r > 0) {
            if (sel->FUN_001d1ae0(&out) && out == 1)
                ok = 0;
            if (r > 1)
                sel->FUN_001d19d0(r - 1);
            if (!ok)
                break;
        }
        for (int i = 0; i < entryCount; i++) {
            if (entries[i].active) {
                slots[count].value.index = (unsigned char)i;
                FUN_001f9fc0(slots[count].value);
            }
        }
        slots[count - 1].flag51 = 0;
    } while (0);

    Queue_1fa1c0 *q = DAT_004dd700->queue;
    if (q) {
        Msg_1fa1c0 m;
        m.FUN_001ca020(label, item->FUN_001fba60());
        q->FUN_001cbc20(&m);
    }
}

} // namespace fn_f326376d

// 0x001fa3a0 FUN_001fa3a0 (344 B): equivalent/0x001fa3a0.cpp [wrapped: conflict: World]
// sym: ?FUN_001fa3a0@Mixer@fn_001fa3a0@@QAEXH@Z
namespace fn_001fa3a0 {
// STATUS: equivalent (tools/equiv.py level 3: 3006 inputs, branch coverage 14/14)
// FUN_001fa3a0 @ 0x001fa3a0
// cl-flags: /GS
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

int __cdecl FUN_00267760(char *buf, int size, const char *fmt);

struct S8_1fa3a0 {
    int a;
    int b;
    void FUN_0027af30(const S8_1fa3a0 *src);
    void FUN_0027b040(const char *name);
};

/* 16-byte by-value argument; only the first ten bytes are copied. Overlays a record's
   name and two flag bytes, which are re-read after the name copy. */
struct SlotKey_1fa3a0 {
    S8_1fa3a0 name;
    char flagA;
    char flagB;
    char pad[6];
    SlotKey_1fa3a0(const SlotKey_1fa3a0 &src) {
        name.FUN_0027af30(&src.name);
        flagA = src.flagA;
        flagB = src.flagB;
    }
};

struct Event_1fa3a0 {
    int words[24];
    void FUN_001ca040(const void *a, const void *b);
};

struct Listener_1fa3a0 {
    void FUN_001cbc20(Event_1fa3a0 *ev);
};

struct World {
    char pad00[0x30];
    Listener_1fa3a0 *listener;
};


struct Record_1fa3a0 {
    char pad00[8];
    int field08;
    char label[0x20];
    char pad2c[4];
    S8_1fa3a0 name;
    unsigned char flagA;
    unsigned char flagB;
    char pad3a[6];
    int f40, f44, f48, f4c;
    unsigned char f50;
    unsigned char f51;
    unsigned short f52;
    char pad54[4];
    void FUN_001f91b0(const Record_1fa3a0 *src);
};

struct Channel {
    char flag;
    char pad[0x27];
};

class Mixer {
public:
    char pad000[0x41c];
    char settings[0x484 - 0x41c];
    Channel channels[1];
    char pad4ac[0x6e0 - 0x4ac - 0x28 + 0x28];
    int channelCount;
    char pad6e4[4];
    Record_1fa3a0 records[16];
    int recordCount;

    void FUN_001f9fc0(SlotKey_1fa3a0 key);
    void FUN_001fa3a0(int index);
};

void Mixer::FUN_001fa3a0(int index)
{
    char gs_unused[16]; /* dead stack buffer: MSVC /GS protects only functions with a char array */

    if (index >= 0 && index < recordCount) {
        for (int i = 0; i < channelCount; i++) {
            if (channels[i].flag) {
                Record_1fa3a0 *r = &records[index];
                r->flagB = (unsigned char)i;
                FUN_001f9fc0(*(SlotKey_1fa3a0 *)&r->name);
            }
        }
        Record_1fa3a0 *r = &records[index];
        r->flagB = 0xff;

        Listener_1fa3a0 *l = DAT_004dd700->listener;
        if (l) {
            Event_1fa3a0 ev;
            ev.FUN_001ca040(settings, r->label);
            l->FUN_001cbc20(&ev);
        }

        r->field08 = 0;
        FUN_00267760(r->label, 0x20, "CONSTRUCTED, BUT NOT YET NAMED");
        r->f40 = 0;
        r->f44 = 0;
        r->f48 = 0;
        r->f4c = 0;
        r->flagA = 0xff;
        r->name.FUN_0027b040("");
        r->flagB = 0xff;
        r->f50 = 0;
        r->f51 = 1;
        r->f52 = 0xffff;
        if (index != recordCount - 1)
            r->FUN_001f91b0(&records[recordCount - 1]);
        recordCount--;
    }
}
} // namespace fn_001fa3a0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

