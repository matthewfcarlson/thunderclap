// STATUS: equivalent (tools/equiv.py level 3: 3025 inputs, branch coverage 28/28)
// FUN_001c3e10 @ 0x001c3e10
#include "decls/data/game/Render/Canvas.h"
#include "decls/data/game/global.h"

struct Console_1c3e10 {
    void FUN_0023f730(const char *section);
    void FUN_0023f740();
    char FUN_0023f770(const char *label, int key);
    void FUN_0023f8f0();
};

struct Target_1c3e10 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void SetColor(unsigned int color, int flag);
};

struct DebugView {
    int FUN_001b4420(int id);
};

struct Hub_1c3e10 {
    char pad0[8];
    struct Sink_1c3e10 *sink;
    char pad0c[4];
    DebugView *debug;
};

struct Sink_1c3e10 {
    void FUN_00099310();
};

struct Level_1c3e10 {
    char pad0[0x59c];
    int id;
};

struct World {
    Level_1c3e10 *FUN_000862a0();
    int *FUN_00086270();
};

struct Gpu {
    void FUN_0027ff40(int a, int b);
};

struct Part_1c3e10 {
    void FUN_001c46a0();
};

struct Frame_1c3e10 {
    char pad0[0x10];
    struct Target_1c3e10 *target;
};

struct Viewport;

struct Renderer_1c3e10 {
    char pad0[0xbc];
    int fBc;
    int fC0;
    void FUN_001c1f30(void *a, int b, int c, int d, int e);
    void FUN_001c2210();
    void FUN_001c13c0();
    void FUN_001c1330(int v);
    void FUN_001c2650(void *a, int b, int c);
    void FUN_001c1340();
    void FUN_001c13d0();
    void FUN_001c1400();
    void FUN_001c1410();
    void FUN_001c22f0();
};

struct Linker {
    void FUN_001c88f0(Renderer_1c3e10 *r);
};

struct Child_1c3e10 {
    virtual void v0();
};

extern World *DAT_004dd6ec;
extern Hub_1c3e10 *DAT_004dd700;

Gpu *__cdecl FUN_0027f250();
void __cdecl FUN_002fa5b0(int v);

class DebugRender {
public:
    Renderer_1c3e10 *renderer;
    Linker *linker;
    char pad08[8];
    Child_1c3e10 *child;
    Part_1c3e10 *partA;
    Part_1c3e10 *partB;
    char area[0x40];
    int f5c;
    int f60;
    int f64;
    int f68;
    char ready;
    char pad6d[2];
    char noOverlay;
    char pad70[8];
    void *extra;

    void FUN_001c3e10();
};

void DebugRender::FUN_001c3e10()
{
    (*(Console_1c3e10**)&DAT_004dd6e8)->FUN_0023f730("Rendering");
    if (!ready) {
        renderer->FUN_001c1f30(area, f5c, f60, f64, f68);
        ready = 1;
    }
    renderer->FUN_001c2210();
    renderer->FUN_001c13c0();
    linker->FUN_001c88f0(renderer);
    if (extra != 0) {
        renderer->FUN_001c1330(renderer->fC0);
        renderer->FUN_001c2650(extra, 0, 0);
    }
    if (!noOverlay)
        renderer->FUN_001c1340();
    if (*DAT_004dd6ec->FUN_00086270() != 6) {
        int v = renderer->fBc;
        Gpu *gpu = FUN_0027f250();
        gpu->FUN_0027ff40(v, 0);
    }
    renderer->FUN_001c1340();
    DAT_004dd700->sink->FUN_00099310();
    renderer->FUN_001c13d0();
    renderer->FUN_001c1400();
    partB->FUN_001c46a0();
    partA->FUN_001c46a0();
    (*(Console_1c3e10**)&DAT_004dd6e8)->FUN_0023f740();
    if ((*(Console_1c3e10**)&DAT_004dd6e8)->FUN_0023f770("Toggle Collision Volumes", 0x76))
        (*(char*)&DAT_004e2321) = !(*(char*)&DAT_004e2321);
    if ((*(Console_1c3e10**)&DAT_004dd6e8)->FUN_0023f770("Toggle Collision Meshes", 0x6d))
        DAT_004e2320 = !DAT_004e2320;
    if ((*(char*)&DAT_004e2321))
        FUN_002fa5b0((*(int*)&DAT_00554c14));
    if (DAT_004e2320 && DAT_004dd6ec) {
        Level_1c3e10 *level = DAT_004dd6ec->FUN_000862a0();
        if (level) {
            int id = level->id;
            Frame_1c3e10 *f = (Frame_1c3e10 *)DAT_004dd700->debug->FUN_001b4420(id);
            if (f)
                f->target->SetColor(0xff000000, 0);
        }
    }
    (*(Console_1c3e10**)&DAT_004dd6e8)->FUN_0023f8f0();
    renderer->FUN_001c1410();
    renderer->FUN_001c22f0();
    if (child)
        child->v0();
}
