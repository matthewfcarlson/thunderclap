// STATUS: equivalent (tools/equiv.py level 3: 73 inputs, branch coverage 12/12)
// FUN_001c46a0 @ 0x001c46a0
struct Vertex_1c46a0 {
    char pad0[8];
    float *pos;
    char padc[4];
    unsigned int *color;
    void FUN_0008ef00();
};

struct Surface_1c46a0 {
    char pad0[0x10];
    void *handle;
};

class Device_1c46a0 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5();
    virtual int Height();
    virtual int Width();
};

class Renderer_1c46a0 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void SetMode(int mode);
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual Vertex_1c46a0 *Begin(void *handle, int a, int b, int c, int d);
    virtual void End(Vertex_1c46a0 *v);
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
    virtual void v52(); virtual void v53();
    virtual void SetA(int v);
    virtual void v55(); virtual void v56(); virtual void v57();
    virtual void SetB(int v);
};

class Stage_1c46a0 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12();
    virtual int S13(int v);
    virtual void v14();
    virtual int S15(int v);
    virtual int S16(int v);
};

extern Device_1c46a0 *DAT_0052c2a4;
extern Renderer_1c46a0 *DAT_0052c2a8;
extern Stage_1c46a0 **DAT_0052c2ac;
void __cdecl FUN_000b3c80(int flag);

class Bar {
public:
    int r;
    int g;
    int b;
    char flag0c;
    char pad0d[3];
    Surface_1c46a0 *surface;
    char flag14;
    char pad15[3];
    float alpha;
    char pad1c[8];
    char flag24;
    char pad25[3];
    float fraction;
    char pad2c[8];
    char flag34;

    void FUN_001c46a0();
};

void Bar::FUN_001c46a0()
{
    if (fraction != 0.0f && alpha != 0.0f) {
        float width = (float)DAT_0052c2a4->Width();
        float height = (float)DAT_0052c2a4->Height();
        float frac = fraction;
        float half = height * 0.5f;
        DAT_0052c2a8->SetMode(2);
        DAT_0052c2a8->SetA(0);
        DAT_0052c2a8->SetB(0);
        (*DAT_0052c2ac)->S15(0);
        (*DAT_0052c2ac)->S13(0);

        unsigned int color = (int)(alpha * 255.0f);
        color = (((color << 8) | r) << 8 | g) << 8 | b;

        Vertex_1c46a0 *v = DAT_0052c2a8->Begin(surface->handle, 1, 0x2020, 4, 0);
        float split = frac * half;
        v->color[0] = color;
        v->pos[0] = 0.0f;
        v->pos[1] = split;
        v->pos[2] = 2.0f;
        v->FUN_0008ef00();
        v->color[0] = color;
        v->pos[0] = 0.0f;
        v->pos[1] = 0.0f;
        v->pos[2] = 2.0f;
        v->FUN_0008ef00();
        v->color[0] = color;
        v->pos[0] = width;
        v->pos[1] = split;
        v->pos[2] = 2.0f;
        v->FUN_0008ef00();
        v->color[0] = color;
        v->pos[0] = width;
        v->pos[1] = 0.0f;
        v->pos[2] = 2.0f;
        v->FUN_0008ef00();
        DAT_0052c2a8->End(v);

        Vertex_1c46a0 *w = DAT_0052c2a8->Begin(surface->handle, 1, 0x2020, 4, 0);
        float rest = height - split;
        w->color[0] = color;
        w->pos[0] = 0.0f;
        w->pos[1] = rest;
        w->pos[2] = 2.0f;
        w->FUN_0008ef00();
        w->color[0] = color;
        w->pos[0] = width;
        w->pos[1] = rest;
        w->pos[2] = 2.0f;
        w->FUN_0008ef00();
        w->color[0] = color;
        w->pos[0] = 0.0f;
        w->pos[1] = height;
        w->pos[2] = 2.0f;
        w->FUN_0008ef00();
        w->color[0] = color;
        w->pos[0] = width;
        w->pos[1] = height;
        w->pos[2] = 2.0f;
        w->FUN_0008ef00();
        DAT_0052c2a8->End(w);

        (*DAT_0052c2ac)->S16(0);
        DAT_0052c2a8->SetMode(0);
        DAT_0052c2a8->SetA(1);
        DAT_0052c2a8->SetB(1);
        return;
    }
    if (flag24 || flag14 || !flag34 || !flag0c)
        return;
    FUN_000b3c80(1);
    flag34 = 0;
}
