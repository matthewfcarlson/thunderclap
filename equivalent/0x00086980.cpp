// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 4/4)
// FUN_00086980 @ 0x00086980
struct App;

struct Camera { void FUN_000afe80(); };
struct SubBounds {
    int FUN_00088fa0();
    int FUN_00088fb0();
};
struct Region {
    char pad[0x80];
    SubBounds bounds;
};
struct Viewport { void FUN_00090db0(int a, int b); };
struct Streamer { void FUN_001eb4f0(int v); };
struct Audio { void FUN_000bc4d0(); };
struct State {
    char pad[8];
    char dirty;
};
struct Manager {
    void FUN_00088b80(App *app);
    int pad0;
    State *state;
};
struct Cleaner { void FUN_00208820(); };
struct Registry { void FUN_001d2760(); };
Registry *FUN_001d4c90();

struct App {
    void FUN_00086980(int unused);
    char pad0[0xc];
    Manager *manager;           // 0xc
    char pad1[0x18 - 0x10];
    Camera *camera;             // 0x18
    char pad2[0x20 - 0x1c];
    Audio *audio;               // 0x20
    char pad3[0x28 - 0x24];
    Cleaner *cleaner;           // 0x28
    char pad4[0x30 - 0x2c];
    Streamer *streamer;         // 0x30
    char pad5[0x38 - 0x34];
    Region *region;             // 0x38
    char pad6[0x48 - 0x3c];
    Viewport *viewport;         // 0x48
    char pad7[0x50 - 0x4c];
    char active;
};

void App::FUN_00086980(int unused)
{
    if (!active)
        return;

    camera->FUN_000afe80();
    Region *r = region;
    int w = r->bounds.FUN_00088fa0();
    Viewport *vp = viewport;
    vp->FUN_00090db0(w, r->bounds.FUN_00088fb0());
    streamer->FUN_001eb4f0(1);
    audio->FUN_000bc4d0();
    manager->state->dirty = 1;
    manager->FUN_00088b80(this);
    Registry *reg = FUN_001d4c90();
    if (reg)
        reg->FUN_001d2760();
    cleaner->FUN_00208820();
    active = 0;
}
