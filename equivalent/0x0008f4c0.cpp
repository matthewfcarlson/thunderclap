// STATUS: equivalent (tools/equiv.py level 3: 581 inputs, branch coverage 10/10)
// FUN_0008f4c0 @ 0x0008f4c0
struct Vertex {
    float x, y, z;
};

struct Mesh {
    char pad00[8];
    Vertex* vert;
    char pad0c[4];
    unsigned int* color;
    void FUN_0008ef00();
};

class Res {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6(int tag, int flag);
};

struct Gfx {
    char pad00[0x10];
    Res* res;
};

class Device {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24(int v);
    virtual int vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual Mesh* vfunc_30(Res* res, int a, int b, int c, int d);
    virtual void vfunc_31(Mesh* m);
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43();
    virtual void vfunc_44();
    virtual void vfunc_45();
    virtual void vfunc_46();
    virtual void vfunc_47();
    virtual void vfunc_48();
    virtual void vfunc_49();
    virtual void vfunc_50();
    virtual void vfunc_51();
    virtual void vfunc_52();
    virtual void vfunc_53();
    virtual void vfunc_54(unsigned int v);
    virtual int vfunc_55();
    virtual void vfunc_56();
    virtual void vfunc_57();
    virtual void vfunc_58(unsigned int v);
    virtual char vfunc_59();
};

class Holder {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13(int v);
    virtual void vfunc_14();
    virtual void vfunc_15(int v);
    virtual void vfunc_16(int v);
};

struct Label {
    void FUN_0008f3a0();
};

struct Overlay {
    char pad00[4];
    int count;
    Label* items[1];
};

extern Device* DAT_0052c2a8;
extern Holder** DAT_0052c2ac;
Gfx* FUN_00085cd0();
void FUN_00085d30();

struct Frame {
    union {
        int i;
        float y;
    } tmp;
    Overlay* self;
    int save1;
    union {
        char b;
        unsigned int w;
    } save2;
    int save3;
};

class DebugOverlay : public Overlay {
public:
    void FUN_0008f4c0();
};

void DebugOverlay::FUN_0008f4c0()
{
    Frame f;
    f.self = this;
    if (!FUN_00085cd0())
        FUN_00085d30();
    f.save1 = DAT_0052c2a8->vfunc_25();
    f.save2.b = DAT_0052c2a8->vfunc_59();
    f.save3 = DAT_0052c2a8->vfunc_55();
    DAT_0052c2a8->vfunc_24(2);
    DAT_0052c2a8->vfunc_58(0);
    DAT_0052c2a8->vfunc_54(0);
    (*DAT_0052c2ac)->vfunc_15(0);
    (*DAT_0052c2ac)->vfunc_13(0);

    Gfx* gfx = FUN_00085cd0();
    gfx->res->vfunc_6(0x444d4c42, 1);

    Mesh* m = DAT_0052c2a8->vfunc_30(gfx->res, 1, 0x2020, 4, 0);
    {
        Vertex* v = m->vert;
        v->x = 70.0f;
        v->y = 20.0f;
        v->z = 1.0f;
        *m->color = 0x80404040;
        m->FUN_0008ef00();
    }
    {
        Vertex* v = m->vert;
        v->x = 570.0f;
        v->y = 20.0f;
        v->z = 1.0f;
        *m->color = 0x80404040;
        m->FUN_0008ef00();
    }
    {
        Vertex* v = m->vert;
        v->x = 70.0f;
        v->y = 204.0f;
        v->z = 1.0f;
        *m->color = 0x80404040;
        m->FUN_0008ef00();
    }
    {
        Vertex* v = m->vert;
        v->x = 570.0f;
        v->y = 204.0f;
        v->z = 1.0f;
        *m->color = 0x80404040;
        m->FUN_0008ef00();
    }
    DAT_0052c2a8->vfunc_31(m);

    m = DAT_0052c2a8->vfunc_30(gfx->res, 3, 0x2020, 5, 0);
    {
        Vertex* v = m->vert;
        v->x = 70.0f;
        v->y = 20.0f;
        v->z = 1.0f;
        *m->color = 0x40ffffff;
        m->FUN_0008ef00();
    }
    {
        Vertex* v = m->vert;
        v->x = 570.0f;
        v->y = 20.0f;
        v->z = 1.0f;
        *m->color = 0x40ffffff;
        m->FUN_0008ef00();
    }
    {
        Vertex* v = m->vert;
        v->x = 570.0f;
        v->y = 204.0f;
        v->z = 1.0f;
        *m->color = 0x40ffffff;
        m->FUN_0008ef00();
    }
    {
        Vertex* v = m->vert;
        v->x = 70.0f;
        v->y = 204.0f;
        v->z = 1.0f;
        *m->color = 0x40ffffff;
        m->FUN_0008ef00();
    }
    {
        Vertex* v = m->vert;
        v->x = 70.0f;
        v->y = 20.0f;
        v->z = 1.0f;
        *m->color = 0x40ffffff;
        m->FUN_0008ef00();
    }
    DAT_0052c2a8->vfunc_31(m);

    m = DAT_0052c2a8->vfunc_30(gfx->res, 2, 0x2020, 0x14, 0);
    for (int i = 1; i <= 10; i++) {
        Vertex* v = m->vert;
        f.tmp.i = i;
        v->x = 70.0f;
        v->z = 1.0f;
        f.tmp.y = 204.0f - (float)f.tmp.i * 18.4f;
        v->y = f.tmp.y;
        *m->color = 0x40000000;
        m->FUN_0008ef00();
        v = m->vert;
        v->y = f.tmp.y;
        v->x = 570.0f;
        v->z = 1.0f;
        *m->color = 0x40000000;
        m->FUN_0008ef00();
    }
    DAT_0052c2a8->vfunc_31(m);

    m = DAT_0052c2a8->vfunc_30(gfx->res, 2, 0x2020, 0xa, 0);
    for (int i = 1; i <= 5; i++) {
        Vertex* v = m->vert;
        f.tmp.i = i;
        v->x = 70.0f;
        v->z = 1.0f;
        f.tmp.y = 204.0f - (float)f.tmp.i * 36.8f;
        v->y = f.tmp.y;
        *m->color = 0x40ffffff;
        m->FUN_0008ef00();
        v = m->vert;
        v->y = f.tmp.y;
        v->x = 570.0f;
        v->z = 1.0f;
        *m->color = 0x40ffffff;
        m->FUN_0008ef00();
    }
    DAT_0052c2a8->vfunc_31(m);

    Overlay* ov = f.self;
    for (int i = 0; i < ov->count; i++)
        ov->items[i]->FUN_0008f3a0();

    DAT_0052c2a8->vfunc_24(f.save1);
    DAT_0052c2a8->vfunc_58(f.save2.w);
    DAT_0052c2a8->vfunc_54(f.save3);
    (*DAT_0052c2ac)->vfunc_16(0);
}
