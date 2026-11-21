// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00085d90..0x00088e60 (kind game, layer game, confidence high), dominant class CTimeManager
// (tree_prelude.h: not needed)


// 0x00086980 FUN_00086980 (132 B): equivalent/0x00086980.cpp [isolated: conflict: FUN_001d4c90; on include/gen/ and not mergeable]
// sym: ?FUN_00086980@App@@QAEXH@Z @65b3fcfddeaf @w7c53acef5b2c @vf89aa8a8a783
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 4/4)
// FUN_00086980 @ 0x00086980
#include "gen/global.h"
struct App;

struct Camera { void FUN_000afe80(); };
struct SubBounds {
    int FUN_00088fa0();
    int FUN_00088fb0();
};
struct Region_86980 {
    char pad[0x80];
    SubBounds bounds;
};
struct Viewport_86980 { void FUN_00090db0(int a, int b); };
struct Streamer { void FUN_001eb4f0(int v); };
struct Audio_86980 { void FUN_000bc4d0(); };
struct State_86980 {
    char pad[8];
    char dirty;
};
struct Manager_86980 {
    void FUN_00088b80(App *app);
    void* vftable;              // (gfx3) the World's vftable word (HulkWorld)
    State_86980 *state;
};
struct Cleaner {  };
struct Registry_86980 { void FUN_001d2760(); };
Registry_86980 *FUN_001d4c90();

// (gfx3) CGame (decls/managers.h's HulkGame) by its pointer words: its 32-bit pads put every manager at the wrong
// word natively (the stats update 0x00090db0 ran on HulkGame+0x24's manager)
struct App {
    void FUN_00086980(int unused);
    void* vftable;              // 0x0
    void* triple;               // 0x4
    void* time;                 // 0x8
    Manager_86980 *manager;           // 0xc the World
    void* controllers;          // 0x10
    void* gameControllers;      // 0x14
    Camera *camera;             // 0x18
    void* platform;             // 0x1c
    Audio_86980 *audio;               // 0x20
    void* render;               // 0x24
    Cleaner *cleaner;           // 0x28
    void* overlay;              // 0x2c
    Streamer *streamer;         // 0x30
    void* fmv;                  // 0x34
    Region_86980 *region;             // 0x38
    void* unlockables;          // 0x3c
    void* pair;                 // 0x40
    void* f44;                  // 0x44
    Viewport_86980 *viewport;         // 0x48 CStatsManager
    void* subtitle;             // 0x4c
    char active;
};

void App::FUN_00086980(int unused)
{
    if (!active)
        return;

    camera->FUN_000afe80();
    Region_86980 *r = region;
    int w = r->bounds.FUN_00088fa0();
    Viewport_86980 *vp = viewport;
    vp->FUN_00090db0(w, r->bounds.FUN_00088fb0());
    streamer->FUN_001eb4f0(1);
    audio->FUN_000bc4d0();
    manager->state->dirty = 1;
    manager->FUN_00088b80(this);
    Registry_86980 *reg = FUN_001d4c90();
    if (reg)
        reg->FUN_001d2760();
    ((::CWorldStreamManager *)cleaner)->FUN_00208820();
    active = 0;
}

