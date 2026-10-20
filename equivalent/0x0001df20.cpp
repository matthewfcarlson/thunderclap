// STATUS: equivalent (tools/equiv.py level 3: 2874 inputs, branch coverage 75/78, incomplete)
// FUN_0001df20 @ 0x0001df20
#include "compat/ptr.h"
#include "decls/address.h"
struct Vec3 {
    float x, y, z;
};

class RefObj {
public:
    virtual void AddRef() throw();
    virtual void Release() throw();
};

struct Binder;

struct Made : public RefObj {
    Made *FUN_000598e0(void *a, struct Obj *o) throw();
};

struct Binder {
    void FUN_00231ad0(struct Bind *b, Made *m, unsigned int flags) throw();
};

struct Bind {
    RefObj *ref;
    Binder *cur;
    char FUN_00231e80(Binder *r) throw();
};

class Factory {
public:
    virtual void v0() throw();
    virtual void v1() throw();
    virtual void v2() throw();
    virtual void v3() throw();
    virtual void v4() throw();
    virtual void v5() throw();
    virtual void v6() throw();
    virtual void v7() throw();
    virtual Binder *v8(Made *m, int z) throw();
};

struct Obj {
    char pad00[8];
    Vec3 a;
    char pad14[4];
    Vec3 b;
    char flag;
    char pad25[0x4c - 0x25];
    RefObj *s4c;
    RefObj *s50;
    int f54;
    char pad58[0x6c - 0x58];
    RefObj *s6c;
    RefObj *s70;
    int f74;
    char pad78[0x94 - 0x78];
    void FUN_00059820() throw();
    void FUN_00059300() throw();
};

void __cdecl FUN_00018810(RefObj **slot, RefObj *v) throw();
void __cdecl FUN_000187a0(RefObj **slot, RefObj *v) throw();
void __cdecl FUN_00018840(RefObj **slot, RefObj *v) throw();
void *__cdecl FUN_0008d690(hulk_uintptr size) throw();

struct Info {
    char pad000[0x1b0];
    int f1b0;
};

struct Holder {
    int FUN_001d72e0() throw();
};

struct Entity {
    char pad000[0x10];
    void **f10;
    char pad14[0xdc - 0x14];
    Bind fdc;
    char padE4[0x11c - 0xe4];
    Info *info;
    char pad120[0x128 - 0x120];
    Holder *f128;
    RefObj *f12c;
    char pad130[0x330 - 0x130];
    Entity *f330;
    Entity *f334;
    Entity *f338;
    char pad33c[0x20b0 - 0x33c];
    int f20b0;
    char FUN_000360f0() throw();
    int FUN_00036270() throw();
    int FUN_00038f90(Vec3 *p, int a, int z) throw();
    char FUN_0003a590(struct World *g, Entity *e) throw();
    void FUN_0003a680(Entity *t, int a, int b, int c, void *m, float e5, float e6, float e7) throw();
    void FUN_0003a9d0(int v) throw();
    float FUN_000354c0() throw();
    int FUN_00036020() throw();
    int FUN_00035ef0(int z) throw();
    void FUN_0003b160(struct Prop *p) throw();
    void FUN_0003b190(struct Prop *p) throw();
};

struct Fighter {
    void FUN_00059a50(Vec3 *out) throw();
};

struct List {
    char pad000[0xc];
    int count;
    char pad010[0x124 - 0x10];
    Entity *player;
    Entity *FUN_00024190(int i) throw();
};

struct Item {
    char pad00[0x2c];
    float f2c;
};

struct Prop {
    char pad00[0x28];
    unsigned int f28;
    char pad2c[0x64 - 0x2c];
    Vec3 pos;
    char pad70[0x100 - 0x70];
    struct P100 *f100;
    void FUN_00080cb0(int v) throw();
};

struct P20 { char pad[0x20]; struct P34 *f20; };
struct P34 { char pad[0x34]; float f34; };
struct P74 { char pad[0x74]; P20 *f74; };
struct P100 { };

struct Mgr {
    int FUN_00079270() throw();
    Prop *FUN_00079280(int i) throw();
};

struct World {
    char pad00[0x20];
    List *list;
    char pad24[0x4c - 0x24];
    Mgr *mgr;
};

struct Owner {
    char pad00[8];
    void *f08;
};

struct Cfg {
    char pad00[0x2c];
    union {
        float f2c;
        int i2c;
    };
    int f30;
    char pad34[4];
    Factory *f38;
    char pad3c[8];
    Factory *f44;
};

Fighter *__fastcall FUN_000592a0(Owner *owner) throw();
Entity *__fastcall FUN_00059a30(Fighter *f) throw();

class Ctrl {
public:
    char pad00[0x1c];
    Owner *f1c;
    Cfg *f20;
    char pad24[0x38 - 0x24];
    char done;
    char pad39[3];
    RefObj *f3c;
    void FUN_0001df20(Vec3 *a1, Vec3 *a2);
};

void Ctrl::FUN_0001df20(Vec3 *a1, Vec3 *a2)
{
    struct Frame {
        Vec3 pos;
        Obj o;
    } fr;

    Fighter *fighter = FUN_000592a0(f1c);
    Entity *edi = FUN_00059a30(fighter);
    Entity *player = DAT_004dd700->list->player;
    fr.pos.x = 0.0f;
    fr.pos.y = 0.0f;
    fr.pos.z = 0.0f;
    fighter->FUN_00059a50(&fr.pos);
    List *list = DAT_004dd700->list;
    int count = list->count;
    Entity *esi = 0;
    int r = 0;
    bool found = false;
    if (count > 0) {
        int idx = 0;
        do {
            esi = list->FUN_00024190(idx);
            if (esi != edi) {
                Info *p = esi->info;
                if (p != 0 && esi->f20b0 == 0 && !esi->FUN_000360f0() && esi->f338 == 0 && esi->f334 == 0) {
                    if (p->f1b0 != edi->info->f1b0) {
                        int lim = f20->f30;
                        if (!(esi->FUN_00036270() > lim)) {
                            r = esi->FUN_00038f90(a1, f20->i2c, 0);
                            if (r != 0) {
                                if (edi->FUN_0003a590((World *)DAT_004dd700, esi)) {
                                    found = true;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
            idx = idx + 1;
        } while (idx < count);
    }
    if (!found) {
        if (edi->FUN_00036020() != 0)
            return;
        if (edi->f334 != 0)
            return;
        if (edi->FUN_00035ef0(0) != 0)
            return;
        if (list->player != edi)
            return;
        Mgr *m = DAT_004dd700->mgr;
        int n = m->FUN_00079270();
        if (n <= 0)
            return;
        int i = 0;
        do {
            Prop *p = m->FUN_00079280(i);
            if (!((p->f28 >> 7) & 1)) {
                double dx = a1->x - p->pos.x;
                double dy = a1->y - p->pos.y;
                double dz = a1->z - p->pos.z;
                double rr = ((P74 *)p->f100)->f74->f20->f34 + f20->f2c;
                if (dz * dz + dy * dy + dx * dx < rr * rr) {
                    Factory *fac = f20->f44;
                    if (fac != 0) {
                        edi->FUN_0003b190(p);
                        Binder *b = fac->v8((Made *)f1c, 0);
                        if (b != 0) {
                            if (!edi->fdc.FUN_00231e80(b)) {
                                b->FUN_00231ad0(&edi->fdc, (Made *)f1c, 0x80000000);
                                if (edi->fdc.cur == b) {
                                    edi->FUN_0003b160(p);
                                    p->FUN_00080cb0(5);
                                }
                            }
                        }
                    }
                    done = 1;
                    return;
                }
            }
            i = i + 1;
        } while (i < n);
        return;
    }

    fr.o.FUN_00059820();
    FUN_00018810(&fr.o.s4c, edi->f12c);
    FUN_00018810(&fr.o.s50, esi->f12c);
    fr.o.a = *a1;
    fr.o.b = *a2;
    fr.o.f54 = f20->f30;
    fr.o.f74 = r;
    fr.o.flag = 1;
    FUN_000187a0(&fr.o.s6c, f3c);
    FUN_00018840(&fr.o.s70, edi->fdc.ref);
    edi->f330 = esi;
    if (edi->info->f1b0 == 3 && esi != player && esi->f128 != 0)
        edi->FUN_0003a9d0(esi->f128->FUN_001d72e0());
    edi->FUN_000354c0();
    esi->f330 = edi;
    Factory *fac = f20->f44;
    char grabbed = 0;
    if (fac != 0) {
        void *mem = FUN_0008d690(0xb0);
        Made *b;
        if (mem)
            b = ((Made *)mem)->FUN_000598e0(f1c->f08, &fr.o);
        else
            b = 0;
        b->AddRef();
        edi->f330 = esi;
        Binder *bi = fac->v8(b, 0);
        if (bi != 0) {
            if (!edi->fdc.FUN_00231e80(bi)) {
                bi->FUN_00231ad0(&edi->fdc, b, 0x80000000);
                if (edi->fdc.cur == bi && esi->fdc.cur == bi) {
                    edi->f334 = esi;
                    edi->FUN_0003a680(0, -1, 0, 0, 0, 0.0f, 1.0f, 0.0f);
                    esi->FUN_0003a680(edi, 0, 0, 0, 0, 0.0f, 1.0f, 0.0f);
                    esi->f334 = 0;
                    grabbed = 1;
                }
            }
        }
        b->Release();
    }
    Factory *fac2 = f20->f38;
    if (fac2 != 0) {
        void *mem = FUN_0008d690(0xb0);
        Made *b;
        if (mem)
            b = ((Made *)mem)->FUN_000598e0(*esi->f10, &fr.o);
        else
            b = 0;
        b->AddRef();
        esi->f330 = edi;
        Binder *bi = fac2->v8(b, 0);
        if (bi != 0) {
            bi->FUN_00231ad0(&esi->fdc, b, 0x80000000);
            if (!grabbed && edi->fdc.cur == bi && esi->fdc.cur == bi) {
                esi->f334 = edi;
                esi->FUN_0003a680(0, -1, 0, 0, 0, 0.0f, 1.0f, 0.0f);
                edi->FUN_0003a680(esi, 0, 0, 0, 0, 0.0f, 1.0f, 0.0f);
                edi->f334 = 0;
            }
        }
        b->Release();
    }
    done = 1;
    fr.o.FUN_00059300();
}
