// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00103340..0x001047b0 (kind game, layer game, confidence high), dominant class COccupationAgent
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f34ce6e5 {
#define TREE_TU_END }
namespace fn_f34ce6e5 {} using namespace fn_f34ce6e5;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f34ce6e5 {
class Thing_103340 {
  public:
    virtual void Use();
};
class Str_103340 {
  public:
};
class CCharacterAgent_103340 {
  public:
    virtual void Init();
    CCharacterAgent_103340(const char*);
};
class COccupationAgent_103340 : public CCharacterAgent_103340 {
  public:
    virtual void Own();
    char pad04[0x58];
    Thing_103340* m5c;
    int m60;
    unsigned char m64;
    char pad65[0x3f];
    unsigned char mA4, mA5;
    char pA6[2];
    int mA8, mAC, mB0, mB4, mB8;
    float mBC;
    unsigned char mC0;
    char pC1[3];
    float mC4;
    unsigned char mC8;
    char pC9[3];
    int mCC, mD0, mD4, mD8, mDC, mE0, mE4, mE8, mEC;
    COccupationAgent_103340(const char*);
};
struct Thing_103410 {
    virtual void f0();
    virtual void f1();
};
struct COccupationAgent_nv_103410 {
    void cleanup_000fc630();
};
struct Inner_1035e0 {
    char pad[0x14];
    void* value;
};
struct Root_1035e0 {
    char pad[0x60];
    Inner_1035e0* inner;
};
struct Child { char pad[0x8c]; int value; unsigned char flag; char pad2[3]; int other; int otherCopy; };
struct Object { char pad[0x5c]; Child *child; char pad2[0x5c]; int value; unsigned char flag; char pad3[3]; int other; void FUN_001035f0(int v, unsigned char f, int o); };
struct Vec3_103640 {
    float x, y, z;
};
class Waypoint;
class Anchor_103640 {
public:
    char FUN_00059a50(Vec3_103640 *out);
};
class Pawn_103640 {
public:
    char pad0[0x10];
    Anchor_103640 *anchor;
};
class Holder_103640 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual Pawn_103640 *pawn();
};
class Marker_103640;
class Target_103640 {
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
    virtual void setPosition(Vec3_103640 pos);
    char pad_[0x7c - 4];
    Vec3_103640 home;
    void FUN_001048d0(Marker_103640 *m);
    void FUN_00104c60(World *g, Vec3_103640 *a, Vec3_103640 *b, int bc, unsigned int c0, int c4, int zero);
};
class Locator {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual Vec3_103640 *position(Vec3_103640 *out);
};
struct Registry_103640 {
    char pad0[0x28];
    struct Index_103640 *index;
};
struct Index_103640 {
    Locator *FUN_001fd780(const char *name);
};
} // namespace fn_f34ce6e5
struct World {
    char pad0[0x28];
    Index_103640 *index;
};
namespace fn_f34ce6e5 {
int FUN_000964a0(char *buf, int size, const char *fmt, ...);
union NameSlot_103640 {
    const char *name;
    float y;
};
class Marker_103640 {
public:
    char pad0[0x58];
    Holder_103640 *holder;
    Target_103640 *target;
    char pad60[4];
    char label[0x40];
    char pad_a4;
    unsigned char active;
    char pad_a6[2];
    Vec3_103640 pos;
    int b4;
    int b8;
    int bc;
    unsigned char c0;
    char pad_c1[3];
    int c4;

    void FUN_00103640(NameSlot_103640 name, float x, float y, float z);
};
struct AgentVtable { void *slots[8]; void (__fastcall *f8)(COccupationAgent *, void *, int); };
struct OccupationDisplay { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual int f6(const char *, unsigned int); char pad[0xe4]; unsigned char flag; };
struct OccupationOther { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(int); };
struct Vec_103a50 { float x,y,z; };
struct Points { char pad[20]; int count;  };
struct Position_103a50 { void FUN_00059a50(Vec_103a50*); };
struct Result_103a50 { char pad[16]; Position_103a50* position; };
struct Provider_103a50 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual Result_103a50* v6(); };
struct COccupationAgent_103a50 { char pad[0x58]; Provider_103a50* provider; char p5c[4]; Points* points; char p64[0x54]; int selected; void target(); };
struct COccupationAgent_103b60;
struct Vector { float x,y,z; };
struct Source_103b60 { void FUN_00059a50(Vector*); };
struct View { char pad[0x10]; Source_103b60* source; };
struct Provider_103b60 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual View* v6(); };
struct Resource_103b60 {  };
struct Lookup_103b60 { Resource_103b60* FUN_00106230(const char*); };
struct Context { char pad[0x18]; Lookup_103b60* lookup; };
struct Manager_103b60 { void FUN_001048d0(COccupationAgent_103b60*); int FUN_00104c60(Context*,Vector*,int,int,unsigned int,int,int); };
struct COccupationAgent_103b60 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
 int pad4; int state; char padC[0x4c]; Provider_103b60* provider; Manager_103b60* manager; Resource_103b60* resource; char name[0x40]; unsigned char enabled; char padA5[0x13]; int selection; int option; unsigned char flag; char padC1[3]; int extra;
 void FUN_00103a50();
 int target(Context* context,const char* text,unsigned char mode);
};


// 0x00103340 FUN_00103340 (181 B): matches/0x00103340.cpp
// sym: ??0COccupationAgent_103340@fn_f34ce6e5@@QAE@PBD@Z
COccupationAgent_103340::COccupationAgent_103340(const char* name) : CCharacterAgent_103340(name) {
    m60 = 0;
    _ReadWriteBarrier();
    mA4 = 1;
    mA5 = 0;
    mA8 = 0;
    mAC = 0;
    mB0 = 0;
    mB4 = -1;
    mB8 = 0;
    mC0 = 0;
    mC8 = 0;
    _ReadWriteBarrier();
    mBC = 1.0f;
    mC4 = 1.0f;
    mCC = 0;
    mD0 = 0;
    mD4 = 0;
    mD8 = 0;
    mDC = 0;
    mE0 = 0;
    mE4 = 0;
    mE8 = 0;
    _ReadWriteBarrier();
    mEC = 0;
    m64 = 0;
    Thing_103340* t = ((Thing_103340 *)((owners::Obj_fefc0 *)(((Str_103340*)name)))->FUN_000fefc0());
    m5c = t;
    t->Use();
}

} // namespace fn_f34ce6e5

// 0x00103400 COccupationAgent::vfunc_10 (6 B): matches/0x00103400.cpp
// sym: ?vfunc_10@COccupationAgent@@UAEHXZ
// Same code shape as 0x0004e0b0 (propagated; names are from that function)
int COccupationAgent::vfunc_10() {
    return 2;
}


// 0x00103410 FUN_00103410 (32 B): matches/0x00103410.cpp
// sym: ?FUN_00103410@COccupationAgent@@QAEXXZ
// Same code shape as 0x000ff240 (propagated; names are from that function)
void COccupationAgent::FUN_00103410() {
    *(void**)this = &handvtable;
    (*(Thing_103410 * *)&this->f_5c)->f1();
    (*(Thing_103410 * *)&this->f_5c) = 0;
    ((COccupationAgent_nv_103410*)this)->cleanup_000fc630();
}


// 0x00103430 COccupationAgent::vfunc_9 (115 B): matches/0x00103430.cpp [wrapped: conflict: COccupationAgent]
// sym: ?vfunc_9@COccupationAgent@fn_00103430@@UAEXXZ
namespace fn_00103430 {
extern "C" void _ReadWriteBarrier();
class IUnk {
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
};
class COccupationAgent {
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
    char pad4[4];
    float f8;
    char padC[0x50];
    IUnk* p5c;
    int i60;
    char b64;
    char pad65[0x3f];
    char bA4;
    char padA5[0xf];
    int iB4;
    int iB8;
    float fBC;
    char bC0;
    char padC1[3];
    float fC4;
    int iC8;
    int iCC;
    int iD0;
    int iD4;
    int iD8;
    int iDC;
    char padE0[0xc];
    int iEC;
};
void COccupationAgent::vfunc_9() {
    i60 = 0;
    bA4 = 1;
    b64 = 0;
    iB4 = -1;
    iB8 = 0;
    fBC = 1.0f;
    f8 = 10.0f;
    p5c->v9();
    bC0 = 0;
    fC4 = 1.0f;
    _ReadWriteBarrier();
    iD4 = 0;
    iD0 = 0;
    iCC = 0;
    iD8 = 0;
    iDC = 0;
    iEC = 0;
}
} // namespace fn_00103430


// 0x001034b0 FUN_001034b0 (20 B): matches/0x001034b0.cpp
// sym: ?FUN_001034b0@Obj_1034b0@owners@@QAEXE@Z
void owners::Obj_1034b0::FUN_001034b0(unsigned char value) {
    if (p)
        p[0x91] = value;
}

namespace fn_f34ce6e5 {

// 0x001034d0 FUN_001034d0 (4 B): matches/0x001034d0.cpp
// sym: ?FUN_001034d0@fn_f34ce6e5@@YIHPAX@Z
// Same code shape as 0x00092330 (propagated; names are from that function)
hulk_intptr __fastcall FUN_001034d0(void* p) {
    return (hulk_intptr)p + 100;
}

} // namespace fn_f34ce6e5

// 0x001034e0 FUN_001034e0 (247 B): equivalent/0x001034e0.cpp [wrapped: conflict: DAT_004dd700]
// sym: ?FUN_001034e0@COccupationAgent_1034e0@fn_001034e0@@QAE_NXZ
namespace fn_001034e0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_001034e0 @ 0x001034e0
struct Vector { unsigned x,y,z; };
struct Entry_1034e0 { Vector position; int next; };
struct Table_1034e0 { char pad[0x14]; int count;  };
struct Transform_1034e0 { void FUN_00059a50(Vector* output); };
struct Object { char pad[0x10]; Transform_1034e0* transform; };
struct Provider_1034e0 { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual Object* slot6(); };
struct Destination_1034e0 { void FUN_00104c60(unsigned,Vector*,Vector*,unsigned,unsigned,unsigned,unsigned); };

#define DAT_004dd700 (*(unsigned *)&::DAT_004dd700)

struct COccupationAgent_1034e0 {
 char pad0[0x58]; Provider_1034e0* provider; Destination_1034e0* destination; Table_1034e0* table; char pad1[0x54]; int index; unsigned parameter; unsigned char flag; char pad2[3]; unsigned option; char pad3[4]; unsigned a,b,c,d,e; char pad4[12]; unsigned f;
 bool FUN_001034e0();
};
bool COccupationAgent_1034e0::FUN_001034e0() {
 if (!table) return false;
 c=0; b=0; a=0; d=0; e=0; f=0;
 if(index<0) return false;
 Entry_1034e0* entry=((Entry_1034e0 *)((owners::Target_106160 *)table)->FUN_00106160(index));
 index=entry->next;
 if(index>=table->count) index=0;
 if(index==-1) return false;
 Object* object=provider->slot6();
 Vector origin; origin.x=0; origin.y=0; origin.z=0;
 object->transform->FUN_00059a50(&origin);
 entry=((Entry_1034e0 *)((owners::Target_106160 *)table)->FUN_00106160(index));
 Vector position=entry->position;
 destination->FUN_00104c60(DAT_004dd700,&origin,&position,parameter,(unsigned)flag,option,0);
 return true;
}
} // namespace fn_001034e0
#undef DAT_004dd700

namespace fn_f34ce6e5 {

// 0x001035e0 FUN_001035e0 (12 B): matches/0x001035e0.cpp
// sym: ?FUN_001035e0@fn_f34ce6e5@@YIPAXPAURoot_1035e0@1@@Z
void* __fastcall FUN_001035e0(Root_1035e0* p) {
    if (!p->inner)
        return 0;
    return p->inner->value;
}


// 0x001035f0 FUN_001035f0 (74 B): equivalent/0x001035f0.cpp
// sym: ?FUN_001035f0@Object@fn_f34ce6e5@@QAEXHEH@Z
// STATUS: equivalent (tools/equiv.py level 3: 2986 inputs, branch coverage 2/2)
// FUN_001035f0 @ 0x001035f0
void Object::FUN_001035f0(int v, unsigned char f, int o) { value=v; flag=f; other=o; Child *c=child; if(c) { c->flag=f; c->value=v; c->other=o; c->otherCopy=o; } }


// 0x00103640 FUN_00103640 (328 B): equivalent/0x00103640.cpp
// sym: ?FUN_00103640@Marker_103640@fn_f34ce6e5@@QAEXTNameSlot_103640@2@MMM@Z
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 4/4)
// FUN_00103640 @ 0x00103640
void Marker_103640::FUN_00103640(NameSlot_103640 name, float x, float y, float z)
{
    struct Frame {
        Vec3_103640 v1;
        Vec3_103640 v4;
        Vec3_103640 v2;
        Vec3_103640 v3;
    } fr;

    if (target == 0)
        return;
    Pawn_103640 *p = holder->pawn();
    const char *nm = name.name;
    FUN_000964a0(label, 0x40, "%s", nm);
    Locator *loc = DAT_004dd700->index->FUN_001fd780(nm);
    if (loc == 0)
        return;
    active = 1;
    z = z + loc->position(&fr.v1)->z;
    name.y = y + loc->position(&fr.v2)->y;
    float nx = x + loc->position(&fr.v3)->x;
    pos.z = z;
    pos.x = nx;
    pos.y = name.y;
    target->setPosition(pos);
    p->anchor->FUN_00059a50(&fr.v4);
    b8 = 0;
    target->FUN_001048d0(this);
    fr.v1 = target->home;
    target->FUN_00104c60(DAT_004dd700, &fr.v4, &fr.v1, bc, c0, c4, 0);
}

} // namespace fn_f34ce6e5

// 0x00103790 COccupationAgent::vfunc_7 (92 B): equivalent/0x00103790.cpp
// sym: ?vfunc_7@COccupationAgent@@UAEXH@Z
// STATUS: equivalent (tools/equiv.py level 3: 20024 inputs, branch coverage 4/4)
// COccupationAgent::vfunc_7 @ 0x00103790
void COccupationAgent::vfunc_7(int value) { if ((char)value) { AgentVtable *table = *(AgentVtable **)this; OccupationDisplay *d = (*(OccupationDisplay * *)&this->f_58); int result = d->f6(d->flag ? "Occ-L" : "Occ", d->flag ? 0xffffff00 : 0xffffffff); table->f8(this, 0, result); (*(OccupationOther * *)&this->f_5c)->f7(value); } (*(OccupationOther * *)&this->f_5c)->f7(value); }


// 0x001037f0 COccupationAgent::vfunc_2 (53 B): matches/0x001037f0.cpp [wrapped: conflict: COccupationAgent]
// sym: ?vfunc_2@COccupationAgent@fn_001037f0@@UAEPAV12@E@Z
namespace fn_001037f0 {
// Same code shape as 0x000ffeb0 (propagated; names are from that function)
struct Thing_1037f0 {
    virtual void a();
    virtual void b();
};
extern int hulk_at_0040d468;
struct COccupationAgent_1037f0 {
    void run_000fc630();
};
void __cdecl thunk_FUN_00267090(void*);
class COccupationAgent {
  public:
    virtual void v0();
    virtual void v1();
    virtual COccupationAgent* vfunc_2(unsigned char);
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
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    char pad[0x58];
    Thing_1037f0* thing;
};
COccupationAgent* COccupationAgent::vfunc_2(unsigned char param) {
    Thing_1037f0* t = thing;
    *(hulk_intptr*)this = (hulk_intptr)&hulk_at_0040d468;
    t->b();
    thing = 0;
    ((COccupationAgent_1037f0*)this)->run_000fc630();
    if (param & 1)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_001037f0


// 0x00103830 COccupationAgent::vfunc_3 (538 B): equivalent/0x00103830.cpp [wrapped: conflict: COccupationAgent; World]
// sym: ?vfunc_3@COccupationAgent@fn_00103830@@UAEMPAUCtx_103830@2@H@Z
namespace fn_00103830 {
// STATUS: equivalent (tools/equiv.py level 3: 88 inputs, branch coverage 28/34, incomplete)
// COccupationAgent::vfunc_3 @ 0x00103830
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


struct Vec3_103830 {
    float x, y, z;
};

struct Locator {
    bool FUN_00059a50(Vec3_103830 *out);
};

struct Target_103830 {
    char pad0[0x40];
    Vec3_103830 pos;
};

struct Body_103830 {
    char pad0[0x10];
    Locator *locator;
    char pad14[0x328 - 0x14];
    Target_103830 *target;
    char pad32c[0x1b0c - 0x32c];
    float f1b0c;
    float f1b10;
    char pad1b14[0x1d30 - 0x1b14];
    float f1d30;
    float f1d34;
    float f1d38;
    float f1d3c;
    char pad1d40[0x2149 - 0x1d40];
    char f2149;
};

struct Part_103830 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual Body_103830 *v6();
    char pad04[0xe8 - 4];
    char flagE8;
};

struct Registry_103830 {
    void *FUN_00106230(char *flag);
};

struct Ctx_103830 {
    char pad0[0x18];
    Registry_103830 *registry;
};

struct Clock_103830 {
    float FUN_00086040();
};

struct World {
    char pad0[0x58];
    Clock_103830 *clock;
};


class COccupationAgent {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual float vfunc_3(Ctx_103830 *ctx, int arg);
    char pad04[8 - 4];
    float limit;
    char pad0c[0x58 - 0xc];
    Part_103830 *part;
    char pad5c[4];
    void *handle;
    char hasHandle;
    char pad65[0xa4 - 0x65];
    char fa4;
    char fa5;
    float FUN_000fc4e0(Ctx_103830 *ctx, int arg);
};

float COccupationAgent::vfunc_3(Ctx_103830 *ctx, int arg)
{
    FUN_000fc4e0(ctx, arg);
    Body_103830 *body = part->v6();
    bool hit = false;

    if (body->f2149) {
        limit = 0.0f;
    } else if (fa5) {
        if (part->flagE8)
            limit = 90.0f;
        else
            limit = 10.0f;
    } else if (!hasHandle) {
        limit = 0.0f;
    } else {
        if (handle == 0) {
            handle = ctx->registry->FUN_00106230(&hasHandle);
            if (handle == 0) {
                limit = 0.0f;
                hasHandle = 0;
                return 0.0f;
            }
            fa4 = 1;
        }
        if (part->flagE8)
            limit = 90.0f;
        else
            limit = 10.0f;
    }

    if (!(limit == 0.0f)) {
        if (body->f1d34 >= 0.0f || body->f1d30 >= 0.0f) {
            Target_103830 *tgt = body->target;
            if (tgt != 0) {
                Vec3_103830 d;
                body->locator->FUN_00059a50(&d);
                double dx = d.x - tgt->pos.x;
                double dy = d.y - tgt->pos.y;
                double dz = d.z - tgt->pos.z;
                double len = sqrt(dz * dz + dy * dy + dx * dx);
                if (len <= body->f1d34) {
                    if (body->f1d30 == 0.0f || (double)body->f1b10 - body->f1d30 >= body->f1b0c) {
                        limit = 0.0f;
                        hit = true;
                    }
                }
            }
        }
    }

    float r = DAT_004dd700->clock->FUN_00086040();
    if (hit) {
        part->flagE8 = 0;
        body->f1d3c = r;
        return limit;
    }
    if (body->f1d3c == 0.0f)
        return limit;
    double s = (double)body->f1d38 + body->f1d3c;
    if (r < s) {
        limit = 0.0f;
        return limit;
    }
    body->f1d3c = 0.0f;
    part->flagE8 = 1;
    return limit;
}
} // namespace fn_00103830
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f34ce6e5 {

// 0x00103a50 FUN_00103a50 (263 B): equivalent/0x00103a50.cpp
// sym: ?target@COccupationAgent_103a50@fn_f34ce6e5@@QAEXXZ
// STATUS: equivalent (tools/equiv.py level 3: 16351 inputs, branch coverage 10/10)
// FUN_00103a50 @ 0x00103a50
void COccupationAgent_103a50::target() {
 if (!points) return;
 selected=0;
 Vec_103a50 first=*((Vec_103a50 *)((owners::Target_106160 *)points)->FUN_00106160(0));
 Vec_103a50 origin;
 provider->v6()->position->FUN_00059a50(&origin);
 int count=points->count;
 double x=(double)first.x-origin.x, y=(double)first.y-origin.y, z=(double)first.z-origin.z;
 float best=(float)sqrt(z*z+y*y+x*x);
 for(int i=1;i<count;++i) {
  Vec_103a50* p=((Vec_103a50 *)((owners::Target_106160 *)points)->FUN_00106160(i));
  float dx=(float)((double)p->x-origin.x);
  double dy=(double)p->y-origin.y, dz=(double)p->z-origin.z;
  double distance=sqrt(dz*dz+dy*dy+(double)dx*dx);
  if(distance < best && distance > 0.01) { best=(float)distance; selected=i; }
 }
}


// 0x00103b60 FUN_00103b60 (199 B): equivalent/0x00103b60.cpp
// sym: ?target@COccupationAgent_103b60@fn_f34ce6e5@@QAEHPAUContext@2@PBDE@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_00103b60 @ 0x00103b60
int COccupationAgent_103b60::target(Context* context,const char* text,unsigned char mode) {
 v9();
 FUN_000964a0(name,0x40,"%s",text);
 resource=context->lookup->FUN_00106230(name);
 if (!resource) { name[0]=0; state=0; return 0; }
 enabled=1;
 Vector position;
 provider->v6()->source->FUN_00059a50(&position);
 if(mode) { selection=0; manager->FUN_001048d0(this); } else FUN_00103a50();
 int result=((int)((owners::Target_106160 *)resource)->FUN_00106160(selection));
 return manager->FUN_00104c60(context,&position,result,option,flag,extra,0);
}

} // namespace fn_f34ce6e5
