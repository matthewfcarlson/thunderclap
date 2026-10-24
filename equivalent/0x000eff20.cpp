// STATUS: equivalent (tools/equiv.py level 3: 3110 inputs, branch coverage 125/126, incomplete)
// FUN_000eff20 @ 0x000eff20
// equiv-map: ??_R0?AVCScriptToken@DollyScript@@@8 = 0x004a13e4
// equiv-map: ??_R0?AVCTokenString@DollyScript@@@8 = 0x004a140c
// equiv-map: ??_R0?AVCTokenFloat@DollyScript@@@8 = 0x004a13bc
#include "compat/ptr.h"
inline void *operator new(unsigned int, void *p) throw() { return p; }
void *FUN_0008d690(unsigned int size);
extern "C" char *__cdecl strncpy(char *, const char *, unsigned int);
void *__cdecl FUN_000f6610(const char *s);

namespace DollyScript {
class CScriptToken {
public:
    virtual void t0();
    virtual unsigned int GetType();
};
class CTokenString : public CScriptToken {
public:
    char pad04[0xc];
    const char *str;
};
class CTokenFloat : public CScriptToken {
public:
    char pad04[0xc];
    unsigned int value;
};
}

struct Parser_eff20 {
    float FUN_000fad30();
    unsigned int FUN_000faeb0();
    const char *FUN_000fad90();
    void FUN_000fa0a0();
    void FUN_000fa0b0(void *state);
    void FUN_000fa100(void *state);
    DollyScript::CScriptToken *FUN_000fb150();
};

class Callback_eff20 {
public:
    virtual void a();
    virtual void b();
};

class __declspec(novtable) FEDoAction_eff20 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    int type;
    int id1;
    int id2;
    void *parent;
    char name[0x20];
    FEDoAction_eff20(void *p)
    {
        id1 = -1;
        id2 = -1;
        parent = p;
        name[0] = 0;
    }
};

class FEDoWait : public FEDoAction_eff20 {
public:
    float limit;
    float elapsed;
    Callback_eff20 *callback;
    unsigned char done;
    FEDoWait(void *p, float lim) : FEDoAction_eff20(p)
    {
        limit = lim;
        callback = 0;
        elapsed = 0;
        done = 1;
    }
};

class FEDoBackScreen : public FEDoAction_eff20 {
public:
    unsigned char b34;
    unsigned char b35;
    FEDoBackScreen(void *p, unsigned char b, unsigned char c) : FEDoAction_eff20(p)
    {
        b34 = b;
        b35 = c;
    }
    FEDoBackScreen *FUN_000e1cf0(void *p, unsigned char b, unsigned char c);
};

struct FEDoSound_eff20 : FEDoAction_eff20 {
    char padA[0x54 - 0x34];
    FEDoSound_eff20 *FUN_000e1970(void *p, const char *s);
};
struct FEDoPopDialog_eff20 : FEDoAction_eff20 {
    char padB[0x34 - 0x34];
    FEDoPopDialog_eff20 *FUN_000e1c40(void *p);
};
struct FEDoBackMenu_eff20 : FEDoAction_eff20 {
    char padC[0x34 - 0x34];
    FEDoBackMenu_eff20 *FUN_000e1c60(void *p);
};
struct FEDoMenu_eff20 : FEDoAction_eff20 {
    char padE[0x54 - 0x34];
    FEDoMenu_eff20 *FUN_000e1b30(void *p, const char *s);
};
struct FEDoScreen_eff20 : FEDoAction_eff20 {
    char padF[0x54 - 0x34];
    FEDoScreen_eff20 *FUN_000e1c90(void *p, const char *s);
};
struct FEDoPushDialog_eff20 : FEDoAction_eff20 {
    char padG[0x1b8 - 0x34];
    FEDoPushDialog_eff20 *FUN_000e1b90(void *p, const char *a, const char *b, const char *c, const char *d, const char *e, int mode);
};
struct FEDoFunction_eff20 : FEDoAction_eff20 {
    char padS[0x3c - 0x34];
    int *items;
    FEDoFunction_eff20 *FUN_000e19d0(void *p, const char *name, int count);
};
struct FEDoAnimation_eff20 : FEDoAction_eff20 {
    char padH[0x40 - 0x34];
    unsigned int f40;
    char pad44[4];
    unsigned int f48;
    unsigned int f4c;
    char pad50;
    unsigned char b51;
    FEDoAnimation_eff20 *FUN_000e8a90(void *p, const char *s);
    void FUN_000e8650(unsigned int v);
    void FUN_000e86a0(unsigned int v);
};

class Owner_eff20 {
public:
    virtual void o0();
};
struct Parent_eff20 {
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
    virtual void Add(FEDoAction_eff20 *c);
};
struct Sink_eff20 {
    void FUN_000e2c60(FEDoAction_eff20 *c);
};

union Slot1 {
    Parser_eff20 *p;
    float f;
    unsigned char b;
    FEDoAction_eff20 *cmd;
    const char *s;
};

struct Frame_eff20 {
    hulk_uintptr off; // 0x10
    FEDoWait *objA;   // 0x14
    int id1;          // 0x18
    int id2;          // 0x1c
    const char *name; // 0x20
    void *self;       // 0x24
    const char *v1;   // 0x28
    unsigned int state[5]; // 0x2c
};

class Builder {
public:
    void FUN_000e76a0(FEDoAction_eff20 *c);
    void FUN_000eff20(Slot1 a1, Parent_eff20 *a2, Sink_eff20 *a3, int a4);
};

void Builder::FUN_000eff20(Slot1 a1, Parent_eff20 *a2, Sink_eff20 *a3, int a4)
{
    Frame_eff20 f;
    Parser_eff20 *p = a1.p;
    FEDoAction_eff20 *cmd = 0;
    int type = a4;
    f.self = this;
    f.objA = 0;
    f.id1 = 0;
    f.id2 = 0;
    f.name = "";
    Parent_eff20 *parent = a2;
    if (type == 4) {
        f.id1 = (int)p->FUN_000fad30();
        f.id2 = (int)p->FUN_000fad30();
    }
    int h = (int)p->FUN_000faeb0();
    if (h == (int)0xb07efca4) {
        f.name = p->FUN_000fad90();
        h = (int)p->FUN_000faeb0();
    }
    if (h == (int)0x9043fffb) {
        a1.f = p->FUN_000fad30();
        void *mem = FUN_0008d690(sizeof(FEDoWait));
        FEDoWait *w = 0;
        parent = a2;
        if (mem != 0)
            w = new (mem) FEDoWait(parent, a1.f);
        f.objA = w;
        w->type = type;
        h = (int)p->FUN_000faeb0();
    } else {
        parent = a2;
    }
    a1.b = 0;
    switch (h) {
    case (int)0x99d29fa1: {
        const char *s = p->FUN_000fad90();
        if (s == 0)
            p->FUN_000fa0a0();
        void *mem = FUN_0008d690(sizeof(FEDoSound_eff20));
        if (mem != 0)
            cmd = ((FEDoSound_eff20 *)mem)->FUN_000e1970(parent, s);
        cmd->type = type;
        break;
    }
    case (int)0x8df5383d: {
        void *mem = FUN_0008d690(sizeof(FEDoPopDialog_eff20));
        if (mem != 0)
            cmd = ((FEDoPopDialog_eff20 *)mem)->FUN_000e1c40(parent);
        cmd->type = type;
        break;
    }
    case (int)0xbe65b9e4: {
        void *mem = FUN_0008d690(sizeof(FEDoBackMenu_eff20));
        if (mem != 0)
            cmd = ((FEDoBackMenu_eff20 *)mem)->FUN_000e1c60(parent);
        cmd->type = type;
        break;
    }
    case (int)0x46667bbc: {
        const char *nm = p->FUN_000fad90();
        if (nm == 0)
            p->FUN_000fa0a0();
        p->FUN_000fa0b0(f.state);
        int count = 0;
        if (p->FUN_000fb150() != 0) {
            do {
                count++;
            } while (p->FUN_000fb150() != 0);
        }
        void *mem = FUN_0008d690(sizeof(FEDoFunction_eff20));
        FEDoFunction_eff20 *seq = 0;
        if (mem != 0)
            seq = ((FEDoFunction_eff20 *)mem)->FUN_000e19d0(a2, nm, count);
        a1.cmd = seq;
        cmd = a1.cmd;
        p->FUN_000fa100(f.state);
        DollyScript::CScriptToken *t = p->FUN_000fb150();
        if (t != 0) {
            f.off = 0;
            do {
                DollyScript::CTokenString *ts = dynamic_cast<DollyScript::CTokenString *>(t);
                if (ts == 0)
                    p->FUN_000fa0a0();
                const char *str = ts->str;
                if (str == 0)
                    str = "";
                FEDoFunction_eff20 *s2 = (FEDoFunction_eff20 *)a1.cmd;
                if (s2->items != 0)
                    *(hulk_intptr *)((char *)((FEDoFunction_eff20 *)a1.cmd)->items + f.off) = (hulk_intptr)FUN_000f6610(str);
                f.off += 4;
                t = p->FUN_000fb150();
            } while (t != 0);
        }
        ((FEDoFunction_eff20 *)a1.cmd)->type = type;
        break;
    }
    case (int)0x22989fa8:
        a1.b = 1;
    case (int)0xbabb057a: {
        const char *s = p->FUN_000fad90();
        if (s == 0)
            p->FUN_000fa0a0();
        void *mem = FUN_0008d690(sizeof(FEDoAnimation_eff20));
        FEDoAnimation_eff20 *ch = 0;
        if (mem != 0)
            ch = ((FEDoAnimation_eff20 *)mem)->FUN_000e8a90(parent, s);
        ch->b51 = a1.b;
        ch->type = type;
        DollyScript::CScriptToken *t = p->FUN_000fb150();
        if (t != 0) {
            if (t->GetType() == 0xdfc23ba3) {
                ch->f40 = 0x3f800000;
            } else {
                DollyScript::CTokenFloat *tf = dynamic_cast<DollyScript::CTokenFloat *>(t);
                if (tf == 0)
                    p->FUN_000fa0a0();
                ch->FUN_000e8650(tf->value);
            }
        }
        t = p->FUN_000fb150();
        if (t != 0) {
            DollyScript::CTokenFloat *tf = dynamic_cast<DollyScript::CTokenFloat *>(t);
            if (tf == 0)
                p->FUN_000fa0a0();
            ch->FUN_000e86a0(tf->value);
        }
        t = p->FUN_000fb150();
        if (t != 0) {
            DollyScript::CTokenFloat *tf = dynamic_cast<DollyScript::CTokenFloat *>(t);
            if (tf == 0)
                p->FUN_000fa0a0();
            ch->f48 = tf->value;
        }
        t = p->FUN_000fb150();
        if (t != 0) {
            DollyScript::CTokenFloat *tf = dynamic_cast<DollyScript::CTokenFloat *>(t);
            if (tf == 0)
                p->FUN_000fa0a0();
            ch->f4c = tf->value;
        }
        cmd = ch;
        break;
    }
    case (int)0x4f1ef819: {
        const char *s = p->FUN_000fad90();
        if (s == 0)
            p->FUN_000fa0a0();
        void *mem = FUN_0008d690(sizeof(FEDoScreen_eff20));
        if (mem != 0)
            cmd = ((FEDoScreen_eff20 *)mem)->FUN_000e1c90(parent, s);
        cmd->type = type;
        break;
    }
    case (int)0x5bbae3fc: {
        const char *s = p->FUN_000fad90();
        if (s == 0)
            p->FUN_000fa0a0();
        void *mem = FUN_0008d690(sizeof(FEDoMenu_eff20));
        if (mem != 0)
            cmd = ((FEDoMenu_eff20 *)mem)->FUN_000e1b30(parent, s);
        cmd->type = type;
        break;
    }
    case (int)0x5e245a31: {
        void *mem = FUN_0008d690(sizeof(FEDoBackScreen));
        if (mem != 0)
            cmd = ((FEDoBackScreen *)mem)->FUN_000e1cf0(parent, 0, 0);
        cmd->type = type;
        break;
    }
    case (int)0x70fab569: {
        void *mem = FUN_0008d690(sizeof(FEDoBackScreen));
        if (mem != 0)
            cmd = ((FEDoBackScreen *)mem)->FUN_000e1cf0(parent, 1, 0);
        cmd->type = type;
        break;
    }
    case (int)0x6ea9b311: {
        void *mem = FUN_0008d690(sizeof(FEDoBackScreen));
        if (mem != 0)
            cmd = new (mem) FEDoBackScreen(parent, 0, 1);
        cmd->type = type;
        break;
    }
    case (int)0x6a10e620: {
        f.v1 = p->FUN_000fad90();
        if (f.v1 == 0)
            p->FUN_000fa0a0();
        const char *v2 = p->FUN_000fad90();
        f.off = (hulk_uintptr)v2;
        if (v2 == 0)
            p->FUN_000fa0a0();
        a1.s = p->FUN_000fad90();
        if (a1.s == 0)
            p->FUN_000fa0a0();
        const char *v4 = p->FUN_000fad90();
        if (v4 == 0)
            p->FUN_000fa0a0();
        const char *v5 = p->FUN_000fad90();
        if (v5 == 0)
            p->FUN_000fa0a0();
        int mode = 0;
        unsigned int mh = p->FUN_000faeb0();
        if (mh == 0xce85a963)
            mode = 0;
        else if (mh == 0x320490b3)
            mode = 1;
        else if (mh == 0x5ebd3822)
            mode = 2;
        void *mem = FUN_0008d690(sizeof(FEDoPushDialog_eff20));
        FEDoPushDialog_eff20 *g = 0;
        if (mem != 0)
            g = ((FEDoPushDialog_eff20 *)mem)->FUN_000e1b90(a2, f.v1, (const char *)f.off, a1.s, v4, v5, mode);
        g->type = a4;
        cmd = g;
        break;
    }
    default:
        p->FUN_000fa0a0();
        break;
    }
    if (a4 == 4) {
        cmd->id1 = f.id1;
        cmd->id2 = f.id2;
    }
    if (cmd != 0) {
        cmd->v3();
        strncpy(cmd->name, f.name, 0x20);
        FEDoWait *w = f.objA;
        if (w != 0) {
            w->callback = (Callback_eff20 *)cmd;
            this->FUN_000e76a0(cmd);
            cmd = w;
        }
        this->FUN_000e76a0(cmd);
        a2->Add(cmd);
        if (a3 != 0)
            a3->FUN_000e2c60(cmd);
    }
}
