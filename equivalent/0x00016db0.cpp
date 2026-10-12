// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 16/16)
// CCameraDramaticAction::vfunc_6 @ 0x00016db0
struct Vec3 {
    float x, y, z;
};

struct Id {
    int lo, hi;
};

struct Mat {
    float m[16];
};

struct Scene {
    void FUN_00035160(Mat* out);
};

struct Handle {
    char pad[4];
};

struct Config {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual float v7();
    char pad04[0x10];
    Vec3 offset;
    Id ids[8];
    int values[8];
    int count;
    char flag;
    char pad85[3];
    int params[6];
};

struct Sub {
    void FUN_0009d100(Id* id, float scale, int value);
    void FUN_00098f50(int a, int b, int c, int d, int e, int f);
    void FUN_0009bd80(struct Manager* mgr, Mat* mat, Vec3 offset, int count);
};

struct Manager {
    char pad0[8];
    Sub* sub;
};

extern Manager* DAT_004dd700;

Handle* __fastcall FUN_000592a0(void* owner);
Scene* __fastcall FUN_00059a30(Handle* h);

class CCameraDramaticAction {
public:
    char pad0[0x1c];
    void* owner;
    Config* cfg;
    int field24;
    char vfunc_6(int arg);
};

char CCameraDramaticAction::vfunc_6(int arg)
{
    Mat mat;

    FUN_00059a30(FUN_000592a0(owner))->FUN_00035160(&mat);

    for (int i = 0; i < 8; i++) {
        Config* c = cfg;
        if ((c->ids[i].lo | c->ids[i].hi) != 0) {
            Sub* sub = DAT_004dd700->sub;
            int value = c->values[i];
            float scale = c->v7();
            sub->FUN_0009d100(&c->ids[i], scale, value);
        }
    }

    Config* c = cfg;
    DAT_004dd700->sub->FUN_00098f50(c->params[0], c->params[1], c->params[2], c->params[3], c->params[4], c->params[5]);
    c = cfg;
    DAT_004dd700->sub->FUN_0009bd80(DAT_004dd700, &mat, c->offset, c->count);
    Config* c2 = cfg;
    field24 = arg;
    return c2->flag;
}
