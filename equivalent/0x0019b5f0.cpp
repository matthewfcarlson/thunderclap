// STATUS: equivalent (tools/equiv.py level 3: 86 inputs, branch coverage 18/18)
// hulkfight::motion::FireBeamAction::vfunc_5 @ 0x0019b5f0
struct Vec3 {
    float x, y, z;
    float FUN_0022d110();
};

struct Mat {
    float m[16];
    void FUN_0022c2b0(const Vec3* in, Vec3* out);
    void FUN_0022c3b0(const Vec3* in, Vec3* out);
    void FUN_0022ca90(Mat* a, Mat* b);
};

struct RefObj {
    virtual void AddRef();
    virtual void Release();
};

struct Beam : RefObj {
    char pad04[0x3c];
    Vec3 pos;
};

struct Fighter {
    char pad0[0x328];
    Beam* beam;
    Beam* FUN_00039c60(Vec3* origin, Vec3* dir, int a, int b, int c, int d, int e);
};

struct Skeleton {
    char pad0[0x1c];
    Mat* mats;
};

struct MatSource {
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
    virtual Mat* vfunc_15();
};

struct Config {
    char pad0[8];
    int f8;
    char pad0c[0x38 - 0xc];
    Vec3 v38;
    Vec3 v44;
    float f50;
    int f54;
    int f58;
    char pad5c[4];
    char f60;
};

struct Owner {
    char pad0[8];
    int f8;
};

struct BeamState {
    char pad0[0x10];
    int f10;
    Beam* ref;
    Vec3 origin;
    Vec3 dir;
    float f30;
    void FUN_00197ff0(float dt);
};

void* __fastcall FUN_000592a0(Owner* owner);
Fighter* __fastcall FUN_00059a30(void* x);
char __cdecl FUN_00096b50(Beam* e, Vec3* io, int* out);

class FireBeamAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual bool vfunc_5(int phase, float dt);
    char pad04[0x18];
    Config* cfg;
    Owner* owner;
    char pad24[0x30 - 0x24];
    float time;
    MatSource* source;
    Skeleton* skeleton;
    int jointIndex;
    char pad40[0x60 - 0x40];
    Beam* beam;
    char pad64[4];
    BeamState* state;
    void FUN_00197610(float dt);
};

bool FireBeamAction::vfunc_5(int phase, float dt)
{
    if (phase == 1) {
        Fighter* fighter = FUN_00059a30(FUN_000592a0(owner));
        FUN_00197610(dt);
        time = dt + time;
        state->f10 = owner->f8;

        Vec3 origin;
        Vec3 dir;
        origin.x = 0.0f;
        origin.y = 0.0f;
        origin.z = 0.0f;
        dir.x = 0.0f;
        dir.y = 0.0f;
        dir.z = -1.0f;
        if (skeleton != 0) {
            Mat m;
            Mat* src = &skeleton->mats[jointIndex];
            if (source != 0) {
                Mat* other = source->vfunc_15();
                m.FUN_0022ca90(src, other);
            } else {
                m = *src;
            }
            Vec3 local = cfg->v38;
            m.FUN_0022c2b0(&local, &origin);
            local = cfg->v44;
            m.FUN_0022c3b0(&local, &dir);
            dir.FUN_0022d110();
        }

        Beam* b = beam;
        if (b == 0) {
            b = fighter->beam;
            if (b == 0) {
                // the original spills the creation arguments into its argument slot, which the
                // trace helper below later receives as an output cell
                int a58 = cfg->f58;
                phase = a58;
                int a54 = cfg->f54;
                b = fighter->FUN_00039c60(&origin, &dir, a54, a58, 0, 0, 0);
            }
        }
        Beam** slot = &state->ref;
        if (b)
            b->AddRef();
        if (*slot)
            (*slot)->Release();
        *slot = b;

        if (b != 0 && cfg->f60) {
            Vec3 hit = b->pos;
            FUN_00096b50(b, &hit, &phase);
            dir.x = hit.x - origin.x;
            dir.y = hit.y - origin.y;
            dir.z = hit.z - origin.z;
            dir.FUN_0022d110();
        }

        state->dir = dir;
        state->origin = origin;
        state->f30 = cfg->f50;
        state->FUN_00197ff0(dt);
    }
    return true;
}
