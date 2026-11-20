// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0028fe80..0x00291bc0 (kind game, layer engine, confidence high), dominant class pure3d::prop::StatePropDataLoader
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/pure3d/prop.h"


// 0x00290bf0 pure3d::prop::StatePropDataLoader::vfunc_5 (3691 B): equivalent/0x00290bf0.cpp [wrapped: macros]
// sym: ?vfunc_5@StatePropDataLoader@fn_00290bf0@@QAEXPAPAUProp@2@PA_KPAUReader@2@PAUInventory@2@@Z @4e49f7fcd99a @w706733634734 @v263d0b57c081
inline void *operator new(size_t, void *p) throw() { return p; }
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_00290bf0 {
// STATUS: equivalent (tools/equiv.py level 3: 2686 inputs, branch coverage 64/64)
// pure3d::prop::StatePropDataLoader::vfunc_5 @ 0x00290bf0
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
extern "C" void *memcpy(void *, const void *, unsigned int);
#endif


struct Stream {
    HULK_TYPE64(char, bool) FUN_002647e0(void *dest, unsigned int count, unsigned int size, int flag);
};

struct Reader {
    char pad[0x284];
    Stream *stream;
    HULK_TYPE64(char, bool) FUN_002669f0();
    int FUN_00266a30();   // (x64t15) i32 as defined (natively a hulk_intptr result did not bind)
    void FUN_00266be0();
};

struct NameField {
    unsigned int lo, hi;
    void FUN_0027b040(const char *s);
    void FUN_0028fe80(const char *s);
};

namespace physics {
class CollisionObject;
class PhysicsObject;
class WorldCollisionObject;
}
namespace pure3d {
class CompositeDrawable;
}

extern "C" char DAT_003fef7c[], DAT_0042cc90[], DAT_0042cc98[], DAT_00425b3c[];   // (fix2) the game's caster vftables
namespace content {
namespace LoadInventory {
template <class T> struct DynamicCaster {   // (fix2) was polymorphic (virtual void v0();): clang's own vftable natively,
  public:                          // the game's by address now, stored by each instantiation's constructor
    void *vftable;
    DynamicCaster();
};
}
}

struct RefObj {
    virtual void v0();
    virtual void v1();
};

struct ResObj {
    virtual void v0();
    virtual void v1();
    char pad04[4];
    unsigned int idLo;
    unsigned int idHi;
};

struct Inventory {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void *v3(void *caster, unsigned __int64 key);
};

struct Rec10a {
    NameField name;
    char b8;
};
struct Rec20 {
    NameField name;
    char b8;
    char pad9[3];
    hulk_intptr fc;
    char b10;
    char pad11[3];
    hulk_intptr f14;
    hulk_intptr f18;
    hulk_intptr f1c;
};
struct Rec10b {
    NameField name;
    hulk_intptr f8;
    hulk_intptr fc;
};
struct Rec30 {
    NameField name;
    unsigned int idLo;
    unsigned int idHi;
    hulk_intptr f10;
    hulk_intptr f14;
    hulk_intptr f18;
    hulk_intptr f1c;
    hulk_intptr f20;
    hulk_intptr f24;
    hulk_intptr f28;
    int f2c;
};
struct Rec58 {
    hulk_intptr f0, f4, f8, fc, f10, f14;
    hulk_intptr f18, f1c, f20;
    char pad24[4];
    NameField n28;
    NameField n30;
    NameField n38;
    NameField n40;
    hulk_intptr f48;
    hulk_intptr f4c;
    hulk_intptr f50;
    char pad54[4];
};
struct Sub {
    char b0;
    char pad1[3];
    hulk_intptr f4;
    hulk_intptr f8;
};

struct StateObj : RefObj {
    char pad04[4];
    NameField name;
    Sub *f10;
    char pad14[4];
    Rec10a *a18;
    char pad1c[4];
    Rec20 *a20;
    char pad24[4];
    Rec10b *a28;
    char pad2c[4];
    Rec30 *a30;
    char pad34[4];
    Rec10b *a38;
    char pad3c[4];
    NameField *a40;
    char pad44[4];
    Rec58 *a48;
    RefObj *f4c;
    char pad50[8];
    StateObj *FUN_0028ff00(hulk_intptr a, hulk_intptr b, hulk_intptr c, hulk_intptr d, hulk_intptr e, hulk_intptr f, hulk_intptr g);
};

struct Prop {
    char pad00[8];
    NameField name;
    char pad10[0x1c - 0x10];
    StateObj **arr1c;
    char pad20[0x28 - 0x20];
    NameField *arr28;
    char pad2c[0x38 - 0x2c];
    Prop *FUN_00290b30(ResObj *res, void *obj2, void *obj3, hulk_intptr x2, hulk_intptr x3);
};

extern "C" int __cdecl FUN_00267760(char *buf, int size, const char *fmt, ...);
void *FUN_00263ea0(unsigned int size);
template <> inline content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable>::DynamicCaster() { vftable = DAT_003fef7c; }
template <> inline content::LoadInventory::DynamicCaster<physics::CollisionObject>::DynamicCaster() { vftable = DAT_0042cc90; }
template <> inline content::LoadInventory::DynamicCaster<physics::PhysicsObject>::DynamicCaster() { vftable = DAT_0042cc98; }
template <> inline content::LoadInventory::DynamicCaster<physics::WorldCollisionObject>::DynamicCaster() { vftable = DAT_00425b3c; }

typedef content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable> CasterComp;
typedef content::LoadInventory::DynamicCaster<physics::CollisionObject> CasterColl;
typedef content::LoadInventory::DynamicCaster<physics::PhysicsObject> CasterPhys;
typedef content::LoadInventory::DynamicCaster<physics::WorldCollisionObject> CasterWorld;

class StatePropDataLoader {
public:
    void vfunc_5(Prop **out, unsigned __int64 *outId, Reader *r, Inventory *inv);
};

union Slot {   // (sweep2) a frame word the code uses as a caster, a pointer, a byte offset or a 4-byte read
    volatile int i;
    volatile hulk_intptr w;
    void *c;
};
struct Frame {   // (sweep2) the frame by its 32-bit offsets, as fields: natively each word keeps its own slot (a byte
                 // view put the 8-byte casters and pointers over their neighbours)
    char pad00[1];
    volatile unsigned char b01;   // +0x01
    volatile unsigned char b02;   // +0x02
    volatile unsigned char b03;   // +0x03
    volatile unsigned char b04;   // +0x04
    volatile unsigned char b05;   // +0x05
    volatile unsigned char b06;   // +0x06
    volatile unsigned char b07;   // +0x07
    volatile unsigned char b08;   // +0x08
    volatile unsigned char b09;   // +0x09
    volatile unsigned char b0a;   // +0x0a
    volatile unsigned char b0b;   // +0x0b
    Slot s0c;                     // +0x0c
    Slot s10;                     // +0x10
    char pad14[3];
    volatile unsigned char b17;   // +0x17
    volatile unsigned char b18;   // +0x18
    volatile unsigned char b19;   // +0x19
    volatile unsigned char b1a;   // +0x1a
    volatile unsigned char b1b;   // +0x1b
    Slot s1c;                     // +0x1c
    volatile hulk_intptr w20;     // +0x20
    volatile int i24;             // +0x24
    Slot s28;                     // +0x28
    volatile hulk_intptr w2c;     // +0x2c
    volatile hulk_intptr w30;     // +0x30
    volatile hulk_intptr w34;     // +0x34
    volatile hulk_intptr w38;     // +0x38
    volatile hulk_intptr w3c;     // +0x3c
    volatile int i40;             // +0x40
    volatile int i44;             // +0x44
    volatile int i48;             // +0x48
    volatile int i4c;             // +0x4c
    volatile int i50;             // +0x50
    volatile int i54;             // +0x54
    volatile int i58;             // +0x58
    volatile int i5c;             // +0x5c
    volatile int i60;             // +0x60
    volatile int i64;             // +0x64
    volatile int i68;             // +0x68
    volatile int i6c;             // +0x6c
    volatile int i70;             // +0x70
    volatile int i74;             // +0x74
    volatile int i78;             // +0x78
    volatile int i7c;             // +0x7c
    volatile int i80;             // +0x80
    volatile int i84;             // +0x84
    volatile int i88;             // +0x88
    volatile int i8c;             // +0x8c
    volatile int i90;             // +0x90
    volatile int i94;             // +0x94
    volatile int i98;             // +0x98
    volatile int i9c;             // +0x9c
    volatile int ia0;             // +0xa0
    volatile int ia4;             // +0xa4
    volatile int ia8;             // +0xa8
    volatile int iac;             // +0xac
    volatile int ib0;             // +0xb0
    volatile int ib4;             // +0xb4
    volatile int ib8;             // +0xb8
    volatile int ibc;             // +0xbc
    volatile int ic0;             // +0xc0
    volatile int ic4;             // +0xc4
    volatile int ic8;             // +0xc8
    volatile int icc;             // +0xcc
    volatile int id0;             // +0xd0
    Slot sd4;                     // +0xd4
    volatile int id8;             // +0xd8
    volatile hulk_intptr wdc;     // +0xdc
    volatile int ie0;             // +0xe0
    volatile int ie4;             // +0xe4
    volatile int ie8;             // +0xe8
    char s0ec[0x100];            // +0xec
    char s1ec[0x100];            // +0x1ec
    char s2ec[0x100];            // +0x2ec
};

void StatePropDataLoader::vfunc_5(Prop **out, unsigned __int64 *outId, Reader *r, Inventory *inv)
{
    Frame f;

    r->stream->FUN_002647e0((char *)&f.i24, 1, 4, 1);
    r->stream->FUN_002647e0((char *)&f.b01, 1, 1, 1);
    unsigned int len = f.b01;
    r->stream->FUN_002647e0(f.s1ec, len, 1, 1);
    r->stream->FUN_002647e0((char *)&f.b01, 1, 1, 1);
    *(f.s1ec + len) = 0;
    len = f.b01;
    r->stream->FUN_002647e0(f.s0ec, len, 1, 1);
    *(f.s0ec + len) = 0;

    unsigned __int64 key = FUN_0027b020(f.s0ec);
    CasterComp *c1 = new ((char *)&f.s0c) CasterComp;
    ResObj *res = (ResObj *)inv->v3(c1, key);
    if (res == 0)
        FUN_00267760(f.s2ec, 0x100, "StatePropDataLoader::LoadObject():  Can not find the composite drawable with name %s to use with the state prop with name %s.", f.s0ec, f.s1ec);

    f.s10.w = 0;
    CasterColl *c2 = new ((char *)&f.s1c) CasterColl;
    unsigned __int64 rid = ((unsigned __int64)res->idHi << 32) | res->idLo;
    f.s28.w = (hulk_intptr)inv->v3(c2, rid);
    if (f.s28.w != 0) {
        CasterPhys *c3 = new ((char *)&f.s10) CasterPhys;
        unsigned __int64 rid2 = ((unsigned __int64)res->idHi << 32) | res->idLo;
        f.s10.w = (hulk_intptr)inv->v3(c3, rid2);
    }

    r->stream->FUN_002647e0((char *)&f.s1c, 1, 4, 1);
    hulk_uintptr ver = f.i24;
    hulk_intptr x3 = 0;
    if (ver >= 3) {
        r->stream->FUN_002647e0((char *)&f.s0c, 1, 4, 1);
        x3 = f.s0c.i;
    }
    void *mem = FUN_00263ea0(0x38);
    Prop *prop;
    if (mem)
        prop = ((Prop *)mem)->FUN_00290b30(res, (void *)f.s28.w, (void *)f.s10.w, f.s1c.i, x3);
    else
        prop = 0;
    f.w20 = (hulk_intptr)prop;
    NameField *pname = &prop->name;
    f.wdc = (hulk_intptr)pname;
    pname->FUN_0027b040(f.s1ec);

    if (r->FUN_002669f0()) {
        f.s10.w = 0;
        f.w30 = 0;
        do {
            unsigned int sub = (unsigned int)r->FUN_00266a30() - 0x8020001;
            if (sub == 7) {
                NameField *rec = (NameField *)((char *)((Prop *)f.w20)->arr28 + f.w30);
                r->stream->FUN_002647e0((char *)&f.b18, 1, 1, 1);
                len = f.b18;
                r->stream->FUN_002647e0(f.s0ec, len, 1, 1);
                *(f.s0ec + len) = 0;
                rec->FUN_0027b040(f.s0ec);
                r->stream->FUN_002647e0((char *)&f.b19, 1, 1, 1);
                len = f.b19;
                r->stream->FUN_002647e0(f.s0ec, len, 1, 1);
                *(f.s0ec + len) = 0;
                rec->FUN_0028fe80(f.s0ec);
                f.w30 += 0x10;
            } else if (sub == 0 || sub == 6 || sub == 8) {
                r->stream->FUN_002647e0((char *)&f.b17, 1, 1, 1);
                len = f.b17;
                r->stream->FUN_002647e0(f.s0ec, len, 1, 1);
                *(f.s0ec + len) = 0;
                r->stream->FUN_002647e0((char *)&f.i68, 1, 4, 1);
                f.b1a = (f.i68 != 0);
                r->stream->FUN_002647e0((char *)&f.i40, 1, 4, 1);
                r->stream->FUN_002647e0((char *)&f.i58, 1, 4, 1);
                r->stream->FUN_002647e0((char *)&f.ie0, 1, 4, 1);
                r->stream->FUN_002647e0((char *)&f.i60, 1, 4, 1);
                r->stream->FUN_002647e0((char *)&f.ia8, 1, 4, 1);
                r->stream->FUN_002647e0((char *)&f.id0, 1, 4, 1);
                hulk_intptr ebp = 0;
                hulk_intptr edi = 0;
                f.s0c.w = 0;
                if ((unsigned int)f.i24 >= 2) {
                    r->stream->FUN_002647e0((char *)&f.i48, 1, 4, 1);
                    f.s0c.w = f.i48;
                }
                if ((unsigned int)f.i24 >= 3) {
                    r->stream->FUN_002647e0((char *)&f.ia0, 1, 4, 1);
                    ebp = f.ia0;
                }
                if ((unsigned int)f.i24 >= 4) {
                    r->stream->FUN_002647e0((char *)&f.i50, 1, 4, 1);
                    edi = f.i50;
                }
                void *m2 = FUN_00263ea0(0x58);
                StateObj *so;
                if (m2)
                    so = ((StateObj *)m2)->FUN_0028ff00(f.i60, f.s0c.w, f.ia8, f.i58, f.ie0, ebp, edi);
                else
                    so = 0;
                so->name.FUN_0027b040(f.s0ec);
                so->f10->b0 = f.b1a;
                so->f10->f8 = f.id0;
                so->f10->f4 = f.i40;
                if (r->FUN_002669f0()) {
                    f.s0c.w = 0;
                    f.s1c.w = 0;
                    f.s28.w = 0;
                    f.w3c = 0;
                    f.w34 = 0;
                    f.w2c = 0;
                    f.w38 = 0;
                    do {
                        unsigned int csub = (unsigned int)r->FUN_00266a30() - 0x8020002;
                        if (csub == 0) {
                            Rec10a *rec = (Rec10a *)((char *)so->a18 + f.w38);
                            r->stream->FUN_002647e0((char *)&f.b0a, 1, 1, 1);
                            len = f.b0a;
                            r->stream->FUN_002647e0(f.s0ec, len, 1, 1);
                            *(f.s0ec + len) = 0;
                            rec->name.FUN_0027b040(f.s0ec);
                            r->stream->FUN_002647e0((char *)&f.ib0, 1, 4, 1);
                            rec->b8 = (f.ib0 != 0);
                            f.w38 += 0x10;
                        } else if (csub == 1) {
                            Rec20 *rec = (Rec20 *)((char *)so->a20 + f.w2c);
                            r->stream->FUN_002647e0((char *)&f.b0b, 1, 1, 1);
                            len = f.b0b;
                            r->stream->FUN_002647e0(f.s0ec, len, 1, 1);
                            *(f.s0ec + len) = 0;
                            rec->name.FUN_0027b040(f.s0ec);
                            r->stream->FUN_002647e0((char *)&f.i70, 1, 4, 1);
                            rec->b8 = (f.i70 != 0);
                            r->stream->FUN_002647e0((char *)&f.ie8, 1, 4, 1);
                            rec->fc = f.ie8;
                            r->stream->FUN_002647e0((char *)&f.i78, 1, 4, 1);
                            rec->b10 = (f.i78 != 0);
                            r->stream->FUN_002647e0((char *)&f.ib8, 1, 4, 1);
                            rec->f14 = f.ib8;
                            r->stream->FUN_002647e0((char *)&f.i80, 1, 4, 1);
                            rec->f18 = f.i80;
                            r->stream->FUN_002647e0((char *)&f.id8, 1, 4, 1);
                            rec->f1c = f.id8;
                            f.w2c += 0x20;
                        } else if (csub == 2) {
                            Rec10b *rec = (Rec10b *)((char *)so->a28 + f.w34);
                            r->stream->FUN_002647e0((char *)&f.b04, 1, 1, 1);
                            len = f.b04;
                            r->stream->FUN_002647e0(f.s0ec, len, 1, 1);
                            *(f.s0ec + len) = 0;
                            rec->name.FUN_0027b040(f.s0ec);
                            r->stream->FUN_002647e0((char *)&f.i88, 1, 4, 1);
                            rec->fc = f.i88;
                            r->stream->FUN_002647e0((char *)&f.ic0, 1, 4, 1);
                            rec->f8 = f.ic0;
                            f.w34 += 0x10;
                        } else if (csub == 4) {
                            Rec30 *rec = (Rec30 *)((char *)so->a30 + f.w3c);
                            r->stream->FUN_002647e0((char *)&f.b08, 1, 1, 1);
                            len = f.b08;
                            r->stream->FUN_002647e0(f.s0ec, len, 1, 1);
                            *(f.s0ec + len) = 0;
                            rec->name.FUN_0027b040(f.s0ec);
                            unsigned __int64 id = FUN_002672f0(f.s0ec, 0, 0);
                            rec->idLo = (unsigned int)id;
                            rec->idHi = (unsigned int)(id >> 32);
                            r->stream->FUN_002647e0((char *)&f.i90, 1, 4, 1);
                            rec->f10 = f.i90;
                            r->stream->FUN_002647e0((char *)&f.ie4, 1, 4, 1);
                            rec->f14 = f.ie4;
                            r->stream->FUN_002647e0((char *)&f.i98, 1, 4, 1);
                            rec->f18 = f.i98;
                            r->stream->FUN_002647e0((char *)&f.ic8, 1, 4, 1);
                            rec->f1c = f.ic8;
                            r->stream->FUN_002647e0((char *)&f.i44, 1, 4, 1);
                            rec->f20 = f.i44;
                            r->stream->FUN_002647e0((char *)&f.i4c, 1, 4, 1);
                            rec->f24 = f.i4c;
                            r->stream->FUN_002647e0((char *)&f.i54, 1, 4, 1);
                            rec->f28 = f.i54;
                            f.w3c += 0x30;
                        } else if (csub == 3) {
                            Rec10b *rec = (Rec10b *)((char *)so->a38 + f.s28.w);
                            r->stream->FUN_002647e0((char *)&f.b06, 1, 1, 1);
                            len = f.b06;
                            r->stream->FUN_002647e0(f.s0ec, len, 1, 1);
                            *(f.s0ec + len) = 0;
                            rec->name.FUN_0027b040(f.s0ec);
                            r->stream->FUN_002647e0((char *)&f.i5c, 1, 4, 1);
                            rec->f8 = f.i5c;
                            r->stream->FUN_002647e0((char *)&f.i64, 1, 4, 1);
                            rec->fc = f.i64;
                            f.s28.w += 0x10;
                        } else if (csub == 9) {
                            Rec58 *rec = (Rec58 *)((char *)so->a48 + f.s1c.w);
                            r->stream->FUN_002647e0((char *)&f.b09, 1, 1, 1);
                            len = f.b09;
                            r->stream->FUN_002647e0(f.s0ec, len, 1, 1);
                            *(f.s0ec + len) = 0;
                            rec->n40.FUN_0027b040(f.s0ec);
                            r->stream->FUN_002647e0((char *)&f.b02, 1, 1, 1);
                            len = f.b02;
                            r->stream->FUN_002647e0(f.s0ec, len, 1, 1);
                            *(f.s0ec + len) = 0;
                            rec->n28.FUN_0027b040(f.s0ec);
                            r->stream->FUN_002647e0((char *)&f.i6c, 1, 4, 1);
                            rec->f4c = f.i6c;
                            r->stream->FUN_002647e0((char *)&f.b03, 1, 1, 1);
                            len = f.b03;
                            r->stream->FUN_002647e0(f.s0ec, len, 1, 1);
                            *(f.s0ec + len) = 0;
                            rec->n38.FUN_0027b040(f.s0ec);
                            r->stream->FUN_002647e0((char *)&f.i74, 1, 4, 1);
                            r->stream->FUN_002647e0((char *)&f.i7c, 1, 4, 1);
                            r->stream->FUN_002647e0((char *)&f.i84, 1, 4, 1);
                            rec->f0 = f.i74;
                            rec->f4 = f.i7c;
                            rec->f8 = f.i84;
                            r->stream->FUN_002647e0((char *)&f.i8c, 1, 4, 1);
                            r->stream->FUN_002647e0((char *)&f.i94, 1, 4, 1);
                            r->stream->FUN_002647e0((char *)&f.i9c, 1, 4, 1);
                            rec->fc = f.i8c;
                            rec->f10 = f.i94;
                            rec->f14 = f.i9c;
                            r->stream->FUN_002647e0((char *)&f.ia4, 1, 4, 1);
                            rec->f48 = f.ia4;
                            r->stream->FUN_002647e0((char *)&f.b05, 1, 1, 1);
                            len = f.b05;
                            r->stream->FUN_002647e0(f.s0ec, len, 1, 1);
                            *(f.s0ec + len) = 0;
                            rec->n30.FUN_0027b040(f.s0ec);
                            r->stream->FUN_002647e0((char *)&f.iac, 1, 4, 1);
                            rec->f18 = f.iac;
                            r->stream->FUN_002647e0((char *)&f.ib4, 1, 4, 1);
                            rec->f50 = f.ib4;
                            if ((unsigned int)f.i24 >= 5) {
                                if (!(DAT_0052c2c0 & 1)) {
                                    DAT_0052c2c0 |= 1;
                                    unsigned __int64 sk = FUN_0027b020("StateProp");
                                    DAT_0052c2b8 = (unsigned int)sk;
                                    DAT_0052c2bc = (unsigned int)(sk >> 32);
                                }
                                if (rec->n40.lo == DAT_0052c2b8 && rec->n40.hi == DAT_0052c2bc) {
                                    r->stream->FUN_002647e0((char *)&f.ibc, 1, 4, 1);
                                    rec->f18 = f.ibc;
                                    r->stream->FUN_002647e0((char *)&f.ic4, 1, 4, 1);
                                    rec->f1c = f.ic4;
                                    r->stream->FUN_002647e0((char *)&f.icc, 1, 4, 1);
                                    rec->f20 = f.icc;
                                }
                            }
                            f.s1c.w += 0x58;
                        } else if (csub == 6) {
                            NameField *rec = (NameField *)((char *)so->a40 + f.s0c.w);
                            r->stream->FUN_002647e0((char *)&f.b07, 1, 1, 1);
                            len = f.b07;
                            r->stream->FUN_002647e0(f.s0ec, len, 1, 1);
                            *(f.s0ec + len) = 0;
                            rec->FUN_0027b040(f.s0ec);
                            r->stream->FUN_002647e0((char *)&f.b01, 1, 1, 1);
                            len = f.b01;
                            r->stream->FUN_002647e0(f.s0ec, len, 1, 1);
                            *(f.s0ec + len) = 0;
                            rec->FUN_0028fe80(f.s0ec);
                            f.s0c.w += 0x10;
                        } else if (csub == 10) {
                            r->stream->FUN_002647e0((char *)&f.b1b, 1, 1, 1);
                            len = f.b1b;
                            r->stream->FUN_002647e0(f.s0ec, len, 1, 1);
                            *(f.s0ec + len) = 0;
                            unsigned __int64 wk = FUN_0027b020(f.s0ec);
                            CasterWorld *cw = new ((char *)&f.sd4) CasterWorld;
                            RefObj *wo = (RefObj *)inv->v3(cw, wk);
                            if (wo != 0) {
                                wo->v0();
                                if (so->f4c != 0)
                                    so->f4c->v1();
                                so->f4c = wo;
                            }
                        }
                        r->FUN_00266be0();
                    } while (r->FUN_002669f0());
                }
                StateObj **slot = (StateObj **)((char *)((Prop *)f.w20)->arr1c + f.s10.w);
                so->v0();
                if (*slot != 0)
                    (*slot)->v1();
                f.s10.w += sizeof(StateObj *);
                *slot = so;
            }
            r->FUN_00266be0();
        } while (r->FUN_002669f0());
    }
    *out = (Prop *)f.w20;
    NameField *pn = (NameField *)f.wdc;
    ((unsigned int *)outId)[0] = pn->lo;
    ((unsigned int *)outId)[1] = pn->hi;
}
} // namespace fn_00290bf0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

