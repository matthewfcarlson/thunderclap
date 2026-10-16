// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 24/24)
// FUN_000f3940 @ 0x000f3940
#include "decls/address.h"
#include "decls/data/game/global.h"

class Entity {
public:
    virtual void AddRef();
    virtual void Release();
};

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

namespace pure3d {
class CompositeDrawable {
public:
    virtual void d0();
};
}

class Registry_f3940 {
public:
    virtual void r0();
    virtual void r1();
    virtual void r2();
    virtual Entity *lookup(content::LoadInventory::DynamicCasterBase *caster, unsigned __int64 id);
};

class FEControl {
public:
    virtual void c0();
};

class TextWindow : public FEControl {
public:
    char pad04[0x154 - 4];
    Entity *drawableA;        // 0x154
    Entity *drawableB;        // 0x158
    char pad15c[0x97c - 0x15c];
    float scale;              // 0x97c
    void FUN_000e3b70(Entity *e);
};

struct Token_f3940 {
    const char *FUN_000fad90();
    float FUN_000fad30();
    void FUN_000fa0a0();
};

class Parser_f3940 {
public:
    virtual void p0();
    virtual void p1();
    virtual void p2();
    virtual void p3();
    virtual void p4();
    virtual void p5();
    virtual void p6();
    virtual void p7();
    virtual void p8();
    virtual void p9();
    virtual void p10();
    virtual void p11();
    virtual void p12();
    virtual void p13();
    virtual void p14();
    virtual void p15();
    virtual void p16();
    virtual void p17();
    virtual void p18();
    virtual void p19();
    virtual void p20();
    virtual void p21();
    virtual void p22();
    virtual void p23();
    virtual void p24();
    virtual void p25();
    virtual void p26();
    virtual void p27();
    virtual void p28();
    virtual Entity *p29(const char *name, int flags);
};

class Node {
public:
    virtual void n0();
    virtual unsigned int tag();
};

class FEThingsBase {
public:
    class ParseFunctor;
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
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual int v34(Token_f3940 *a0, Node *a3, ParseFunctor *fn);
    virtual int v35(Token_f3940 *a0, Parser_f3940 *a1, FEControl *a2, Node *a3);
    virtual int v36(Token_f3940 *a0, Parser_f3940 *a1, FEControl *a2, Node *a3);
    class ParseFunctor {
    public:
        virtual void call();
        FEThingsBase *owner;
        void (FEThingsBase::*fn)(Token_f3940 *a0, Parser_f3940 *a1, FEControl *a2, Node *a3);
        Parser_f3940 *a1;
        FEControl *a2;
        ParseFunctor(FEThingsBase *o, void (FEThingsBase::*f)(Token_f3940 *, Parser_f3940 *, FEControl *, Node *), Parser_f3940 *p1, FEControl *p2)
            : owner(o), fn(f), a1(p1), a2(p2) {}
    };
    void FUN_000f3940(Token_f3940 *a0, Parser_f3940 *a1, FEControl *a2, Node *a3);
};

void FEThingsBase::FUN_000f3940(Token_f3940 *a0, Parser_f3940 *a1, FEControl *a2, Node *a3)
{
    TextWindow *win = dynamic_cast<TextWindow *>(a2);
    switch (a3->tag()) {
    case 0xcc74e7a7: {
        const char *nameA = a0->FUN_000fad90();
        Registry_f3940 *reg = (*(Registry_f3940**)&DAT_004dd9cc);
        unsigned __int64 idA = FUN_0027b020(nameA);
        content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable> casterA;
        Entity *e = reg->lookup(&casterA, idA);
        if (e)
            e->AddRef();
        if (win->drawableA)
            win->drawableA->Release();
        win->drawableA = e;
        const char *nameB = a0->FUN_000fad90();
        reg = (*(Registry_f3940**)&DAT_004dd9cc);
        unsigned __int64 idB = FUN_0027b020(nameB);
        content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable> casterB;
        e = reg->lookup(&casterB, idB);
        if (e)
            e->AddRef();
        if (win->drawableB)
            win->drawableB->Release();
        win->drawableB = e;
        return;
    }
    case 0x493f336b:
        win->scale = a0->FUN_000fad30();
        return;
    case 0x65ba5b03: {
        const char *s = a0->FUN_000fad90();
        const char *p = s;
        while (*p++ != 0) {
        }
        if (p - s - 1 != 0)
            win->FUN_000e3b70(a1->p29(s, 0));
        return;
    }
    default:
        break;
    }
    if ((char)v35(a0, a1, a2, a3))
        return;
    if ((char)v36(a0, a1, a2, a3))
        return;
    ParseFunctor fn(this, &FEThingsBase::FUN_000f3940, a1, a2);
    if ((char)v34(a0, a3, &fn))
        return;
    a0->FUN_000fa0a0();
}
