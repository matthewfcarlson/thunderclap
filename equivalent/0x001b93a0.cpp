// STATUS: equivalent (tools/equiv.py level 3: 3080 inputs, branch coverage 83/96, incomplete)
// FUN_001b93a0 @ 0x001b93a0
struct Vec3 {
    float x, y, z;
};

class Node {
public:
    char FUN_00059a50(Vec3 *out);
};

class Region {
public:
    char FUN_001c8790(Vec3 *pos);
};

class Tracker {
public:
    Vec3 *FUN_001c39d0();
    char pad0[4];
    Region *region;
};

class Display {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3(int v);
    virtual void vf4(float x, float y, float z, float scale, unsigned int color);
    virtual void vf5();
    virtual void vf6();
    virtual void vf7(int v);
    virtual void vf8(float a, unsigned int colorA, float b, float c, unsigned int colorB, float d,
                     float e, float f);
    virtual void vf9();
};

class Renderer {
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
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85(int v);
    virtual char v86();
    virtual void v87();
    virtual void v88();
    virtual Display *v89(int v);
};

class Probe {
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
};

class Settings {
public:
    char FUN_0023f760(const char *name, int a, int b);
    char FUN_0023f770(const char *name, int a);
};

class Input {
public:
    char FUN_00092940(int button);
};

class Pad {
public:
    Input *FUN_00086340();
};

struct Globals {
    char pad0[0x54];
    Pad *pad;
};

class Stats {
public:
    void FUN_0028f9a0();
    void FUN_0028faf0(int v);
};

struct Body {
    char pad0[0x10];
    Node *node;
};

struct Controller {
    char pad0[0x124];
    Body *body;
};

struct Frame {
    int type;
};

class Camera {
public:
    void FUN_001bc720();
};

class Fader {
public:
    void FUN_001bf8b0();
};

struct Scene {
    char pad0[0x20];
    Controller *controller;
    char pad1[0x40 - 0x24];
    Camera *camera;
    char pad2[0x50 - 0x44];
    Fader *fader;
};

class Menu {
public:
    void FUN_000bdd60();
};

class Overlays {
public:
    void FUN_000d6c70();
};

extern char DAT_004dd8e4;
extern float DAT_004dd91c;
extern Probe *DAT_0052c2a4;
extern Renderer *DAT_0052c2a8;
extern Stats *DAT_0052c2b4;
extern Settings *DAT_004dd6e8;
extern Globals *DAT_004dd700;
extern char DAT_004e2240;
extern char DAT_004e2241;
extern float DAT_004e2244;
extern float DAT_004e2248;
extern float DAT_004e224c;
extern char DAT_004e2250;
extern char DAT_004e2251;
extern float DAT_004e2254;
extern float DAT_004e2258;
extern float DAT_004e225c;
extern float DAT_004e2260;
extern char DAT_004e2264;
extern char DAT_004e2265;
extern float DAT_004c3bd8;
extern int DAT_004c3bdc;
extern int DAT_004c3be0;
extern int DAT_004c3be4;
extern char DAT_004c3be8;
extern int DAT_004c3bf0;
extern int DAT_004c3bf4;
extern int DAT_004c3bf8;
extern int DAT_004c3bfc;
extern int DAT_004c3c00;
extern int DAT_004c3c04;
extern float DAT_004c3c08;
extern float DAT_004c3c0c;

Tracker *FUN_001c3d90();
unsigned int FUN_00267f00();

class Frontend {
public:
    void FUN_001b93a0(Frame *frame, Scene *scene, Menu *menu, Overlays *overlays, int a4, int a5);

    char pad0[0x31];
    char skip;
};

void Frontend::FUN_001b93a0(Frame *frame, Scene *scene, Menu *menu, Overlays *overlays, int a4, int a5)
{
    if (skip)
        return;
    unsigned int startTick = 0;
    if (DAT_004dd8e4)
        startTick = FUN_00267f00();
    DAT_0052c2a4->v14();
    if (DAT_004dd6e8->FUN_0023f770("PDDI stats", 0x70)) {
        DAT_0052c2a8->v85(DAT_0052c2a8->v86() == 0);
    }
    DAT_0052c2b4->FUN_0028f9a0();
    if (frame->type == 4 || frame->type == 6) {
        Vec3 pos = *FUN_001c3d90()->FUN_001c39d0();
        if (!FUN_001c3d90()->region->FUN_001c8790(&pos)) {
            Controller *c = scene->controller;
            if (c->body != 0) {
                if (c->body->node->FUN_00059a50(&pos))
                    FUN_001c3d90()->region->FUN_001c8790(&pos);
            }
        }
        scene->camera->FUN_001bc720();
        if (!DAT_004e2240)
            DAT_004e2240 = 1;
        Display *d = DAT_0052c2a8->v89(0x103);
        Input *input = DAT_004dd700->pad->FUN_00086340();
        if (input->FUN_00092940(0xe)) {
            d->vf4(-100.0f, 0.0f, 0.0f, 0.5f, 0xffffd490u);
            d->vf3(1);
        } else if (input->FUN_00092940(0xd)) {
            d->vf4(-100.0f, 0.0f, 0.0f, 0.5f, 0xffffffffu);
            d->vf3(1);
        } else {
            d->vf5();
        }
        if (DAT_004c3be8) {
            if (DAT_004e2250) {
                DAT_004e2244 = 0;
                DAT_004e2248 = 0;
                DAT_004e224c = 0;
                DAT_004c3bd8 = 0.5f;
                DAT_004c3bdc = 0xff;
                DAT_004c3be0 = 0xff;
                DAT_004c3be4 = 0xff;
                DAT_004e2250 = 0;
            }
            d->vf3((unsigned char)DAT_004e2241);
            int b = DAT_004c3be4 < 0 ? 0 : (DAT_004c3be4 > 255 ? 255 : DAT_004c3be4);
            int g = DAT_004c3be0 < 0 ? 0 : (DAT_004c3be0 > 255 ? 255 : DAT_004c3be0);
            int rr = DAT_004c3bdc < 0 ? 0 : (DAT_004c3bdc > 255 ? 255 : DAT_004c3bdc);
            unsigned int color = (((((unsigned int)rr | 0xffffff00u) << 8) | g) << 8) | b;
            d->vf4(DAT_004e2244, DAT_004e2248, DAT_004e224c, DAT_004c3bd8, color);
            d->vf3((unsigned char)DAT_004e2241);
            DAT_004c3be8 = 0;
        }
        d->vf6();
        if (DAT_004e2264) {
            if (DAT_004e2265) {
                DAT_004e2254 = 0;
                DAT_004c3bf0 = 0xff;
                DAT_004c3bf4 = 0xff;
                DAT_004c3bf8 = 0xff;
                DAT_004e2258 = 0;
                DAT_004c3bfc = 0x80;
                DAT_004c3c00 = 0x80;
                DAT_004c3c04 = 0x80;
                DAT_004e225c = 0;
                DAT_004e2260 = 0;
                DAT_004c3c08 = 0.5f;
                DAT_004e2265 = 0;
            }
            int e = DAT_004c3c04 < 0 ? 0 : (DAT_004c3c04 > 255 ? 255 : DAT_004c3c04);
            int f = DAT_004c3c00 < 0 ? 0 : (DAT_004c3c00 > 255 ? 255 : DAT_004c3c00);
            int h = DAT_004c3bfc < 0 ? 0 : (DAT_004c3bfc > 255 ? 255 : DAT_004c3bfc);
            unsigned int colorB = (((((unsigned int)h | 0xffffff00u) << 8) | f) << 8) | e;
            int k = DAT_004c3bf8 < 0 ? 0 : (DAT_004c3bf8 > 255 ? 255 : DAT_004c3bf8);
            int m = DAT_004c3bf4 < 0 ? 0 : (DAT_004c3bf4 > 255 ? 255 : DAT_004c3bf4);
            int n = DAT_004c3bf0 < 0 ? 0 : (DAT_004c3bf0 > 255 ? 255 : DAT_004c3bf0);
            unsigned int colorA = (((((unsigned int)n | 0xffffff00u) << 8) | m) << 8) | k;
            d->vf8(DAT_004e2254, colorA, DAT_004c3c0c, DAT_004e2258, colorB, DAT_004e225c,
                   DAT_004e2260, DAT_004c3c08);
            d->vf7((unsigned char)DAT_004e2251);
            DAT_004e2264 = 0;
        }
        d->vf9();
        scene->fader->FUN_001bf8b0();
    }
    if (frame->type == 4) {
        if (DAT_004dd6e8->FUN_0023f760("Render Overlays", 0x23, 1))
            overlays->FUN_000d6c70();
    }
    if (DAT_004dd6e8->FUN_0023f760("Render Frontend", 0x40, 1))
        menu->FUN_000bdd60();
    if (DAT_004dd8e4) {
        unsigned int now = FUN_00267f00();
        if (DAT_004dd8e4)
            DAT_004dd91c = (float)(now - startTick) * 1e-06f;
    }
    DAT_0052c2b4->FUN_0028faf0(0);
}
