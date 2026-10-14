// STATUS: equivalent (tools/equiv.py level 3: 73 inputs, branch coverage 19/22, incomplete)
// FUN_001c82c0 @ 0x001c82c0
struct Vec3_1c82c0 {
    float x, y, z;
};

struct Profiler_1c82c0 {
    char FUN_0023f760(const char *name, int id, int flag);
};
extern Profiler_1c82c0 *DAT_004dd6e8;

struct Viewer {
    void FUN_002a05c0(void *p, Vec3_1c82c0 *pos, int zero, float one);
};

struct Slot_1c82c0 {
    int f0;
    float f4;
};

struct Light {
    char pad0[0x14];
    unsigned color;
    char pad18[0x58 - 0x18];
    Slot_1c82c0 slot;
};

struct LightSet_1c82c0 {
    char pad0[0x10];
    int count;
    int numLights;
    Light **lights;
    void FUN_002a1180(int mode);
};

struct Scene_1c82c0 {
    char pad0[0xc0];
    Viewer *viewer;
    char padc4[4];
    LightSet_1c82c0 *set;
};

class Emitter_1c82c0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(int a, int b);
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
    virtual void v20(int a, Slot_1c82c0 *slot);
    virtual void v21();
    virtual void v22();
    virtual void v23(float f);
};

struct View {
    char pad0[0x14];
    Emitter_1c82c0 *emitter;
    char pad18[0x90 - 0x18];
    float scale;
    void FUN_001c4d30(Vec3_1c82c0 *out);
    void FUN_001c4d80();
};

struct Painter {
    void FUN_002a31d0();
    void FUN_002a31a0(unsigned color);
    void FUN_002a3250();
};

struct PainterHost {
    char pad0[8];
    Painter inner;
};

struct Renderer_1c82c0 {
    char pad0[0x760];
    PainterHost *host;
    void FUN_001c82c0(Scene_1c82c0 *scene, View *view, int unused);
};

static float ShadeSlope()
{
    return -3.863987684f;
}

void Renderer_1c82c0::FUN_001c82c0(Scene_1c82c0 *scene, View *view, int unused)
{
    Viewer *viewer = scene->viewer;
    Emitter_1c82c0 *em = view->emitter;
    if (em == 0)
        return;

    Vec3_1c82c0 pos;
    view->FUN_001c4d30(&pos);
    LightSet_1c82c0 *set = scene->set;
    if (DAT_004dd6e8->FUN_0023f760("Compute Lights", 0x6c, 1)) {
        set->FUN_002a1180(2);
        viewer->FUN_002a05c0(set, &pos, 0, 1.0f);
    }
    view->FUN_001c4d80();

    int count = set->numLights;
    if (count > 1)
        count = 1;
    for (int i = 0; i < count; i++) {
        if (i >= set->count)
            continue;
        Light *light = set->lights[i];
        if (light == 0)
            continue;

        Slot_1c82c0 *slot = &light->slot;
        float x = -slot->f4;
        static float slope = ShadeSlope();
        if (x < 0.2588f)
            continue;

        double t = 1.0;
        if (x < 0.0f)
            t = (x - 0.2588f) * slope;
        double tb = t * view->scale;
        double base = (double)((light->color >> 16) & 0xff) * 0.00392157f * 255.0f;
        int c0 = (int)base;
        int c1 = (int)((255 - c0) * tb + c0);
        unsigned color = (((0xffffff00u | c1) << 8) | c1) << 8 | c1;

        host->inner.FUN_002a31d0();
        host->inner.FUN_002a31a0(color);
        em->v20(0, slot);
        em->v23(20.0f);
        em->v8(0, 0);
        host->inner.FUN_002a3250();
    }
}
