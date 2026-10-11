// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_001b6fd0 @ 0x001b6fd0
struct Surface;
struct Vertices {
    void FUN_0008ef00();
    char pad0[8];
    float *pos;
    char pad1[4];
    unsigned int *color;
};
struct Screen {
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual int vfn6();
    virtual int vfn7();
};
struct Device {
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6();
    virtual void vfn7();
    virtual void vfn8();
    virtual void vfn9();
    virtual void vfn10();
    virtual void vfn11();
    virtual void vfn12();
    virtual void vfn13();
    virtual void vfn14();
    virtual void vfn15();
    virtual void vfn16();
    virtual void vfn17();
    virtual void vfn18();
    virtual void vfn19();
    virtual void vfn20();
    virtual void vfn21();
    virtual void vfn22();
    virtual void vfn23();
    virtual void vfn24(int v);
    virtual int vfn25();
    virtual void vfn26();
    virtual void vfn27();
    virtual void vfn28();
    virtual void vfn29();
    virtual Vertices *vfn30(Surface *s, int a, int b, int c, int d);
    virtual void vfn31(Vertices *v);
    virtual void vfn32();
    virtual void vfn33();
    virtual void vfn34();
    virtual void vfn35();
    virtual void vfn36();
    virtual void vfn37();
    virtual void vfn38();
    virtual void vfn39();
    virtual void vfn40();
    virtual void vfn41();
    virtual void vfn42();
    virtual void vfn43();
    virtual void vfn44();
    virtual void vfn45();
    virtual void vfn46();
    virtual void vfn47();
    virtual void vfn48();
    virtual void vfn49();
    virtual void vfn50();
    virtual void vfn51();
    virtual void vfn52();
    virtual void vfn53();
    virtual void vfn54(int v);
    virtual void vfn55();
    virtual void vfn56();
    virtual void vfn57();
    virtual void vfn58(int v);
};
struct Stage {
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6();
    virtual void vfn7();
    virtual void vfn8();
    virtual void vfn9();
    virtual void vfn10();
    virtual void vfn11();
    virtual void vfn12();
    virtual void vfn13(int v);
    virtual void vfn14();
    virtual void vfn15(int v);
    virtual void vfn16(int v);
};

extern Screen *DAT_0052c2a4;
extern Device *DAT_0052c2a8;
extern Stage **DAT_0052c2ac;

struct Holder {
    char pad[0x10];
    Surface *surface;
};

class Fader {
public:
    void FUN_001b6fd0(int alpha);
    char pad0[0xc];
    Holder *holder;
};

void Fader::FUN_001b6fd0(int alpha)
{
    float w = (float)DAT_0052c2a4->vfn7();
    float h = (float)DAT_0052c2a4->vfn6();
    int saved = DAT_0052c2a8->vfn25();
    DAT_0052c2a8->vfn24(2);
    DAT_0052c2a8->vfn54(0);
    DAT_0052c2a8->vfn58(0);
    (*DAT_0052c2ac)->vfn15(0);
    (*DAT_0052c2ac)->vfn13(0);

    unsigned int color = (unsigned int)alpha << 24;
    Vertices *v = DAT_0052c2a8->vfn30(holder->surface, 1, 0x2020, 4, 0);
    v->color[0] = color;
    v->pos[0] = 0;
    v->pos[1] = h;
    v->pos[2] = 2.0f;
    v->FUN_0008ef00();

    v->color[0] = color;
    v->pos[0] = 0;
    v->pos[1] = 0;
    v->pos[2] = 2.0f;
    v->FUN_0008ef00();

    v->color[0] = color;
    v->pos[0] = w;
    v->pos[1] = h;
    v->pos[2] = 2.0f;
    v->FUN_0008ef00();

    v->color[0] = color;
    v->pos[0] = w;
    v->pos[1] = 0;
    v->pos[2] = 2.0f;
    v->FUN_0008ef00();

    DAT_0052c2a8->vfn31(v);
    DAT_0052c2a8->vfn24(saved);
    DAT_0052c2a8->vfn54(1);
    DAT_0052c2a8->vfn58(1);
    (*DAT_0052c2ac)->vfn16(0);
}
