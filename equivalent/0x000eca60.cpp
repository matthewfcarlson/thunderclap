// STATUS: equivalent (tools/equiv.py level 3: 57 inputs, branch coverage 17/20, incomplete)
// TextLabel::vfunc_5 @ 0x000eca60
struct Vec3_eca60 {
    float x, y, z;
};

union Word_eca60 {
    float f;
    int i;
    unsigned int u;
};

struct Cell_eca60 {
    Word_eca60 a, b, c, d;
};

struct Source_eca60;

struct Builder {
    unsigned int hdr[2];
    Cell_eca60 cells[8];
    int cursor;
    float scale;
    void FUN_000f7fe0(Source_eca60 *src);
    void FUN_000f78e0();
    void FUN_000f87f0(void *a, void *b);
};

namespace pure3d {
class FrameController {
public:
    virtual void v0();
    virtual void v1();
};

class TextureAnimationController : public FrameController {
public:
    virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(int value);
};
}

class TextLabel;

class Source_eca60 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17();
    virtual pure3d::FrameController *v18(int a);
};

struct Level2_eca60 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual Source_eca60 *v44();
};

struct Level1_eca60 {
    char pad0[4];
    Level2_eca60 *level2;
};

struct Level0 {
    char pad0[8];
    Level1_eca60 *level1;
};

class Owner_eca60 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13();
    virtual void v14(Vec3_eca60 *out, TextLabel *obj);
    virtual void v15(Vec3_eca60 *out, TextLabel *obj);
    virtual float v16(TextLabel *obj);
    virtual float v17(TextLabel *obj);
    char pad04[4];
    Level1_eca60 *p8;
};

struct Pass_eca60 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(int a);
    virtual void v16(int a);
};

struct PassHolder_eca60 {
    Pass_eca60 *pass;
    void FUN_00293d00(const Vec3_eca60 *v);
    void FUN_00293c80(int a, int b, int c);
    void FUN_00293da0(int a, int b, int c);
};

class Widget_eca60 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(int a, int b);
};

struct Inner3c_eca60 {
    char pad0[8];
    Source_eca60 *source;
};

struct Inner44 {
    char pad0[0x3c];
    Inner3c_eca60 *p3c;
};

struct Child50 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(int a, int b);
    char pad04[0x44 - 4];
    Inner44 *p44;
};

extern PassHolder_eca60 *DAT_0052c2ac;

void __cdecl FUN_000e11a0(Vec3_eca60 v, int a, int b);
void __cdecl FUN_000e0cc0(Vec3_eca60 v, int a, int b);

class TextLabel {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();

    char pad04[0x10];
    Owner_eca60 *owner;               // 0x14
    char sub18[0x3c - 0x18];    // 0x18
    unsigned int color;         // 0x3c
    unsigned char flag40;
    char pad41[3];
    int val44;                  // 0x44
    unsigned char flag48;
    char pad49[3];
    int val4c;                  // 0x4c
    Child50 *child;             // 0x50
    int v54, v58, v5c;          // 0x54
    Widget_eca60 *w60;                // 0x60
    Widget_eca60 *w64;                // 0x64
    char pad68[4];
    unsigned int v6c;           // 0x6c
    unsigned int v70;           // 0x70
    unsigned char active;       // 0x74
    char pad75[3];
    Vec3_eca60 anchor;                // 0x78
    char pad84[0xac - 0x84];
    void *val_ac;               // 0xac
    char padb0[0x118 - 0xb0];
    int v118, v11c, v120, v124; // 0x118
};

struct Frame_eca60 {
    Vec3_eca60 v1;
    float f1;
    Builder x;
};

void TextLabel::vfunc_5()
{
    if (active == 0)
        return;

    Frame_eca60 f;

    if (flag40 == 1) {
        DAT_0052c2ac->pass->v15(0);
        owner->v14(&f.v1, this);
        DAT_0052c2ac->FUN_00293d00(&f.v1);
        owner->v15(&f.v1, this);
        FUN_000e11a0(f.v1, val44, 2);
        DAT_0052c2ac->pass->v16(0);
    }
    if (flag48 == 1) {
        DAT_0052c2ac->pass->v15(0);
        owner->v14(&f.v1, this);
        DAT_0052c2ac->FUN_00293d00(&f.v1);
        owner->v15(&f.v1, this);
        FUN_000e0cc0(f.v1, val4c, 0);
        DAT_0052c2ac->pass->v16(0);
    }
    if (child != 0) {
        Source_eca60 *obj = child->p44->p3c->source;
        pure3d::TextureAnimationController *tac =
            dynamic_cast<pure3d::TextureAnimationController *>(obj->v18(0));
        if (tac != 0) {
            tac->v12(v118);
            tac->v7();
        }
        DAT_0052c2ac->pass->v15(0);
        owner->v14(&f.v1, this);
        DAT_0052c2ac->FUN_00293d00(&f.v1);
        DAT_0052c2ac->FUN_00293c80(v11c, v120, v124);
        DAT_0052c2ac->FUN_00293da0(v54, v58, v5c);
        child->v8(0, 0);
        DAT_0052c2ac->pass->v16(0);
    }

    f.x.FUN_000f7fe0(owner->p8->level2->v44());
    unsigned int saved = color;
    if (w60 != 0)
        color = saved & 0xff000000;
    f.x.cells[f.x.cursor].c.u = v70;
    f.x.cells[f.x.cursor].b.u = v6c;
    f.f1 = owner->v17(this);
    f.x.cells[f.x.cursor].a.f = owner->v16(this) * f.f1;
    f.x.cells[f.x.cursor].d.u = color;
    f.x.hdr[1] = color;
    DAT_0052c2ac->pass->v15(0);
    owner->v14(&f.v1, this);
    DAT_0052c2ac->FUN_00293d00(&f.v1);
    DAT_0052c2ac->FUN_00293d00(&anchor);
    if (w60 != 0)
        w60->v8(0, 0);
    if (w64 != 0)
        w64->v8(0, 0);
    void *arg;
    if (val_ac != 0)
        arg = val_ac;
    else if (w60 != 0)
        arg = 0;
    else
        arg = (char *)owner->p8 + 0x978;
    f.x.FUN_000f87f0(sub18, arg);
    color = saved;
    DAT_0052c2ac->pass->v16(0);
    f.x.FUN_000f78e0();
}
