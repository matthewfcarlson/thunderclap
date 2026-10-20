// STATUS: equivalent (tools/equiv.py level 3: 2686 inputs, branch coverage 64/64)
// pure3d::prop::StatePropDataLoader::vfunc_5 @ 0x00290bf0
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/engine/pure3d/prop.h"
inline void *operator new(unsigned int, void *p) throw() { return p; }
extern "C" void *memcpy(void *, const void *, unsigned int);

struct Stream {
    char FUN_002647e0(void *dest, unsigned int count, unsigned int size, int flag);
};

struct Reader {
    char pad[0x284];
    Stream *stream;
    char FUN_002669f0();
    int FUN_00266a30();
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

namespace content {
namespace LoadInventory {
template <class T>
struct DynamicCaster {
    virtual void v0();
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
    int fc;
    char b10;
    char pad11[3];
    int f14;
    int f18;
    int f1c;
};
struct Rec10b {
    NameField name;
    int f8;
    int fc;
};
struct Rec30 {
    NameField name;
    unsigned int idLo;
    unsigned int idHi;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
};
struct Rec58 {
    int f0, f4, f8, fc, f10, f14;
    int f18, f1c, f20;
    char pad24[4];
    NameField n28;
    NameField n30;
    NameField n38;
    NameField n40;
    int f48;
    int f4c;
    int f50;
    char pad54[4];
};
struct Sub {
    char b0;
    char pad1[3];
    int f4;
    int f8;
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
    StateObj *FUN_0028ff00(int a, int b, int c, int d, int e, int f, int g);
};

struct Prop {
    char pad00[8];
    NameField name;
    char pad10[0x1c - 0x10];
    StateObj **arr1c;
    char pad20[0x28 - 0x20];
    NameField *arr28;
    char pad2c[0x38 - 0x2c];
    Prop *FUN_00290b30(ResObj *res, void *obj2, void *obj3, int x2, int x3);
};

int __cdecl FUN_00267760(char *buf, int size, const char *fmt, ...);
void *FUN_00263ea0(unsigned int size);

typedef content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable> CasterComp;
typedef content::LoadInventory::DynamicCaster<physics::CollisionObject> CasterColl;
typedef content::LoadInventory::DynamicCaster<physics::PhysicsObject> CasterPhys;
typedef content::LoadInventory::DynamicCaster<physics::WorldCollisionObject> CasterWorld;

class StatePropDataLoader {
public:
    void vfunc_5(Prop **out, unsigned __int64 *outId, Reader *r, Inventory *inv);
};

struct Frame {
    char b[0x3ec];
};

#define W(o) (*(volatile hulk_intptr *)((char *)&f + (o)))
#define U8(o) (*(volatile unsigned char *)((char *)&f + (o)))
#define PT(o) ((char *)&f + (o))

void StatePropDataLoader::vfunc_5(Prop **out, unsigned __int64 *outId, Reader *r, Inventory *inv)
{
    Frame f;

    r->stream->FUN_002647e0(PT(0x24), 1, 4, 1);
    r->stream->FUN_002647e0(PT(0x01), 1, 1, 1);
    unsigned int len = U8(0x01);
    r->stream->FUN_002647e0(PT(0x1ec), len, 1, 1);
    r->stream->FUN_002647e0(PT(0x01), 1, 1, 1);
    *(PT(0x1ec) + len) = 0;
    len = U8(0x01);
    r->stream->FUN_002647e0(PT(0xec), len, 1, 1);
    *(PT(0xec) + len) = 0;

    unsigned __int64 key = FUN_0027b020(PT(0xec));
    CasterComp *c1 = new (PT(0x0c)) CasterComp;
    ResObj *res = (ResObj *)inv->v3(c1, key);
    if (res == 0)
        FUN_00267760(PT(0x2ec), 0x100, "StatePropDataLoader::LoadObject():  Can not find the composite drawable with name %s to use with the state prop with name %s.", PT(0xec), PT(0x1ec));

    W(0x10) = 0;
    CasterColl *c2 = new (PT(0x1c)) CasterColl;
    unsigned __int64 rid = ((unsigned __int64)res->idHi << 32) | res->idLo;
    W(0x28) = (hulk_intptr)inv->v3(c2, rid);
    if (W(0x28) != 0) {
        CasterPhys *c3 = new (PT(0x10)) CasterPhys;
        unsigned __int64 rid2 = ((unsigned __int64)res->idHi << 32) | res->idLo;
        W(0x10) = (hulk_intptr)inv->v3(c3, rid2);
    }

    r->stream->FUN_002647e0(PT(0x1c), 1, 4, 1);
    hulk_uintptr ver = W(0x24);
    hulk_intptr x3 = 0;
    if (ver >= 3) {
        r->stream->FUN_002647e0(PT(0x0c), 1, 4, 1);
        x3 = W(0x0c);
    }
    void *mem = FUN_00263ea0(0x38);
    Prop *prop;
    if (mem)
        prop = ((Prop *)mem)->FUN_00290b30(res, (void *)W(0x28), (void *)W(0x10), W(0x1c), x3);
    else
        prop = 0;
    W(0x20) = (hulk_intptr)prop;
    NameField *pname = &prop->name;
    W(0xdc) = (hulk_intptr)pname;
    pname->FUN_0027b040(PT(0x1ec));

    if (r->FUN_002669f0()) {
        W(0x10) = 0;
        W(0x30) = 0;
        do {
            unsigned int sub = (unsigned int)r->FUN_00266a30() - 0x8020001;
            if (sub == 7) {
                NameField *rec = (NameField *)((char *)((Prop *)W(0x20))->arr28 + W(0x30));
                r->stream->FUN_002647e0(PT(0x18), 1, 1, 1);
                len = U8(0x18);
                r->stream->FUN_002647e0(PT(0xec), len, 1, 1);
                *(PT(0xec) + len) = 0;
                rec->FUN_0027b040(PT(0xec));
                r->stream->FUN_002647e0(PT(0x19), 1, 1, 1);
                len = U8(0x19);
                r->stream->FUN_002647e0(PT(0xec), len, 1, 1);
                *(PT(0xec) + len) = 0;
                rec->FUN_0028fe80(PT(0xec));
                W(0x30) += 0x10;
            } else if (sub == 0 || sub == 6 || sub == 8) {
                r->stream->FUN_002647e0(PT(0x17), 1, 1, 1);
                len = U8(0x17);
                r->stream->FUN_002647e0(PT(0xec), len, 1, 1);
                *(PT(0xec) + len) = 0;
                r->stream->FUN_002647e0(PT(0x68), 1, 4, 1);
                U8(0x1a) = (W(0x68) != 0);
                r->stream->FUN_002647e0(PT(0x40), 1, 4, 1);
                r->stream->FUN_002647e0(PT(0x58), 1, 4, 1);
                r->stream->FUN_002647e0(PT(0xe0), 1, 4, 1);
                r->stream->FUN_002647e0(PT(0x60), 1, 4, 1);
                r->stream->FUN_002647e0(PT(0xa8), 1, 4, 1);
                r->stream->FUN_002647e0(PT(0xd0), 1, 4, 1);
                hulk_intptr ebp = 0;
                hulk_intptr edi = 0;
                W(0x0c) = 0;
                if ((unsigned int)W(0x24) >= 2) {
                    r->stream->FUN_002647e0(PT(0x48), 1, 4, 1);
                    W(0x0c) = W(0x48);
                }
                if ((unsigned int)W(0x24) >= 3) {
                    r->stream->FUN_002647e0(PT(0xa0), 1, 4, 1);
                    ebp = W(0xa0);
                }
                if ((unsigned int)W(0x24) >= 4) {
                    r->stream->FUN_002647e0(PT(0x50), 1, 4, 1);
                    edi = W(0x50);
                }
                void *m2 = FUN_00263ea0(0x58);
                StateObj *so;
                if (m2)
                    so = ((StateObj *)m2)->FUN_0028ff00(W(0x60), W(0x0c), W(0xa8), W(0x58), W(0xe0), ebp, edi);
                else
                    so = 0;
                so->name.FUN_0027b040(PT(0xec));
                so->f10->b0 = U8(0x1a);
                so->f10->f8 = W(0xd0);
                so->f10->f4 = W(0x40);
                if (r->FUN_002669f0()) {
                    W(0x0c) = 0;
                    W(0x1c) = 0;
                    W(0x28) = 0;
                    W(0x3c) = 0;
                    W(0x34) = 0;
                    W(0x2c) = 0;
                    W(0x38) = 0;
                    do {
                        unsigned int csub = (unsigned int)r->FUN_00266a30() - 0x8020002;
                        if (csub == 0) {
                            Rec10a *rec = (Rec10a *)((char *)so->a18 + W(0x38));
                            r->stream->FUN_002647e0(PT(0x0a), 1, 1, 1);
                            len = U8(0x0a);
                            r->stream->FUN_002647e0(PT(0xec), len, 1, 1);
                            *(PT(0xec) + len) = 0;
                            rec->name.FUN_0027b040(PT(0xec));
                            r->stream->FUN_002647e0(PT(0xb0), 1, 4, 1);
                            rec->b8 = (W(0xb0) != 0);
                            W(0x38) += 0x10;
                        } else if (csub == 1) {
                            Rec20 *rec = (Rec20 *)((char *)so->a20 + W(0x2c));
                            r->stream->FUN_002647e0(PT(0x0b), 1, 1, 1);
                            len = U8(0x0b);
                            r->stream->FUN_002647e0(PT(0xec), len, 1, 1);
                            *(PT(0xec) + len) = 0;
                            rec->name.FUN_0027b040(PT(0xec));
                            r->stream->FUN_002647e0(PT(0x70), 1, 4, 1);
                            rec->b8 = (W(0x70) != 0);
                            r->stream->FUN_002647e0(PT(0xe8), 1, 4, 1);
                            rec->fc = W(0xe8);
                            r->stream->FUN_002647e0(PT(0x78), 1, 4, 1);
                            rec->b10 = (W(0x78) != 0);
                            r->stream->FUN_002647e0(PT(0xb8), 1, 4, 1);
                            rec->f14 = W(0xb8);
                            r->stream->FUN_002647e0(PT(0x80), 1, 4, 1);
                            rec->f18 = W(0x80);
                            r->stream->FUN_002647e0(PT(0xd8), 1, 4, 1);
                            rec->f1c = W(0xd8);
                            W(0x2c) += 0x20;
                        } else if (csub == 2) {
                            Rec10b *rec = (Rec10b *)((char *)so->a28 + W(0x34));
                            r->stream->FUN_002647e0(PT(0x04), 1, 1, 1);
                            len = U8(0x04);
                            r->stream->FUN_002647e0(PT(0xec), len, 1, 1);
                            *(PT(0xec) + len) = 0;
                            rec->name.FUN_0027b040(PT(0xec));
                            r->stream->FUN_002647e0(PT(0x88), 1, 4, 1);
                            rec->fc = W(0x88);
                            r->stream->FUN_002647e0(PT(0xc0), 1, 4, 1);
                            rec->f8 = W(0xc0);
                            W(0x34) += 0x10;
                        } else if (csub == 4) {
                            Rec30 *rec = (Rec30 *)((char *)so->a30 + W(0x3c));
                            r->stream->FUN_002647e0(PT(0x08), 1, 1, 1);
                            len = U8(0x08);
                            r->stream->FUN_002647e0(PT(0xec), len, 1, 1);
                            *(PT(0xec) + len) = 0;
                            rec->name.FUN_0027b040(PT(0xec));
                            unsigned __int64 id = FUN_002672f0(PT(0xec), 0, 0);
                            rec->idLo = (unsigned int)id;
                            rec->idHi = (unsigned int)(id >> 32);
                            r->stream->FUN_002647e0(PT(0x90), 1, 4, 1);
                            rec->f10 = W(0x90);
                            r->stream->FUN_002647e0(PT(0xe4), 1, 4, 1);
                            rec->f14 = W(0xe4);
                            r->stream->FUN_002647e0(PT(0x98), 1, 4, 1);
                            rec->f18 = W(0x98);
                            r->stream->FUN_002647e0(PT(0xc8), 1, 4, 1);
                            rec->f1c = W(0xc8);
                            r->stream->FUN_002647e0(PT(0x44), 1, 4, 1);
                            rec->f20 = W(0x44);
                            r->stream->FUN_002647e0(PT(0x4c), 1, 4, 1);
                            rec->f24 = W(0x4c);
                            r->stream->FUN_002647e0(PT(0x54), 1, 4, 1);
                            rec->f28 = W(0x54);
                            W(0x3c) += 0x30;
                        } else if (csub == 3) {
                            Rec10b *rec = (Rec10b *)((char *)so->a38 + W(0x28));
                            r->stream->FUN_002647e0(PT(0x06), 1, 1, 1);
                            len = U8(0x06);
                            r->stream->FUN_002647e0(PT(0xec), len, 1, 1);
                            *(PT(0xec) + len) = 0;
                            rec->name.FUN_0027b040(PT(0xec));
                            r->stream->FUN_002647e0(PT(0x5c), 1, 4, 1);
                            rec->f8 = W(0x5c);
                            r->stream->FUN_002647e0(PT(0x64), 1, 4, 1);
                            rec->fc = W(0x64);
                            W(0x28) += 0x10;
                        } else if (csub == 9) {
                            Rec58 *rec = (Rec58 *)((char *)so->a48 + W(0x1c));
                            r->stream->FUN_002647e0(PT(0x09), 1, 1, 1);
                            len = U8(0x09);
                            r->stream->FUN_002647e0(PT(0xec), len, 1, 1);
                            *(PT(0xec) + len) = 0;
                            rec->n40.FUN_0027b040(PT(0xec));
                            r->stream->FUN_002647e0(PT(0x02), 1, 1, 1);
                            len = U8(0x02);
                            r->stream->FUN_002647e0(PT(0xec), len, 1, 1);
                            *(PT(0xec) + len) = 0;
                            rec->n28.FUN_0027b040(PT(0xec));
                            r->stream->FUN_002647e0(PT(0x6c), 1, 4, 1);
                            rec->f4c = W(0x6c);
                            r->stream->FUN_002647e0(PT(0x03), 1, 1, 1);
                            len = U8(0x03);
                            r->stream->FUN_002647e0(PT(0xec), len, 1, 1);
                            *(PT(0xec) + len) = 0;
                            rec->n38.FUN_0027b040(PT(0xec));
                            r->stream->FUN_002647e0(PT(0x74), 1, 4, 1);
                            r->stream->FUN_002647e0(PT(0x7c), 1, 4, 1);
                            r->stream->FUN_002647e0(PT(0x84), 1, 4, 1);
                            rec->f0 = W(0x74);
                            rec->f4 = W(0x7c);
                            rec->f8 = W(0x84);
                            r->stream->FUN_002647e0(PT(0x8c), 1, 4, 1);
                            r->stream->FUN_002647e0(PT(0x94), 1, 4, 1);
                            r->stream->FUN_002647e0(PT(0x9c), 1, 4, 1);
                            rec->fc = W(0x8c);
                            rec->f10 = W(0x94);
                            rec->f14 = W(0x9c);
                            r->stream->FUN_002647e0(PT(0xa4), 1, 4, 1);
                            rec->f48 = W(0xa4);
                            r->stream->FUN_002647e0(PT(0x05), 1, 1, 1);
                            len = U8(0x05);
                            r->stream->FUN_002647e0(PT(0xec), len, 1, 1);
                            *(PT(0xec) + len) = 0;
                            rec->n30.FUN_0027b040(PT(0xec));
                            r->stream->FUN_002647e0(PT(0xac), 1, 4, 1);
                            rec->f18 = W(0xac);
                            r->stream->FUN_002647e0(PT(0xb4), 1, 4, 1);
                            rec->f50 = W(0xb4);
                            if ((unsigned int)W(0x24) >= 5) {
                                if (!(DAT_0052c2c0 & 1)) {
                                    DAT_0052c2c0 |= 1;
                                    unsigned __int64 sk = FUN_0027b020("StateProp");
                                    DAT_0052c2b8 = (unsigned int)sk;
                                    DAT_0052c2bc = (unsigned int)(sk >> 32);
                                }
                                if (rec->n40.lo == DAT_0052c2b8 && rec->n40.hi == DAT_0052c2bc) {
                                    r->stream->FUN_002647e0(PT(0xbc), 1, 4, 1);
                                    rec->f18 = W(0xbc);
                                    r->stream->FUN_002647e0(PT(0xc4), 1, 4, 1);
                                    rec->f1c = W(0xc4);
                                    r->stream->FUN_002647e0(PT(0xcc), 1, 4, 1);
                                    rec->f20 = W(0xcc);
                                }
                            }
                            W(0x1c) += 0x58;
                        } else if (csub == 6) {
                            NameField *rec = (NameField *)((char *)so->a40 + W(0x0c));
                            r->stream->FUN_002647e0(PT(0x07), 1, 1, 1);
                            len = U8(0x07);
                            r->stream->FUN_002647e0(PT(0xec), len, 1, 1);
                            *(PT(0xec) + len) = 0;
                            rec->FUN_0027b040(PT(0xec));
                            r->stream->FUN_002647e0(PT(0x01), 1, 1, 1);
                            len = U8(0x01);
                            r->stream->FUN_002647e0(PT(0xec), len, 1, 1);
                            *(PT(0xec) + len) = 0;
                            rec->FUN_0028fe80(PT(0xec));
                            W(0x0c) += 0x10;
                        } else if (csub == 10) {
                            r->stream->FUN_002647e0(PT(0x1b), 1, 1, 1);
                            len = U8(0x1b);
                            r->stream->FUN_002647e0(PT(0xec), len, 1, 1);
                            *(PT(0xec) + len) = 0;
                            unsigned __int64 wk = FUN_0027b020(PT(0xec));
                            CasterWorld *cw = new (PT(0xd4)) CasterWorld;
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
                StateObj **slot = (StateObj **)((char *)((Prop *)W(0x20))->arr1c + W(0x10));
                so->v0();
                if (*slot != 0)
                    (*slot)->v1();
                W(0x10) += 4;
                *slot = so;
            }
            r->FUN_00266be0();
        } while (r->FUN_002669f0());
    }
    *out = (Prop *)W(0x20);
    NameField *pn = (NameField *)W(0xdc);
    ((unsigned int *)outId)[0] = pn->lo;
    ((unsigned int *)outId)[1] = pn->hi;
}
