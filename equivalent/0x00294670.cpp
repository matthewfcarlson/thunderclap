// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_00294670 @ 0x00294670
struct Vec3_294670 { float x, y, z; };
struct Matrix { float m[16]; };

struct Vec3Ops_294670 : Vec3_294670 {
    void FUN_0022d240(const Vec3_294670* in, const Matrix* matrix);
};

struct Camera {
    Matrix* FUN_0028faa0();
};

class Target_294670 {
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
    virtual Matrix* v13();
};

extern Camera** DAT_0052c2b0;

struct View {
    char pad00[0x18];
    Target_294670* target;      // 0x18
    void FUN_002940f0(const Vec3_294670* a, const Vec3_294670* b);
    void FUN_002941b0(const Vec3_294670* a, float* out);
    void Project(Vec3_294670 pos, float* out);
};

void View::Project(Vec3_294670 pos, float* out)
{
    if (target == 0)
        return;
    Vec3Ops_294670 local;
    local.FUN_0022d240(&pos, (*DAT_0052c2b0)->FUN_0028faa0());
    if (target != 0)
        local.FUN_0022d240(&local, target->v13());
    FUN_002940f0(&local, &local);
    FUN_002941b0(&local, out);
}
