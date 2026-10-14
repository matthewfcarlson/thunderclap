// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 6/6)
// FUN_000cab50 @ 0x000cab50
struct Vec3_cab50 {
    float x, y, z;
};

struct Pass_cab50 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(int a);
    virtual void v16(int a);
};

struct PassHolder_cab50 {
    Pass_cab50 *pass;
    void FUN_00293d00(const Vec3_cab50 *color);
    void FUN_00293da0(float a, float b, float c);
    void FUN_00293bf0(float a);
};

struct Sprite {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(int a, int b);
};

extern PassHolder_cab50 *DAT_0052c2ac;
extern Vec3_cab50 DAT_004ddebc;
extern Vec3_cab50 DAT_004ddf18;

class Effect_cab50 {
public:
    char pad0[0x28];
    Sprite *sprites[5][2];   // 0x28, stride 8

    void FUN_000cab50();
};

void Effect_cab50::FUN_000cab50()
{
    DAT_0052c2ac->pass->v15(0);
    DAT_0052c2ac->FUN_00293d00(&DAT_004ddebc);
    for (int i = 0; i < 5; i++) {
        if (i != 0)
            DAT_0052c2ac->FUN_00293d00(&DAT_004ddf18);
        DAT_0052c2ac->pass->v15(0);
        DAT_0052c2ac->FUN_00293bf0(-1.57079637f);
        if (sprites[i][0] != 0)
            sprites[i][0]->v8(0, 0);
        DAT_0052c2ac->pass->v16(0);
    }
    DAT_0052c2ac->pass->v16(0);
}
