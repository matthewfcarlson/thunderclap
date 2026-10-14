// STATUS: equivalent (tools/equiv.py level 3: 3030 inputs, branch coverage 30/30)
// CSPListener::vfunc_0 @ 0x001db230
// equiv-map: ??0Name@@QAE@ABU0@@Z = 0x0027af30
extern "C" int __cdecl _sprintf(char *, const char *, ...);
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern unsigned int DAT_004d9968;

struct V3_1db230 {
    float x, y, z;
};
extern V3_1db230 DAT_004c6160;

struct Name {
    int a, b;
    Name(const Name &o);
};

struct Mat_1db230 {
    float m[16];
    void FUN_0022c3b0(const V3_1db230 *in, V3_1db230 *out);
    void FUN_0022cc90(V3_1db230 *v);
};

struct Evt {
    char data[0x38];
    Evt *FUN_001ca6b0(Name n1, Name n2, int a, int b, int c);
    Evt *FUN_001caae0(Name n1, int k, Name n2, int a, int b, int c, int d);
};

struct Sink_1db230 {
    void FUN_001cbc20(Evt *e);
};

struct Fec {
    char pad0[8];
    Name name;
    char pad10[0xac - 0x10];
    int FUN_001d4e10();
    int FUN_001d5710();
};

struct Inner_1db230 {
    char pad0[0x10];
    int *f10;
};

struct Link_1db230 {
    char pad0[8];
    Inner_1db230 *f08;
    int kind;
};

class Obj_1db230 {
public:
    virtual void s00();
    virtual void s01();
    virtual void s02();
    virtual void s03();
    virtual void s04();
    virtual void s05();
    virtual void s06();
    virtual void s07();
    virtual void s08();
    virtual void s09();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual Mat_1db230 *v3c();
    char pad04[4];
    Name name8;
    char pad10[0x40 - 0x10];
    int f40;
    char pad44[0xec - 0x44];
    Fec *fec;
    char padf0[0x114 - 0xf0];
    Link_1db230 *f114;
    void *FUN_001d6490();
    V3_1db230 *FUN_001d6b40();
    void FUN_001d72a0();
    char FUN_001d6a90();
    int FUN_001d7100(int v);
    void FUN_001d7e70();
    void FUN_001db110(unsigned int a2);
    void FUN_001d6b60(Mat_1db230 m, int z);
};

struct Ctx_1db230 {
    char pad0[0xc];
    struct Obj0c_1db230 *f0c;
    struct Obj10_1db230 *f10;
    char pad14[0x20 - 0x14];
    struct Obj20_1db230 *f20;
    char pad24[0x30 - 0x24];
    Sink_1db230 *f30;
    struct Ui_1db230 *f34;
};
struct Obj0c_1db230 {
    void FUN_001e5720(unsigned int a2);
};
struct Obj10_1db230 {
    void FUN_001b4620(V3_1db230 pos, int a, int b, int c);
};
struct Obj20_1db230 {
    void FUN_00025470(unsigned int a2);
};
struct Ui_1db230 {
    void FUN_001ebd80(unsigned int a2, const char *name, float t, int z);
};
struct World0c {
    void FUN_001deda0(unsigned int a2);
    void FUN_001dd2c0(unsigned int a2, int k);
};
struct World {
    char pad0[0xc];
    World0c *f0c;
    char pad10[0x30 - 0x10];
    Sink_1db230 *f30;
};
extern World *DAT_004dd700;

const char *__cdecl FUN_001b46f0(void *l, unsigned int *out);

struct Ev_1db230 {
    char pad0[8];
    int type;
};

class CSPListener {
public:
    virtual void vfunc_0(Ev_1db230 *a1, unsigned int a2);
    char pad04[8];
    Ctx_1db230 *fc;
    void FUN_001db110(unsigned int a2);
};

void CSPListener::vfunc_0(Ev_1db230 *a1, unsigned int a2)
{
    unsigned int cookie = DAT_004d9968;
    int type = a1->type;
    Ctx_1db230 *u = fc;
    switch (type) {
    case 1:
        fc->f0c->FUN_001e5720(a2);
        break;
    case 2:
        fc->f34->FUN_001ebd80(a2, "Opened", 100.0f, 0);
        break;
    case 3:
        fc->f34->FUN_001ebd80(a2, "Closed", 100.0f, 0);
        break;
    case 8:
        FUN_001db110(a2);
        fc->f34->FUN_001ebd80(a2, "Broken", 100.0f, 0);
        break;
    case 4: {
        Obj10_1db230 *o = fc->f10;
        V3_1db230 *p = ((Obj_1db230 *)a2)->FUN_001d6b40();
        o->FUN_001b4620(*p, 0, 0, 0);
        fc->f34->FUN_001ebd80(a2, "ExplosionSmall", 100.0f, 0);
        break;
    }
    case 5: {
        Obj10_1db230 *o = fc->f10;
        V3_1db230 *p = ((Obj_1db230 *)a2)->FUN_001d6b40();
        o->FUN_001b4620(*p, 1, 0, 0);
        fc->f34->FUN_001ebd80(a2, "ExplosionMedium", 100.0f, 0);
        break;
    }
    case 6: {
        Obj10_1db230 *o = fc->f10;
        V3_1db230 *p = ((Obj_1db230 *)a2)->FUN_001d6b40();
        o->FUN_001b4620(*p, 2, 0, 0);
        fc->f34->FUN_001ebd80(a2, "ExplosionBig", 100.0f, 0);
        break;
    }
    case 10: case 11: case 12: case 13: case 14:
    case 15: case 16: case 17: case 18: case 19: {
        Obj10_1db230 *o = fc->f10;
        V3_1db230 *p = ((Obj_1db230 *)a2)->FUN_001d6b40();
        o->FUN_001b4620(*p, type - 7, 0, 0);
        fc->f34->FUN_001ebd80(a2, "ExplosionSmall", 100.0f, 0);
        break;
    }
    case 20:
        ((Obj_1db230 *)a2)->FUN_001d72a0();
        break;
    case 21:
        fc->f20->FUN_00025470(a2);
        break;
    case 23: {
        Obj_1db230 *o = (Obj_1db230 *)a2;
        Mat_1db230 m = *o->v3c();
        V3_1db230 v;
        v.x = 0.0f;
        v.y = 0.0f;
        v.z = 0.0f;
        m.FUN_0022c3b0(&DAT_004c6160, &v);
        m.FUN_0022cc90(&v);
        o->FUN_001d6b60(m, 0);
        break;
    }
    case 9:
        DAT_004dd700->f0c->FUN_001deda0(a2);
        break;
    case 24:
        DAT_004dd700->f0c->FUN_001dd2c0(a2, 0xe);
        break;
    case 25:
        DAT_004dd700->f0c->FUN_001dd2c0(a2, 0xf);
        break;
    case -1: {
        Obj_1db230 *o = (Obj_1db230 *)a2;
        int total = o->fec->FUN_001d5710();
        int cur = o->f40;
        if (cur == total - 1) {
            a2 = 0;
            const char *r = FUN_001b46f0(o->FUN_001d6490(), &a2);
            Fec *fec = o->fec;
            Evt ev;
            ev.FUN_001ca6b0(o->name8, fec->name, fec->FUN_001d4e10(), (int)r, a2);
            DAT_004dd700->f30->FUN_001cbc20(&ev);
        }
        if (!o->FUN_001d6a90()) {
            char buf[16];
            _sprintf(buf, "State_%d", o->f40);
            u->f34->FUN_001ebd80((unsigned int)o, buf, 100.0f, 0);
            Sink_1db230 *sink = fc->f30;
            if (sink != 0) {
                a2 = 0;
                const char *r = FUN_001b46f0(o->FUN_001d6490(), &a2);
                int inner = 0;
                Link_1db230 *l = o->f114;
                if (l != 0 && l->kind == 1 && l->f08 != 0)
                    inner = *l->f08->f10;
                Fec *fec = o->fec;
                Evt ev;
                ev.FUN_001caae0(o->name8, o->FUN_001d7100(-1), fec->name, fec->FUN_001d4e10(), (int)r, a2, inner);
                sink->FUN_001cbc20(&ev);
            }
        }
        o->FUN_001d7e70();
        break;
    }
    default:
        break;
    }
    __security_check_cookie(cookie);
}
