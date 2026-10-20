// STATUS: equivalent (tools/equiv.py level 3: 3117 inputs, branch coverage 100/100)
// FUN_0002b970 @ 0x0002b970
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/unknown.h"
extern "C" int memcmp(const void *a, const void *b, unsigned int n);
extern "C" int __cdecl FUN_00267760(char *buf, int size, const char *fmt, ...);
int FUN_00266da0(int mode);
void *thunk_FUN_0008d690(unsigned int size);
void *FUN_0008d690(hulk_uintptr size);
char FUN_00202560(void *from, float a2, int flag, void *a3, void *a4, void *o38, void *o48, void *opts);


struct V3_2b970 {
    float x, y, z;
};

struct Name_2b970 {
    void FUN_0027b040(const char *s);
};

struct Comp_2b970;
struct Char_2b970;

struct Ent_2b970 {
    char pad0[0x60];
    int f60;
    char pad64[0xe8 - 0x64];
    char be8;
    char pad0e9[0x118 - 0xe9];
    Name_2b970 name;
    void FUN_000fdbd0(Comp_2b970 *c);
};

struct Def {
    char pad0[0x14];
    int f14;
    char pad18[0x1b0 - 0x18];
    int f1b0;
    char pad1b4[0x37c - 0x1b4];
    char b37c;
    char pad37d[0x38c - 0x37d];
    char b38c, b38d, b38e, b38f, b390;
    unsigned __int64 FUN_000443c0();
};

struct Registry_2b970 {
    char pad0[0xc];
    int count;
    Def *FUN_00044ad0(unsigned int lo, unsigned int hi);
    Def *FUN_00044ab0(int i);
};

struct Owner_2b970 {
    void FUN_00059cd0(Char_2b970 *c);
};
struct Factory_2b970 {
    int *FUN_00059b60();
    Owner_2b970 *FUN_00059ba0(int *x);
};
struct Slot8b {
    void FUN_000c7d10(int a, const char *name);
};
struct Slot8_2b970 {
    Slot8b *FUN_000cae70();
};
struct P3c_2b970 {
    char pad0[8];
    Slot8_2b970 *p8;
};
struct Pl2 {
    char pad0[0x12c];
    int f12c;
};
struct G20 {
    char pad0[0x124];
    Pl2 *f124;
};
struct World {
    char pad0[0x20];
    G20 *p20;
    char pad24[0x3c - 0x24];
    P3c_2b970 *p3c;
    char pad40[4];
    Factory_2b970 *p44;
};

struct Comp_2b970 {
    Comp_2b970 *FUN_001076f0(Ent_2b970 *e);
    Comp_2b970 *FUN_000ff180(Ent_2b970 *e);
    Comp_2b970 *FUN_000fcb10(Ent_2b970 *e);
    Comp_2b970 *FUN_00105f50(Ent_2b970 *e);
    Comp_2b970 *FUN_00103340(Ent_2b970 *e);
    void FUN_00103b60(World *w, const char *anim, int z);
    void FUN_001034b0(int a);
};

class Char_2b970 {
public:
    virtual void v0();
    virtual void v1();
    char pad04[0x11c - 4];
    Def *p11c;
    char pad120[0x128 - 0x120];
    void *p128;
    char pad12c[0x1ca0 - 0x12c];
    Ent_2b970 *p1ca0;
    char pad1ca4[0x1d7c - 0x1ca4];
    int f1d7c;
    Char_2b970 *FUN_00037860(int *x);
    void FUN_00036d60(char *name);
    void FUN_00042b40(Def *d);
    void FUN_0003f650();
    void FUN_000362f0();
    char FUN_00035a90();
    void FUN_000368d0(int a);
    void FUN_00035fa0(int a);
    void FUN_0003f400(V3_2b970 *p);
    void FUN_000354e0(float a);
    void FUN_00035ce0(int a);
};

class Spawner_2b970 {
public:
    World *p0;
    Registry_2b970 *p4;
    char pad8[0x128 - 8];
    char name[0x100];
    char pad228[0x584 - 0x228];
    int f584;
    char b588;
    int FUN_00024280(unsigned int lo, unsigned int hi);
    int FUN_0002a3c0(Char_2b970 *c);
    void FUN_0002b590();
    char F(const char *defName, V3_2b970 pos, float angle, const char *name2, const char *anim, char flag8,
           const char *name9, char arg10);
};

static Comp_2b970 *MakeComp1(Ent_2b970 *e)
{
    void *m = FUN_0008d690(0xb0);
    return m ? ((Comp_2b970 *)m)->FUN_001076f0(e) : 0;
}
static Comp_2b970 *MakeComp2(Ent_2b970 *e)
{
    void *m = FUN_0008d690(0x1a0);
    return m ? ((Comp_2b970 *)m)->FUN_000ff180(e) : 0;
}
static Comp_2b970 *MakeComp3(Ent_2b970 *e)
{
    void *m = FUN_0008d690(0x74);
    return m ? ((Comp_2b970 *)m)->FUN_000fcb10(e) : 0;
}
static Comp_2b970 *MakeComp4(Ent_2b970 *e)
{
    void *m = FUN_0008d690(0xf4);
    return m ? ((Comp_2b970 *)m)->FUN_00105f50(e) : 0;
}
static Comp_2b970 *MakeComp5(Ent_2b970 *e)
{
    void *m = FUN_0008d690(0xf0);
    return m ? ((Comp_2b970 *)m)->FUN_00103340(e) : 0;
}

char Spawner_2b970::F(const char *defName, V3_2b970 pos, float angle, const char *name2, const char *anim, char flag8,
                const char *name9, char arg10)
{
    int old = FUN_00266da0(0xc);
    if ((*(char*)&DAT_004dc038)) {
        FUN_00266da0(old);
        return 0;
    }
    FUN_00267760(name, 0x100, "%s", name9);
    unsigned __int64 nh = FUN_0027b020(name);
    if (FUN_00024280((unsigned int)nh, (unsigned int)(nh >> 32))) {
        FUN_00266da0(old);
        return 0;
    }
    Registry_2b970 *reg0 = p4;
    unsigned __int64 dh = FUN_0027b020(defName);
    Def *def = reg0->FUN_00044ad0((unsigned int)dh, (unsigned int)(dh >> 32));
    if (!def) {
        unsigned __int64 dh2 = FUN_0027b020(defName);
        int i = 0;
        int n = p4->count;
        bool found = false;
        if (n > 0) {
            do {
                unsigned __int64 id = p4->FUN_00044ab0(i)->FUN_000443c0();
                if (id == dh2) {
                    found = true;
                    break;
                }
                i++;
            } while (i < p4->count);
        }
        if (!found) {
            FUN_00266da0(old);
            return 0;
        }
        def = p4->FUN_00044ab0(i);
        if (!def) {
            FUN_00266da0(old);
            return 0;
        }
    }
    Factory_2b970 *fac = p0->p44;
    int *fx = fac->FUN_00059b60();
    void *mem = thunk_FUN_0008d690(0x2300);
    Char_2b970 *ch;
    if (mem)
        ch = ((Char_2b970 *)mem)->FUN_00037860(fx);
    else
        ch = 0;
    ch->v0();
    Owner_2b970 *ow = fac->FUN_00059ba0(fx);
    if (ow)
        ow->FUN_00059cd0(ch);
    ch->FUN_00036d60(name);
    ch->FUN_00042b40(def);
    ch->FUN_0003f650();
    ch->FUN_000362f0();
    if (arg10 && !ch->FUN_00035a90()) {
        V3_2b970 A, B;
        ch->FUN_000368d0(0);
        ch->FUN_00035fa0(0);
        if (FUN_00202560(&pos, 10.0f, 0, &B, &A, 0, 0, 0))
            pos.y = B.y;
        ch->FUN_000368d0(1);
        ch->FUN_00035fa0(1);
    }
    ch->FUN_0003f400(&pos);
    ch->FUN_000354e0(angle * 0.0174532924f);
    bool doTail = false;
    if (ch->p128 == 0) {
        Ent_2b970 *ent = ch->p1ca0;
        unsigned __int64 did = def->FUN_000443c0();
        bool skipAll = (unsigned int)did == (*(unsigned int*)&DAT_004dc0e0) && (unsigned int)(did >> 32) == (*(unsigned int*)((char*)&DAT_004dc0e0 + 4));
        if (!skipAll) {
            if (!def->b37c) {
                if (def->b38c)
                    ent->FUN_000fdbd0(MakeComp1(ent));
                if (def->b38d)
                    ent->FUN_000fdbd0(MakeComp2(ent));
                if (def->b38e)
                    ent->FUN_000fdbd0(MakeComp3(ent));
                if (def->b38f)
                    ent->FUN_000fdbd0(MakeComp4(ent));
                if (def->b390) {
                    Comp_2b970 *c = MakeComp5(ent);
                    if (memcmp(anim, "none", 5) != 0)
                        c->FUN_00103b60(p0, anim, 0);
                    ent->FUN_000fdbd0(c);
                }
            }
            ent->name.FUN_0027b040(name2);
            ent->be8 = flag8;
        }
        if (ch->p128 == 0)
            doTail = true;
    }
    if (!doTail && !def->b37c) {
        Def *cd = ch->p11c;
        Ent_2b970 *ent = ch->p1ca0;
        if (cd->b390) {
            Comp_2b970 *c = MakeComp5(ent);
            if (memcmp(anim, "none", 5) != 0) {
                c->FUN_00103b60(p0, anim, 0);
                if (ch->p11c->f14 == 5)
                    c->FUN_001034b0((*(unsigned char*)&DAT_004dc288));
                else
                    c->FUN_001034b0(1);
            }
            ent->FUN_000fdbd0(c);
            ent->name.FUN_0027b040(name2);
            ent->be8 = flag8;
        }
        Def *cd2 = ch->p11c;
        Comp_2b970 *c2 = 0;
        bool add = false;
        if (cd2->f14 == 4) {
            if (cd2->b38c) {
                c2 = MakeComp1(ent);
                add = true;
            }
        } else {
            if (cd2->b38f) {
                c2 = MakeComp4(ent);
                add = true;
            }
        }
        if (add)
            ent->FUN_000fdbd0(c2);
        Def *cd3 = ch->p11c;
        if (cd3->f14 == 5 && cd3->b38c)
            ent->FUN_000fdbd0(MakeComp1(ent));
    }
    Pl2 *pl = p0->p20->f124;
    if (pl)
        ch->p1ca0->f60 = pl->f12c;
    ch->f1d7c = f584;
    ch->FUN_00035ce0((unsigned char)b588);
    if (b588 == 0 && f584 == 0x7fffffff)
        ch->f1d7c = 2;
    f584 = 0x7fffffff;
    b588 = 0;
    int res = FUN_0002a3c0(ch);
    Slot8_2b970 *s8 = p0->p3c->p8;
    Def *cd4 = ch->p11c;
    if (cd4 && cd4->f1b0 != 1 && s8) {
        if (s8->FUN_000cae70())
            s8->FUN_000cae70()->FUN_000c7d10(1, name9);
    }
    ch->v1();
    FUN_0002b590();
    FUN_00266da0(old);
    return res != -1;
}
