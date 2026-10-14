// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_000cf740 @ 0x000cf740
struct Vec3_cf740 {
    float x, y, z;
};

struct Pass_cf740 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(int a);
    virtual void v16(int a);
};

struct PassHolder_cf740 {
    Pass_cf740 *pass;
    void FUN_00293d00(const Vec3_cf740 *color);
    void FUN_00293da0(int a, int b, int c);   // float bits
    void FUN_00293bf0(float a);
};

struct Sprite {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(int a, int b);
};

extern PassHolder_cf740 *DAT_0052c2ac;
extern Vec3_cf740 DAT_004ddec8;
extern int DAT_0049fd0c;   // 0.8f

class Effect_cf740 {
public:
    char pad0[0x218];
    Sprite *sprite;         // 0x218

    void FUN_000ce280();
    void FUN_000cf740();
};

void Effect_cf740::FUN_000cf740()
{
    FUN_000ce280();
    if (sprite != 0) {
        DAT_0052c2ac->pass->v15(0);
        DAT_0052c2ac->FUN_00293d00(&DAT_004ddec8);
        Vec3_cf740 zero;
        zero.x = 0.0f;
        zero.y = 0.0f;
        zero.z = 0.0f;
        DAT_0052c2ac->FUN_00293d00(&zero);
        int k = DAT_0049fd0c;
        DAT_0052c2ac->FUN_00293da0(k, k, k);
        sprite->v8(0, 0);
        DAT_0052c2ac->pass->v16(0);
    }
}
