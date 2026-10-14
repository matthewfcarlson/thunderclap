// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002bc660 @ 0x002bc660
// pure3d::BillboardCutOffQuadGroup::BillboardCutOffQuadGroup @ 0x002bc660
struct Matrix {
    float m[16];
    void FUN_0022b980();
};

namespace pure3d {

class __declspec(novtable) QuadGroupBase {
public:
    virtual void v0();
    char pad04[0x3c];
    void FUN_002a5060();
    QuadGroupBase() { FUN_002a5060(); }
};

class BillboardQuadGroup : public QuadGroupBase {
public:
    Matrix transform;
    float scale;
    int f84;
    unsigned char f88;
    unsigned char f89;
    unsigned char f8a;
    char pad8b;
    int f8c;
    int f90;
    char pad94[4];
    BillboardQuadGroup() {
        scale = 1.0f;
        f84 = 0;
        f88 = 1;
        f89 = 0;
        f8a = 0;
        f8c = 0;
        f90 = 0;
        transform.FUN_0022b980();
    }
    virtual void v1();
};

class BillboardCutOffQuadGroup : public BillboardQuadGroup {
public:
    int f98, f9c, fa0, fa4, fa8, fac, fb0, fb4, fb8, fbc, fc0, fc4, fc8;
    BillboardCutOffQuadGroup();
    virtual void v1();
};

BillboardCutOffQuadGroup::BillboardCutOffQuadGroup()
{
    f98 = 0;
    f9c = 0;
    fa0 = 0;
    fa4 = 0;
    fa8 = 0;
    fac = 0;
    fb0 = 0;
    fb4 = 0;
    fb8 = 0;
    fbc = 0;
    fc0 = 0;
    fc4 = 0;
    fc8 = 0;
}

}
