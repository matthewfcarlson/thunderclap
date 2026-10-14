// STATUS: equivalent (tools/equiv.py level 3: 3077 inputs, branch coverage 72/72)
// FUN_000f42c0 @ 0x000f42c0
struct Pair64 {
    unsigned int lo, hi;
};
Pair64 __cdecl FUN_0027b020(const char *s);

namespace content {
namespace LoadInventory {
class __declspec(novtable) DynamicCasterBase {
public:
    virtual void cast(void *p) = 0;
};

template <class T>
class DynamicCaster : public DynamicCasterBase {
public:
    virtual void cast(void *p);
};
}
}

namespace pure3d { class CompositeDrawable; }

struct Color_f42c0 {
    int value;
    Color_f42c0 *FUN_000115c0(int r, int g, int b, int a);
};

class Reg_f42c0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void *v3(content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable> *caster, unsigned int lo, unsigned int hi);
};
extern Reg_f42c0 *DAT_004dd9cc;
int __cdecl FUN_000c0d80(Reg_f42c0 *g, const char *s);

struct ParseState {
    char data[0x24];
    void FUN_000f7930();
    void FUN_000f7960();
    void FUN_000f8500(const char *name, void *node, char flag);
};

class Param {
public:
    float FUN_000fad30();
    const char *FUN_000fad90();
    int FUN_000faeb0();
    char FUN_000f9e90();
    void FUN_000fa0a0();
    class Child_f42c0 *FUN_000fb150();
};

class Child_f42c0 {
public:
    virtual void v0();
    virtual int GetHash();
};

class Args_f42c0 {
public:
    virtual void v0();
    virtual int GetType();
};

struct Made_f42c0 {
    char pad0[0x74];
    char f74;
};

class Factory_f42c0 {
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
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual Made_f42c0 *v29(const char *name, int z);
};

class Target_f42c0 {
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
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19(ParseState *st, int flag, void *p);
    virtual void v20();
    virtual void v21();
    virtual void v22(float f);
    virtual void v23(float f);
    virtual void v24(float f);
    char pad04[0x1d5c - 4];
    int f1d5c;
    char pad1d60[0x1d98 - 0x1d60];
    Made_f42c0 *f1d98;
    char pad1d9c[0x1da4 - 0x1d9c];
    int f1da4;
    void FUN_000ebda0(int v);
    void FUN_000ebdd0(int v);
    void FUN_000e2f80(const char *s);
    void FUN_000e3770(Made_f42c0 *m);
};

union Slot3 {
    Target_f42c0 *d;
    char flag;
    int w;
};

class FEThingsBase {
public:
    class ParseFunctor {
    public:
        virtual void vfunc_0(int a, int b);
        FEThingsBase *mObj;
        void (FEThingsBase::*mFn)(Param *, Factory_f42c0 *, Slot3, Args_f42c0 *);
        Factory_f42c0 *mC;
        Target_f42c0 *mD;
    };

    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void v33(Child_f42c0 *c, ParseState *st);
    virtual char v34(Param *p, Args_f42c0 *a, ParseFunctor *f);
    virtual char v35(Param *p, Factory_f42c0 *c, Target_f42c0 *d, Args_f42c0 *a);
    virtual char v36(Param *p, Factory_f42c0 *c, Target_f42c0 *d, Args_f42c0 *a);
    virtual void w37();
    virtual void w38();
    virtual void w39();
    virtual void w40();
    virtual void w41();
    virtual void w42();
    virtual void w43();
    virtual void *v44();

    void FUN_000f42c0(Param *p, Factory_f42c0 *c, Slot3 d3, Args_f42c0 *args);
};

inline void *operator new(unsigned int, void *p) throw() { return p; }

struct Frame_f42c0 {
    int pad10;
    char raw[0x24];
};

static __forceinline int StrLen(const char *s)
{
    const char *e = s;
    while (*e++ != 0) {
    }
    return (int)(e - s) - 1;
}

void FEThingsBase::FUN_000f42c0(Param *p, Factory_f42c0 *c, Slot3 d3, Args_f42c0 *args)
{
    Frame_f42c0 fr;
    Target_f42c0 *d = d3.d;
    int type = args->GetType();
    switch (type) {
    case 0xbd69b501: {
        float f = p->FUN_000fad30();
        if (f >= 0.0f)
            d->v23(f);
        return;
    }
    case 0xde237f67: {
        float f = p->FUN_000fad30();
        if (f >= 0.0f)
            d->v24(f);
        return;
    }
    case 0x493f336b: {
        float f = p->FUN_000fad30();
        if (f >= 0.0f)
            d->v22(f);
        return;
    }
    case 0x8ebfb676: {
        int r = (int)p->FUN_000fad30();
        int g = (int)p->FUN_000fad30();
        int b = (int)p->FUN_000fad30();
        int a = 0xff;
        if (p->FUN_000f9e90())
            a = (int)p->FUN_000fad30();
        Color_f42c0 col;
        d->f1da4 = col.FUN_000115c0(r, g, b, a)->value;
        return;
    }
    case 0xcc74e7a7: {
        d->FUN_000ebda0(FUN_000c0d80(DAT_004dd9cc, p->FUN_000fad90()));
        d->FUN_000ebdd0(FUN_000c0d80(DAT_004dd9cc, p->FUN_000fad90()));
        return;
    }
    case 0xe10f2442:
        d->FUN_000e2f80(p->FUN_000fad90());
        return;
    case 0x091ece77: {
        const char *name = p->FUN_000fad90();
        if (StrLen(name) != 0) {
            d->f1d98 = c->v29(name, 0);
            if (d->f1d98 != 0)
                d->f1d98->f74 = 0;
        }
        if (!p->FUN_000f9e90())
            return;
        do {
            (*(ParseState *)fr.raw).FUN_000f7930();
            (*(ParseState *)fr.raw).FUN_000f8500("", v44(), 1);
            const char *tag = p->FUN_000fad90();
            Reg_f42c0 *g = DAT_004dd9cc;
            Pair64 h = FUN_0027b020(tag);
            content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable> *caster =
                new ((void *)&d3) content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable>;
            void *obj = g->v3(caster, h.lo, h.hi);
            d->v19((ParseState *)fr.raw, 0, obj);
            (*(ParseState *)fr.raw).FUN_000f7960();
        } while (p->FUN_000f9e90());
        return;
    }
    case 0x65ba5b03: {
        const char *name = p->FUN_000fad90();
        if (StrLen(name) == 0)
            return;
        d->FUN_000e3770(c->v29(name, 0));
        return;
    }
    case 0x1babae77: {
        int v = p->FUN_000faeb0();
        if (v == 0x3e33165a)
            d->f1d5c = 1;
        else if (v == 0x56a6a191)
            d->f1d5c = 2;
        else if (v == 0x612213a0)
            d->f1d5c = 0;
        else
            p->FUN_000fa0a0();
        return;
    }
    case 0x76744a71: {
        const char *name = p->FUN_000fad90();
        if (StrLen(name) != 0) {
            d->f1d98 = c->v29(name, 0);
            if (d->f1d98 != 0)
                d->f1d98->f74 = 0;
        }
        d3.flag = 0;
        Child_f42c0 *ch = p->FUN_000fb150();
        while (ch != 0) {
            if (ch->GetHash() == 0x1f4ee86f) {
                d3.flag = 1;
            } else {
                (*(ParseState *)fr.raw).FUN_000f7930();
                v33(ch, (ParseState *)fr.raw);
                d->v19((ParseState *)fr.raw, d3.w, 0);
                d3.flag = 0;
                (*(ParseState *)fr.raw).FUN_000f7960();
            }
            ch = p->FUN_000fb150();
        }
        return;
    }
    }

    if (v35(p, c, d, args))
        return;
    if (v36(p, c, d, args))
        return;
    ParseFunctor *f = new (fr.raw) ParseFunctor;
    f->mObj = this;
    f->mFn = &FEThingsBase::FUN_000f42c0;
    f->mC = c;
    f->mD = d;
    if (v34(p, args, f))
        return;
    p->FUN_000fa0a0();
}
