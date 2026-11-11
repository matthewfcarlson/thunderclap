// cl-flags: /GS
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00203870..0x00208b9c (kind game, layer game, confidence high), dominant class CWorldStreamManager
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/engine/content.h"
#include "decls/data/engine/fight.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f43ea553 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f43ea553 {} using namespace fn_f43ea553;
#include "game/global.h"

// ---- declarations shared by the functions below
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" char *strncpy(char *, const char *, unsigned int);
#endif
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int sprintf(char *, const char *, ...);
#endif
namespace fn_f43ea553 {
struct Source_203a80 {
    char *FUN_002666f0();
};
struct Tag {
    int unused;
};
class Holder_203a80 {
public:
    char pad00[4];
    Tag tag;
    char pad08[0x1c];
    char name[0xac8];
    Source_203a80 *source;
    char pad_af0[2];
    char shortForm;
    char disabled;

    char *FUN_00203a80();
};
struct Source_203bb0 {
    char *FUN_002666f0();
};
class Holder_203bb0 {
public:
    char pad00[4];
    Tag tag;
    char pad08[0xae4];
    Source_203bb0 *source;
    char pad_af0[2];
    char shortForm;

    int FUN_00203bb0();
};
class Handle_203e90 {
public:
    virtual void v0();
    bool FUN_00266750();
    int FUN_00266700();
};
struct Request {
    char name[0x100];
    int f100;
    int f104;
    int f108;
    char f10c;
    char pad10d[3];
};
struct Mgr_203e90 {
    char pad00[4];
    int limit;
    void FUN_00265810(Request* r, Handle_203e90** out);
    int FUN_00264870();
};
struct Target_203e90 {
    void FUN_00266220(int v);
};
struct Item_203e90 {
    void FUN_000bd1b0(int v);
};
struct Holder_203e90 {
    char pad00[0x20];
    Item_203e90* item;
    Item_203e90* FUN_00086280();
};
struct Actor_203e90 {
    char pad00[4];
    char f04;
    char pad05[0x21];
    short f26;
    char pad28[0x10];
    Target_203e90* f38;
};
int FUN_00266da0(int v);
extern "C" unsigned int FUN_00267f80();
class Owner_203e90 {
public:
    char pad000[0x588];
    Holder_203e90* f588;
    char pad58c[0xaf5 - 0x58c];
    char fAF5;
    char padAF6[6];
    unsigned int fAFC;

    Handle_203e90* Run(const char* name, bool a2, bool a3, Actor_203e90* actor, Target_203e90* target, int a6, int a7);
};
struct Frame_204d70 { char buf[32];  };
struct Rec_204d70 { char pad[0x38]; int v38; };
struct Target_204d70 {
    char pad0[0x24];
    char name[1];
    Rec_204d70 *FUN_00204540(char *key);
    hulk_intptr FUN_00204d70(int index);
};
} // namespace fn_f43ea553
extern "C" int __cdecl _sprintf(char *buf, const char *fmt, ...);
namespace fn_f43ea553 {
struct Marker_205860 {
    void FUN_00204f00();
};
class District_205860 {
public:
    char pad0[0x24];
    char name[0x570 - 0x24];    // 0x24
    int ids[2];                 // 0x570
    bool FUN_002046b0(int id);
    Marker_205860 *FUN_00204540(const char *label);
    void FUN_00205860(int id);
};
struct Obj_206320 {
  virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5();
  void FUN_00263e90(); void FUN_002660a0(Obj_206320*);
};
struct LoadInventory_206320 { Obj_206320* FUN_00266480(int); };
struct Sub_206320 { int FUN_00088fa0(); int FUN_00088fb0(); };
struct Ctx_206320 {
  char pad0[0x80]; Sub_206320 sub;
  const char* FUN_000897e0(); char* FUN_000897f0(); char* FUN_0008a2d0();
};
struct Prov_206320 {  };
struct Rand {  };
struct Link_206320 { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); void FUN_00233160(Obj_206320*); };
struct Node { char pad[0x5c]; Link_206320* link; };
struct Registry_206320 {  };
struct Fig { Obj_206320* FUN_00024400(const char*, int); };
} // namespace fn_f43ea553
struct World { char pad[0x20]; Fig* fig; };
namespace fn_f43ea553 {
struct Timer { void FUN_00265ad0();  };
struct Nodes_206320 {
  Node* FUN_00232840(long long); int FUN_002327c0(); Node* FUN_00232810(int);
};
struct W_206320 {
  char pad0[4]; char name1[0x20]; char name2[0x20];
  Obj_206320* f44;
  char pad1[0x588-0x48]; Prov_206320* prov;
  char pad2[0x5a4-0x58c]; unsigned int tbl[0x100];
  char pad3[0xaa0-0x9a4]; Obj_206320* aa0; char aa4[0x20]; char ac4[0x20];
  Obj_206320* ae4; Obj_206320* ae8;
  void FUN_00205910();   
  Obj_206320* FUN_00203e90(const char*, int, int, int, Obj_206320*, Obj_206320*, int);
  void FUN_00206320(Ctx_206320*);
};
extern "C" Registry_206320* __cdecl FUN_001d4c90();
extern "C" Rand* __cdecl FUN_000964d0();
extern "C" void* __cdecl FUN_00263ea0(int);
extern "C" void __cdecl FUN_000964a0(char*, int, const char*, ...);
} // namespace fn_f43ea553
extern "C" int __cdecl _strncmp(const char*, const char*, unsigned int);

namespace fn_f43ea553 {

// 0x00203a80 FUN_00203a80 (293 B): equivalent/0x00203a80.cpp
// sym: ?FUN_00203a80@Holder_203a80@fn_f43ea553@@QAEPADXZ @6ba93859d810 @wf52860304ff6
// STATUS: equivalent (tools/equiv.py level 3: 20012 inputs, branch coverage 9/9)
// FUN_00203a80 @ 0x00203a80
char *Holder_203a80::FUN_00203a80()
{
    struct Frame {
        char buf[0x100];
    } fr;
    if (!source || disabled) {
        return 0;
    }
    strncpy(fr.buf, source->FUN_002666f0(), 0x100);
    Tag *t = &tag;
    if (t) {
        char *end = fr.buf;
        while (*end)
            end++;
        end -= 4;
        *end = 0;
        if (shortForm)
            sprintf(((char*)&DAT_004e5a68), "%s_district_%d", name, atol(end - 1));
        else
            sprintf(((char*)&DAT_004e5a68), "%s_r%03d", name, atol(end - 3));
    } else {
        char *p = fr.buf;
        while (*p)
            p++;
        p--;
        while (*p != 'C')
            p--;
        char *q = ((char*)&DAT_004e5a68);
        while ((*q++ = *p++) != 0)
            ;
        char *dot = ((char*)&DAT_004e5a68);
        while (*dot != '.')
            dot++;
        *dot = 0;
    }
    return ((char*)&DAT_004e5a68);
}


// 0x00203bb0 FUN_00203bb0 (242 B): equivalent/0x00203bb0.cpp
// sym: ?FUN_00203bb0@Holder_203bb0@fn_f43ea553@@QAEHXZ @067c928d4bbe @w1c8000020426
// STATUS: equivalent (tools/equiv.py level 3: 20012 inputs, branch coverage 7/7)
// FUN_00203bb0 @ 0x00203bb0
int Holder_203bb0::FUN_00203bb0()
{
    struct Frame {
        char small[0x20];
        char buf[0x100];
    } fr;
    if (!source) {
        return -1;
    }
    strncpy(fr.buf, source->FUN_002666f0(), 0x100);
    Tag *t = &tag;
    if (t) {
        char *end = fr.buf;
        while (*end)
            end++;
        end -= 4;
        *end = 0;
        long v = atol(shortForm ? end - 1 : end - 3);
        return v;
    }
    char *p = fr.buf;
    while (*p)
        p++;
    p--;
    while (*p != 'R')
        p--;
    p++;
    char *q = fr.small;
    while ((*q++ = *p++) != 0)
        ;
    char *dot = fr.small;
    while (*dot != '.')
        dot++;
    *dot = 0;
    long v = atol(fr.small);
    return v;
}


// 0x00203e90 FUN_00203e90 (452 B): equivalent/0x00203e90.cpp
// sym: ?Run@Owner_203e90@fn_f43ea553@@QAEPAVHandle_203e90@2@PBD_N1PAUActor_203e90@2@PAUTarget_203e90@2@HH@Z @38bebf6837aa @w3bc73b346e87
// STATUS: equivalent (tools/equiv.py level 3: 9174 inputs, branch coverage 30/30)
// FUN_00203e90 @ 0x00203e90
Handle_203e90* Owner_203e90::Run(const char* name, bool a2, bool a3, Actor_203e90* actor, Target_203e90* target, int a6, int a7)
{
    struct Frame {
        Handle_203e90* out;
        int saved;
        int prev;
        Request req;
    } f;
    f.prev = FUN_00266da0(0xb);
    if (actor)
        actor->f04 = 1;
    f.req.f108 = a7;
    f.out = 0;
    f.req.name[0] = 0;
    f.req.f100 = 0;
    f.req.f104 = 0;
    f.req.f10c = 0;
    if (name)
        strncpy(f.req.name, name, 0xff);
    f.req.f104 = a6;
    f.req.f10c = 0;
    if (actor)
        f.req.f108 = actor->f26;
    (*(Mgr_203e90**)&DAT_00527c58)->FUN_00265810(&f.req, &f.out);
    if (!a2) {
        Item_203e90* item = f588->FUN_00086280();
        if (a3 && item && !fAF5)
            item->FUN_000bd1b0(0);
        f.saved = (*(Mgr_203e90**)&DAT_00527c58)->FUN_00264870();
        ((owners::C_264860 *)((*(Mgr_203e90**)&DAT_00527c58)))->FUN_00264860(250000);
        while (!f.out->FUN_00266750()) {
            if (item) {
                if ((a3 && !fAF5) || (fAFC != 0 && FUN_00267f80() - fAFC > 3000))
                    item->FUN_000bd1b0(0);
            }
            FUN_00087990();
        }
        ((owners::C_264860 *)((*(Mgr_203e90**)&DAT_00527c58)))->FUN_00264860(f.saved);
        int n = f.out->FUN_00266700();
        Target_203e90* t = actor ? actor->f38 : target;
        t->FUN_00266220(n);
    }
    FUN_00266da0(f.prev);
    Handle_203e90* result = f.out;
    return result;
}


// 0x00204d70 FUN_00204d70 (109 B): equivalent/0x00204d70.cpp
// sym: ?FUN_00204d70@Target_204d70@fn_f43ea553@@QAEHH@Z @3504c1170b76 @wb83fdb3b2edd
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 4/4)
// FUN_00204d70 @ 0x00204d70
hulk_intptr Target_204d70::FUN_00204d70(int index)
{
    Frame_204d70 f;
    char *buf = f.buf;
    sprintf(buf, "%s_r%03d", name, index);
    if ((*(char*)&DAT_004c91d8) != 0) {
        Rec_204d70 *r = FUN_00204540(buf);
        if (r != 0) {
            int v = r->v38;
            return v;
        }
    }
    return 0;
}


// 0x00205860 FUN_00205860 (165 B): equivalent/0x00205860.cpp
// sym: ?FUN_00205860@District_205860@fn_f43ea553@@QAEXH@Z @2768998d7f72 @w6ac53d11bd67
// STATUS: equivalent (tools/equiv.py level 3: 20001 inputs, branch coverage 8/8)
// FUN_00205860 @ 0x00205860
void District_205860::FUN_00205860(int id)
{
    struct Frame {
        char label[0x100];
    } fr;
    for (int i = 0; i < 2; i++) {
        if (ids[i] != id)
            continue;
        if (!FUN_002046b0(id)) {
            _sprintf(fr.label, "%s_district_%d", name, id);
            ((owners::Thing_204760 *)this)->FUN_00204760(id);
            if ((*(char*)((char*)&DAT_004c91d8 + 1)) != 0)
                FUN_00204540(fr.label)->FUN_00204f00();
        }
        break;
    }
}


// 0x00206320 FUN_00206320 (1199 B): equivalent/0x00206320.cpp
// sym: ?FUN_00206320@W_206320@fn_f43ea553@@QAEXPAUCtx_206320@2@@Z @1751c2469025 @w9263a85f0d92
// STATUS: equivalent (tools/equiv.py level 3: 544 inputs, branch coverage 42/42)
// FUN_00206320 @ 0x00206320
void W_206320::FUN_00206320(Ctx_206320* g){
  char buf[0x100];
  const char* s = ((Ctx_206320 *)((owners::C_86310 *)prov)->FUN_00086310())->FUN_000897e0();
  char* d = name1;
  while ((*d++ = *s++) != 0) {}
  s = ((Ctx_206320 *)((owners::C_86310 *)prov)->FUN_00086310())->FUN_000897f0();
  d = name2;
  while ((*d++ = *s++) != 0) {}
  (*(Timer**)&DAT_00527c58)->FUN_00265ad0();
  ((owners::C_264860 *)((*(Timer**)&DAT_00527c58)))->FUN_00264860(3000);
  FUN_00205910();
  for (int i = 0; i < 0x100; i++) tbl[i] = 0;
  Registry_206320* reg = FUN_001d4c90();
  ((owners::C_203a10 *)this)->FUN_00203a10();
  if (((Ctx_206320 *)((owners::C_86310 *)prov)->FUN_00086310())->sub.FUN_00088fa0() == 10) {
    const char* hulk = "hulk";
    bool same = true;
    for (int i = 0; i < 5; i++) if (aa4[i] != hulk[i]) { same = false; break; }
    if (same) {
      int v = ((Ctx_206320 *)((owners::C_86310 *)prov)->FUN_00086310())->sub.FUN_00088fb0();
      if (v == 0x20 || v == 0x28) {
        ((owners::Target_203870 *)this)->FUN_00203870((char *)"joefixit");
      } else if (v == 0x23) {
        ((owners::Obj_2039a0 *)this)->FUN_002039a0(5, 12);
        int r = ((owners::Random_11380 *)(FUN_000964d0()))->FUN_00011380(1, 10);
        if (r == 1) ((owners::Target_203870 *)this)->FUN_00203870((char *)"hulk_canada");
        else if (r == 2) ((owners::Target_203870 *)this)->FUN_00203870((char *)"hulk_australia");
      }
    }
  }
  if (aa0 != 0 && _strncmp(aa4, ac4, 0x20) == 0) {
    Nodes_206320* nodes = (*(Nodes_206320**)&DAT_004e5af8);
    Node* n1 = nodes->FUN_00232840(FUN_002672f0((*(const char**)&DAT_004c91cc), 0, 0));
    Link_206320* l1 = n1->link;
    l1->FUN_00233160(ae4);
    Node* n2 = nodes->FUN_00232840(FUN_002672f0((*(const char**)&DAT_004c91d4), 0, 0));
    Link_206320* l2 = n2->link;
    l2->FUN_00233160(ae8);
  } else {
    int savedHeap = FUN_00266da0(0x11);
    if (ae8) { ae8->slot1(); ae8 = 0; }
    if (ae4) { ae4->slot1(); ae4 = 0; }
    if (aa0) { aa0->slot1(); aa0 = 0; }
    void* mem = FUN_00263ea0(0x14);
    aa0 = mem ? ((LoadInventory_206320*)mem)->FUN_00266480(0x800) : 0;
    aa0->slot0();
    FUN_000964a0(buf, 0x100, "art/global_nonchar.p3d");
    FUN_00203e90(buf, 0, 1, 0, aa0, 0, 0x11)->FUN_00263e90();
    FUN_000964a0(buf, 0x100, "art/global_%s.p3d", aa4);
    FUN_00203e90(buf, 0, 1, 0, aa0, 0, 0x11)->FUN_00263e90();
    _strncpy(ac4, aa4, 0x20);
    Fig* fig = DAT_004dd700->fig;
    int oldMode = FUN_002381a0(2, 0x11);
    Obj_206320* o = fig->FUN_00024400("scripts/fight/hulk.fig", 0);
    if (o) o->slot0();
    if (ae4) ae4->slot1();
    ae4 = o;
    o = fig->FUN_00024400("scripts/fight/common.fig", 0);
    if (o) o->slot0();
    if (ae8) ae8->slot1();
    ae8 = o;
    FUN_002381a0(2, oldMode);
    FUN_00266da0(savedHeap);
  }
  FUN_000964a0(buf, 0x100, "art/locations/%s/%s_init.lua", g->FUN_000897e0(), g->FUN_000897f0());
  ((owners::Object_1d3600 *)reg)->FUN_001d3600(buf, 0);
  FUN_000964a0(buf, 0x100, "art/missions/%s/%s_init.lua", g->FUN_0008a2d0(), g->FUN_0008a2d0());
  ((owners::Object_1d3600 *)reg)->FUN_001d3600(buf, 0);
  Nodes_206320* nodes = (*(Nodes_206320**)&DAT_004e5af8);
  int n = nodes->FUN_002327c0();
  for (int i = 0; i < n; i++) nodes->FUN_00232810(i)->link->slot5();
  f44->FUN_002660a0(aa0);
  FUN_000964a0(buf, 0x100, "art/locations/%s/%s.p3d", g->FUN_000897e0(), g->FUN_000897f0());
  FUN_00203e90(buf, 0, 1, 0, f44, f44, 0xb)->FUN_00263e90();
  FUN_000964a0(buf, 0x100, "art/missions/%s/%s.p3d", g->FUN_0008a2d0(), g->FUN_0008a2d0());
  FUN_00203e90(buf, 0, 1, 0, f44, f44, 0xb)->FUN_00263e90();
}

} // namespace fn_f43ea553

// 0x002067d0 FUN_002067d0 (610 B): equivalent/0x002067d0.cpp [wrapped: conflict: World]
// sym: ?FUN_002067d0@Loader_2067d0@fn_002067d0@@QAEXHD@Z @d7198c2358e4 @w5a12642ec708
inline void *operator new(size_t, void *p) throw() { return p; }
namespace fn_002067d0 {
// STATUS: equivalent (tools/equiv.py level 3: 7358 inputs, branch coverage 12/12)
// FUN_002067d0 @ 0x002067d0
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



#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl sprintf(char *, const char *, ...);
#endif


typedef unsigned __int64 ID;

namespace pure3d { class Geometry_2067d0; class Shadow_2067d0; class LightGroup_2067d0; }
namespace physics { class WorldCollisionObject_2067d0; }

namespace content {
namespace LoadInventory {
template <class T>
struct DynamicCaster {
    virtual void v0();
};
}
}

struct Name_2067d0 {
    unsigned int lo, hi;
    void FUN_0027b0e0(const char *s);
    void FUN_0027af50();
};

struct Factory_2067d0 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void *f3(void *caster, unsigned int lo, unsigned int hi);
    void FUN_002660a0(int v);
};

struct Entry_2067d0 {
    char pad0[8];
    char loaded;            // 0x08
    char pad9[0x56 - 9];
    short f56;              // 0x56
    float f58;              // 0x58
    void FUN_001c6cb0(void *geom);
    void FUN_001c6ce0(void *shadow);
    void FUN_001c6950(void *lights);
};

struct Item_2067d0 {
    char pad0[0x38];
    Factory_2067d0 *factory;       // 0x38
};

struct SlotA_2067d0 { void FUN_001dd320(int idx); };
struct SlotB_2067d0 {  };
struct SlotC_2067d0 { void FUN_001fb300(Factory_2067d0 *f); };
struct SlotD { void FUN_0007da70(int idx); };
struct SlotE { void FUN_001b5ec0(void *obj, int idx); };

struct Bank {
    char pad0[0xc];
    SlotA_2067d0 *a;               // 0x0c
    SlotE *e;               // 0x10
    char pad14[0x28 - 0x14];
    SlotB_2067d0 *b;               // 0x28
    char pad2c[0x48 - 0x2c];
    SlotC_2067d0 *c;               // 0x48
    SlotD *d;               // 0x4c
};

struct Mid_2067d0 {
    char pad0[0xc];
    Bank *bank;             // 0x0c
};

struct Event_2067d0 {
    int f0, f4, f8, fc, f10, f14;
    void FUN_001cad10(int idx);
};

struct Queue_2067d0 {
    void FUN_001cbc20(Event_2067d0 *e);
};

struct World {
    char pad0[0x30];
    Queue_2067d0 *queue;           // 0x30
};

struct Registry3 {
    Entry_2067d0 *FUN_001c7f70(Name_2067d0 *n);
};

struct Registry2 {
    char pad0[4];
    Registry3 *table;       // 0x04
};

Registry2 *FUN_001c3d90();


struct Loader_2067d0 {
    char pad0[0x24];
    char name[0x588 - 0x24];
    Mid_2067d0 *mid;               // 0x588
    char pad58c[4];
    short *f590;            // 0x590
    char pad594[0x5a4 - 0x594];
    char flags[0x100];      // 0x5a4
    Item_2067d0 *FUN_00204540(const char *name);
    void FUN_002067d0(int idx, char flag);
};

struct Frame_2067d0 {
    char casters[8];        // 0x00, 0x04
    Name_2067d0 nm;                // 0x08
    Event_2067d0 ev;               // 0x10
    char name[0x100];
    char buf[0x100];
};

void Loader_2067d0::FUN_002067d0(int idx, char flag)
{
    Frame_2067d0 f;
    sprintf(f.name, "%s_r%03d", this->name, idx);
    Factory_2067d0 *fac = 0;
    if ((*(char*)&DAT_004c91d8))
        fac = FUN_00204540(f.name)->factory;
    Name_2067d0 &nm = f.nm;
    nm.FUN_0027b0e0(f.name);
    Entry_2067d0 *entry = FUN_001c3d90()->table->FUN_001c7f70(&nm);
    nm.FUN_0027af50();
    fac->FUN_002660a0(((int)((owners::Obj_203db0 *)this)->FUN_00203db0((hulk_intptr)(entry->f56))));
    mid->bank->a->FUN_001dd320(idx);
    ((owners::C_1fd180 *)(mid->bank->b))->FUN_001fd180(idx);
    mid->bank->c->FUN_001fb300(fac);

    sprintf(f.buf, "%sScene", f.name);
    ID sceneKey = FUN_002672f0(f.buf, 0, 0);
    {
        content::LoadInventory::DynamicCaster<pure3d::Geometry_2067d0> *c = new (&f.casters[4]) content::LoadInventory::DynamicCaster<pure3d::Geometry_2067d0>;
        entry->FUN_001c6cb0(fac->f3(c, (unsigned int)sceneKey, (unsigned int)(sceneKey >> 32)));
    }
    sprintf(f.buf, "%sShadow", f.name);
    {
        ID k = FUN_002672f0(f.buf, 0, 0);
        content::LoadInventory::DynamicCaster<pure3d::Shadow_2067d0> *c = new (&f.casters[0]) content::LoadInventory::DynamicCaster<pure3d::Shadow_2067d0>;
        entry->FUN_001c6ce0(fac->f3(c, (unsigned int)k, (unsigned int)(k >> 32)));
    }
    {
        content::LoadInventory::DynamicCaster<pure3d::LightGroup_2067d0> *c = new (&f.casters[0]) content::LoadInventory::DynamicCaster<pure3d::LightGroup_2067d0>;
        entry->FUN_001c6950(fac->f3(c, (unsigned int)sceneKey, (unsigned int)(sceneKey >> 32)));
    }
    if (f590 && *f590 != 0 && !flag)
        entry->f58 = 1.0f;
    entry->loaded = 1;
    flags[idx] = 1;
    mid->bank->d->FUN_0007da70(idx);
    sprintf(f.buf, "%sWorldCollision", f.name);
    {
        ID k = FUN_002672f0(f.buf, 0, 0);
        content::LoadInventory::DynamicCaster<physics::WorldCollisionObject_2067d0> *c = new (&f.casters[0]) content::LoadInventory::DynamicCaster<physics::WorldCollisionObject_2067d0>;
        void *wc = fac->f3(c, (unsigned int)k, (unsigned int)(k >> 32));
        if (wc)
            mid->bank->e->FUN_001b5ec0(wc, idx);
    }
    if (!(*(char*)&DAT_004e5a58)) {
        f.ev.FUN_001cad10(idx);
        DAT_004dd700->queue->FUN_001cbc20(&f.ev);
    }
}
} // namespace fn_002067d0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00206a40 FUN_00206a40 (454 B): equivalent/0x00206a40.cpp [wrapped: conflict: FUN_001c3d90; World]
// sym: ?Load@Scene_206a40@fn_00206a40@@QAEXH@Z @e637b1a2cbac @w9444c3995062
namespace fn_00206a40 {
// STATUS: equivalent (tools/equiv.py level 3: 10099 inputs, branch coverage 16/16)
// FUN_00206a40 @ 0x00206a40
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



#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int sprintf(char *buf, const char *fmt, ...);
#endif


namespace pure3d { class LightGroup; }
namespace content {
namespace LoadInventory {
template <class T>
struct DynamicCaster {
    virtual void v0();
};
}
}

struct Slot_206a40 {
    char pad00[0x28];
    char flag28;
};

struct Mixer {
    void FUN_0029f8c0(Slot_206a40 *s);
};

struct Lists_206a40 {
    char pad00[0xc0];
    Mixer *mixC0;
    Mixer *mixC4;
};

struct List_206a40 {
    char pad00[0x10];
    int size;
    int count;
    Slot_206a40 **data;
};

struct Loader_206a40 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual List_206a40 *v3(content::LoadInventory::DynamicCaster<pure3d::LightGroup> *caster, unsigned int lo, unsigned int hi);
};

struct Entry38 {
    char pad00[0x38];
    Loader_206a40 *loader;
};

struct Obj_206a40 {
    char pad00[8];
    char f8;
    void FUN_001c6cb0(int v);
    void FUN_001c6ce0(int v);
};

struct NameKey_206a40 {
    int f0;
    int f4;
    void FUN_0027b0e0(const char *s);
    void FUN_0027af50();
};

struct Mgr_206a40 {
    Obj_206a40 *FUN_001c7f70(NameKey_206a40 *key);
};

struct Single {
    Lists_206a40 *f0;
    Mgr_206a40 *f4;
};

struct SubA_206a40 { void FUN_001b5f60(int i); };
struct SubB_206a40 { void FUN_001e73b0(int i); };
struct SubC_206a40 { void FUN_001fd220(int i); };
struct SubD { void FUN_00079980(int i); };

struct Sub0C_206a40 {
    char pad00[0xc];
    SubB_206a40 *b0c;
    SubA_206a40 *a10;
    char pad14[0x28 - 0x14];
    SubC_206a40 *c28;
    char pad2c[0x4c - 0x2c];
    SubD *d4c;
};

struct Hold588 {
    char pad00[0xc];
    Sub0C_206a40 *f0c;
};

struct Tmp_206a40 {
    char pad[0x18];
    void FUN_001cad80(int i);
};

struct Target30 {
    void FUN_001cbc20(Tmp_206a40 *t);
};

struct World {
    char pad00[0x30];
    Target30 *f30;
};

Single *FUN_001c3d90();


class Scene_206a40 {
public:
    char pad00[0x24];
    char name[0x20];
    char pad44[0x588 - 0x44];
    Hold588 *f588;
    char pad58c[0x5a4 - 0x58c];
    char flags[0x100];

    Entry38 *FUN_00204540(const char *s);
    void Load(int idx);
};

void Scene_206a40::Load(int idx)
{
    struct Frame {
        Lists_206a40 *lists;
        union {
            NameKey_206a40 key;
            char casterBuf[sizeof(content::LoadInventory::DynamicCaster<pure3d::LightGroup>)];
        } u;
        Tmp_206a40 tmp;
        char buf1[0x100];
        char buf2[0x100];
    } f;

    sprintf(f.buf1, "%s_r%03d", name, idx);
    Loader_206a40 *loader = 0;
    if ((*(char*)&DAT_004c91d8))
        loader = FUN_00204540(f.buf1)->loader;
    Mgr_206a40 *mgr = FUN_001c3d90()->f4;
    f.lists = FUN_001c3d90()->f0;
    if (mgr) {
        f.u.key.FUN_0027b0e0(f.buf1);
        Obj_206a40 *obj = mgr->FUN_001c7f70(&f.u.key);
        f.u.key.FUN_0027af50();
        obj->FUN_001c6cb0(0);
        obj->FUN_001c6ce0(0);
        sprintf(f.buf2, "%sScene", f.buf1);
        unsigned __int64 h = FUN_002672f0(f.buf2, 0, 0);
        content::LoadInventory::DynamicCaster<pure3d::LightGroup> *caster =
            new (f.u.casterBuf) content::LoadInventory::DynamicCaster<pure3d::LightGroup>;
        List_206a40 *list = loader->v3(caster, (unsigned int)h, (unsigned int)(h >> 32));
        if (list) {
            for (int i = 0; i < list->count; i++) {
                Slot_206a40 *s = i < list->size ? list->data[i] : 0;
                if (s->flag28)
                    f.lists->mixC4->FUN_0029f8c0(s);
                else
                    f.lists->mixC0->FUN_0029f8c0(s);
            }
        }
        obj->f8 = 0;
    }
    f588->f0c->a10->FUN_001b5f60(idx);
    flags[idx] = 0;
    f588->f0c->b0c->FUN_001e73b0(idx);
    f588->f0c->c28->FUN_001fd220(idx);
    f588->f0c->d4c->FUN_00079980(idx);
    if (!(*(char*)&DAT_004e5a58)) {
        f.tmp.FUN_001cad80(idx);
        DAT_004dd700->f30->FUN_001cbc20(&f.tmp);
    }
}
} // namespace fn_00206a40
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00207080 FUN_00207080 (165 B): equivalent/0x00207080.cpp [wrapped: conflict: FUN_001c3d90]
// sym: ?FUN_00207080@District_207080@fn_00207080@@QAEXH@Z @71836488ddfd @w85400711ac65
namespace fn_00207080 {
// STATUS: equivalent (tools/equiv.py level 3: 20012 inputs, branch coverage 4/4)
// FUN_00207080 @ 0x00207080
// cl-flags: /GS

extern "C" int __cdecl _sprintf(char *buf, const char *fmt, ...);

class Locator {
public:
    virtual void v0();
};

class Locator91 : public Locator {
public:
    virtual void v1();
};

struct Marker_207080 {
    void FUN_00204f00();
};

struct Entry_207080 {
    char pad0[0x56];
    short id;               // 0x56
};

struct Index_207080 {
    Entry_207080 *FUN_001c7f10(int key);
};

struct Manager_207080 {
    char pad0[4];
    Index_207080 *index;           // 0x04
};

Manager_207080 *FUN_001c3d90();

class Region;

#define DAT_0052c2a8 (*(class Services_207080 * *)&::DAT_0052c2a8)


class Services_207080 {
public:
    virtual void v0();
    virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
    virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65(); virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69();
    virtual void v70(); virtual void v71(); virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75(); virtual void v76(); virtual void v77(); virtual void v78(); virtual void v79();
    virtual void v80(); virtual void v81(); virtual void v82(); virtual void v83(); virtual void v84(); virtual void v85(); virtual void v86(); virtual void v87(); virtual void v88(); virtual void v89();
    virtual void v90();
    virtual void v91();
};

class District_207080 {
public:
    char pad0[0x24];
    char name[0x570 - 0x24];    // 0x24
    int ids[2];                 // 0x570
    bool FUN_002046b0(int id);
    void FUN_00206a40(int id);
    Marker_207080 *FUN_00204540(const char *label);
    void FUN_00205860(int id);
    void FUN_00207080(int id);
};

void District_207080::FUN_00207080(int id)
{
    struct Frame {
        char label[0x100];
    } fr;
    DAT_0052c2a8->v91();
    _sprintf(fr.label, "%s_r%03d", name, id);
    FUN_00206a40(id);
    if ((*(char*)&DAT_004c91d8) != 0)
        FUN_00204540(fr.label)->FUN_00204f00();
    int room = FUN_001c3d90()->index->FUN_001c7f10(id)->id;
    if (!FUN_002046b0(room))
        FUN_00205860(room);
}
} // namespace fn_00207080
#undef DAT_0052c2a8


// 0x00207580 FUN_00207580 (706 B): equivalent/0x00207580.cpp [wrapped: conflict: FUN_000964a0; FUN_001c3d90]
// sym: ?FUN_00207580@MapLoader@fn_00207580@@QAE_NH_N@Z @f32ac21f077b @w2c4989b03fb8
namespace fn_00207580 {
// STATUS: equivalent (tools/equiv.py level 3: 18876 inputs, branch coverage 45/46, incomplete)
// FUN_00207580 @ 0x00207580
// cl-flags: /GS

extern "C" int __cdecl _sprintf(char *, const char *, ...);
extern int __cdecl FUN_000964a0(char *buf, int size, const char *fmt, ...);

struct Node {
    char pad0[0x56];
    short key;
};

struct Pool_207580 {
    Node *FUN_001c7f10(int id);
};

struct Holder_207580 {
    char pad0[4];
    Pool_207580 *pool;
};
Holder_207580 *__cdecl FUN_001c3d90();

struct Slot3c {
    int f0;
    char used;
    char name[0x33];
    int f38;
};

struct Handle_207580 {
    void FUN_00263e90();
};

struct Thing_207580 {
    void FUN_002660a0(int v);
};

class MapLoader {
public:
    char pad0[4];
    char str1[0x20];        // 4
    char str2[0x20];        // 0x24
    int f44;
    Slot3c slots[22];       // 0x48 (20 + 2)
    int keys[2];            // 0x570
    char pad578[0xaec - 0x578];
    Handle_207580 *handle;         // 0xaec
    char padaf0[2];
    char pending;           // 0xaf2
    int FUN_00204c10(int v);
    void FUN_00207080(int v);
    Handle_207580 *FUN_00203e90(char *path, int a, int b, char *slot, int c, int d, int e);
    void FUN_002067d0(int id, int v);
    bool FUN_00207580(int a1, bool a2);
};

bool MapLoader::FUN_00207580(int a1, bool a2)
{
    struct Frame {
        int key;
        Node *node;
        char name[0x40];
        char path[0x100];
    } f;

    char *slot = 0;
    int arg1_ = a1;
    f.node = FUN_001c3d90()->pool->FUN_001c7f10(arg1_);
    if (f.node == 0) {
        return false;
    }
    for (;;) {
        f.key = f.node->key;
        int j = 0;
        while (j < 2 && keys[j] != f.key)
            j++;
        int ref;
        if (j >= 2) {
            FUN_000964a0(f.path, 0x100, "art/locations/%s/%s_district_%d.p3d", str1, str2, f.key);
            _sprintf(f.name, "%s_district_%d", str2, f.key);
            ((owners::C_207150 *)this)->FUN_00207150();
            if ((*(char*)((char*)&DAT_004c91d8 + 1)) != 0) {
                int s = 0;
                while (s < 2 && slots[20 + s].used != 0)
                    s++;
                slot = s < 2 ? (char *)&slots[20 + s] : 0;
                char *d = slot + 5;
                char *src = f.name;
                char c;
                do {
                    c = *src;
                    *d = c;
                    d++;
                    src++;
                } while (c != 0);
            }
            ref = f44;
            pending = 1;
        } else {
            FUN_000964a0(f.path, 0x100, "art/locations/%s/%s_r%03d.p3d", str1, str2, a1);
            _sprintf(f.name, "%s_r%03d", str2, a1);
            if ((*(char*)&DAT_004c91d8) != 0) {
                int s = 0;
                while (s < 0x14 && slots[s].used != 0)
                    s++;
                slot = s < 0x14 ? (char *)&slots[s] : 0;
                char *d = slot + 5;
                char *src = f.name;
                char c;
                do {
                    c = *src;
                    *d = c;
                    d++;
                    src++;
                } while (c != 0);
            }
            if (pending != 0) {
                ref = f44;
            } else {
                ref = 0;
                if ((*(char*)((char*)&DAT_004c91d8 + 1)) != 0) {
                    int k2 = f.node->key;
                    int m = 0;
                    while (m < 2 && keys[m] != k2)
                        m++;
                    if (m < 2)
                        ref = slots[20 + m].f38;
                }
            }
        }
        if (!a2 && (*(char*)&DAT_004e5a50) == 0) {
            handle = FUN_00203e90(f.path, 1, 0, slot, 0, ref, 0xb);
            return true;
        }
        if (pending == 0) {
            int n = FUN_00204c10(0);
            if (n > 0)
                FUN_00207080(n);
        }
        handle = FUN_00203e90(f.path, 0, 1, slot, 0, ref, 0xb);
        handle->FUN_00263e90();
        bool wasPending = pending != 0;
        handle = 0;
        if (!wasPending) {
            FUN_002067d0(a1, 1);
            return true;
        }
        pending = 0;
        int q = 0;
        while (q < 2 && keys[q] != 0)
            q++;
        if (q < 2)
            keys[q] = f.key;
        int arg2_ = f44;
        ((Thing_207580 *)((owners::Obj_203db0 *)this)->FUN_00203db0((hulk_intptr)(f.key)))->FUN_002660a0(arg2_);
    }
}
} // namespace fn_00207580


// 0x00207e80 FUN_00207e80 (220 B): matches/0x00207e80.cpp [wrapped: macros]
// sym: ?FUN_00207e80@Object@fn_00207e80@@QAEXXZ
namespace fn_00207e80 {
// STATUS: equivalent (tools/equiv.py level 3: 725 inputs, branch coverage 12/12)
// FUN_00207e80 @ 0x00207e80
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

#define V(n) virtual void slot##n();
struct Gfx { V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9) V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19) V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29) V(30) V(31) V(32) V(33) V(34) V(35) V(36) V(37) V(38) V(39) V(40) V(41) V(42) V(43) V(44) V(45) V(46) V(47) V(48) V(49) V(50) V(51) V(52) V(53) V(54) V(55) V(56) V(57) V(58) V(59) V(60) V(61) V(62) V(63) V(64) V(65) V(66) V(67) V(68) V(69) V(70) V(71) V(72) V(73) V(74) V(75) V(76) V(77) V(78) V(79) V(80) V(81) V(82) V(83) V(84) V(85) V(86) V(87) V(88) V(89) V(90) V(91) };

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl sprintf(char*, const char*, ...);
#endif

struct Item { int FUN_00266710(); };
struct Result { void FUN_00204f00(); };
struct Object {
 char pad0[0x24]; char name[0x56c]; int count590; char pad594[8]; int count59c; char pad5a0[4]; unsigned char states[0x400]; char pad9a4[0x148]; Item* item; unsigned char flag;
 void FUN_00203e30(Item*); void FUN_00207410(); void FUN_00206a40(int); Result* FUN_00204540(const char*);
 void FUN_00207e80();
};
void Object::FUN_00207e80() {
 char buffer[256];
 DAT_0052c2a8->slot91();
 if(item) {
  int status=item->FUN_00266710();
  flag=1;
  if(status!=3) FUN_00203e30(item);
  FUN_00207410();
 }
 for(int i=0;i<1024;++i) {
  if(states[i]==1 || states[i]==3) {
   FUN_00206a40(i);
   sprintf(buffer,"%s_r%03d",name,i);
   if((*(unsigned char*)&DAT_004c91d8)) FUN_00204540(buffer)->FUN_00204f00();
  }
  states[i]=0;
 }
 count59c=0; count590=0;
}
} // namespace fn_00207e80
#undef V
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00207f60 FUN_00207f60 (212 B): matches/0x00207f60.cpp [wrapped: conflict: FUN_001c3d90]
// sym: ?FUN_00207f60@Object@fn_00207f60@@QAEXXZ
namespace fn_00207f60 {
// STATUS: equivalent (tools/equiv.py level 3: 143 inputs, branch coverage 6/6)
// FUN_00207f60 @ 0x00207f60
// cl-flags: /GS

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl sprintf(char *, const char *, ...);
#endif

struct Item_207f60 { char pad[0x54]; short id; };
struct ListPart { int FUN_001c7520(); };
struct Manager_207f60 { char pad[0x18]; ListPart list;  };
struct Context { char pad[4]; Manager_207f60 *manager; };
Context * __cdecl FUN_001c3d90();
struct Resource_207f60 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8();
 virtual void v9(int *, int *, int *, int *);
 virtual void v10(); virtual void v11();
};
struct Handle_207f60 { char pad[0x30]; Resource_207f60 *resource; };
struct Object {
 char pad0[0x24]; char name[0xad0]; unsigned char dirty;
 void FUN_00204e40();
 void FUN_00207580(int, int);
 Handle_207f60 *FUN_00204540(const char *);
 void FUN_00207080(int);
 void FUN_00207f60();
};
void Object::FUN_00207f60() {
 if (dirty) { FUN_00204e40(); dirty=0; }
 Manager_207f60 *manager=FUN_001c3d90()->manager;
 int count=manager->list.FUN_001c7520();
 for(int i=0;i<count;++i) {
  int id=((Item_207f60 *)((owners::Thing_1c7f80 *)manager)->FUN_001c7f80((unsigned int)i))->id;
  char buffer[32];
  sprintf(buffer,"%s_r%03d",name,id);
  FUN_00207580(id,1);
  Handle_207f60 *h=FUN_00204540(buffer);
  int a,b,c,d;
  h->resource->v9(&a,&b,&c,&d);
  h->resource->v11();
  FUN_00207080(id);
 }
}
} // namespace fn_00207f60

