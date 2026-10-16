// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 16/16)
// CCameraDramaticAction::vfunc_6 @ 0x00016db0
#include "decls/address.h"
struct Vec3_16db0 {
    float x, y, z;
};

struct Id_16db0 {
    int lo, hi;
};

struct Mat_16db0 {
    float m[16];
};

struct Scene_16db0 {
    void FUN_00035160(Mat_16db0* out);
};

struct Handle_16db0 {
    char pad[4];
};

struct Config_16db0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual float v7();
    char pad04[0x10];
    Vec3_16db0 offset;
    Id_16db0 ids[8];
    int values[8];
    int count;
    char flag;
    char pad85[3];
    int params[6];
};

struct Sub_16db0 {
    void FUN_0009d100(Id_16db0* id, float scale, int value);
    void FUN_00098f50(int a, int b, int c, int d, int e, int f);
    void FUN_0009bd80(struct World* mgr, Mat_16db0* mat, Vec3_16db0 offset, int count);
};

struct World {
    char pad0[8];
    Sub_16db0* sub;
};


Handle_16db0* __fastcall FUN_000592a0(void* owner);
Scene_16db0* __fastcall FUN_00059a30(Handle_16db0* h);

class CCameraDramaticAction {
public:
    char pad0[0x1c];
    void* owner;
    Config_16db0* cfg;
    int field24;
    char vfunc_6(int arg);
};

char CCameraDramaticAction::vfunc_6(int arg)
{
    Mat_16db0 mat;

    FUN_00059a30(FUN_000592a0(owner))->FUN_00035160(&mat);

    for (int i = 0; i < 8; i++) {
        Config_16db0* c = cfg;
        if ((c->ids[i].lo | c->ids[i].hi) != 0) {
            Sub_16db0* sub = DAT_004dd700->sub;
            int value = c->values[i];
            float scale = c->v7();
            sub->FUN_0009d100(&c->ids[i], scale, value);
        }
    }

    Config_16db0* c = cfg;
    DAT_004dd700->sub->FUN_00098f50(c->params[0], c->params[1], c->params[2], c->params[3], c->params[4], c->params[5]);
    c = cfg;
    DAT_004dd700->sub->FUN_0009bd80(DAT_004dd700, &mat, c->offset, c->count);
    Config_16db0* c2 = cfg;
    field24 = arg;
    return c2->flag;
}
