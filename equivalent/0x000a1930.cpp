// STATUS: equivalent (tools/equiv.py level 3: 72 inputs, branch coverage 8/8)
// FUN_000a1930 @ 0x000a1930
struct V3 {
    float x, y, z;
};

struct Block {
    V3 pos;                 // 0x170
    float f17c;
    float f180;
    float f184;
    float f188;
    float f18c;
    float f190;
    float f194;
    float f198;
    float f19c;
    char pad1a0[0x1c4 - 0x1a0];
    float f1c4;
    float f1c8;
    float f1cc;
    char pad1d0[0x1e8 - 0x1d0];
    float f1e8;
    float f1ec;
    float f1f0;
    char pad1f4[0x20c - 0x1f4];
    float f20c;
    float f210;
    float f214;
    float f218;
    float f21c;
    float f220;
    float f224;
    float f228;
    float f22c;
    float f230;
    char pad234[0x248 - 0x234];
    Block* FUN_000a06d0(const Block* src);
};

struct World;

struct Target {
    void FUN_000fd8a0(World* world, void* mat, int scratch, float f8);
};

struct Inner {
    Target* FUN_000fdc30();
};

struct Holder {
    char pad0[0x1ca0];
    Inner* inner;
};

struct Game {
    char pad0[0x124];
    Holder* holder;
};

struct World {
    char pad0[0x20];
    Game* game;
};

extern World* DAT_004dd700;

void __cdecl FUN_000a04c0(V3* dir, float* p1, float* p0, float* scratch);

class Mover {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(float* scratch, V3* pos);
    virtual void v7();
    virtual float v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void* v14();
    char pad4[0x170 - 4];
    Block b;
    Block f248;
    int mode;
    int prevMode;
    int f328;
    char pad32c[0x394 - 0x32c];
    int f394;
    char pad398[0x3bc - 0x398];
    float f3bc;
    float f3c0;
    float f3c4;
    char pad3c8[0x448 - 0x3c8];
    float f448;
    char pad44c[0x490 - 0x44c];
    char f490;
    char pad491[0x4ac - 0x491];
    int f4ac;
    int f4b0;
    void FUN_000a1930(V3 pos, int newMode);
};

void Mover::FUN_000a1930(V3 pos, int newMode)
{
    int m = mode;
    if (m == 7)
        m = f328;
    prevMode = m;
    mode = newMode;
    f394 = 0;
    b.f18c = pos.y;
    b.f190 = pos.z;
    b.f188 = pos.x;
    b.f17c = pos.x;
    b.f180 = b.f18c;
    b.f184 = b.f190;
    b.pos.x = pos.x;
    b.pos.y = b.f180;
    b.pos.z = b.f184;
    b.f194 = pos.x;
    b.f198 = b.pos.y;
    b.f19c = b.pos.z;
    if (mode == 1) {
        pos.x = b.f194 - b.f1c4;
        pos.y = b.f198 - b.f1c8;
        pos.z = b.f19c - b.f1cc;
        FUN_000a04c0(&pos, &f3bc, &f3c0, &f3c4);
    }
    pos.x = b.f1e8 - b.f194;
    pos.y = b.f1ec - b.f198;
    pos.z = b.f1f0 - b.f19c;
    float* scratch = (float*)&newMode;
    FUN_000a04c0(&pos, &b.f210, &b.f20c, scratch);
    b.f220 = f448;
    b.f21c = f448;
    b.f228 = 0;
    b.f224 = 0;
    b.f218 = 0;
    b.f214 = 0;
    b.f230 = 0;
    b.f22c = 0;
    f248.FUN_000a06d0(&b);
    f490 = 0;
    f4ac = 0;
    f4b0 = 0;
    Holder* holder = DAT_004dd700->game->holder;
    if (holder) {
        Target* t = holder->inner->FUN_000fdc30();
        if (t) {
            v6(scratch, &pos);
            World* world = DAT_004dd700;
            float f8 = v8();
            void* mat = v14();
            t->FUN_000fd8a0(world, mat, newMode, f8);
        }
    }
}
