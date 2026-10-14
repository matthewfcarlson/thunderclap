// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// physics::RootMatrixDriver::vfunc_9 @ 0x002fc220
struct Mat4 {
    float m[16];
    void FUN_0022ca90(Mat4* a, Mat4* b);
};

struct Joint {
    Mat4* FUN_0030f100();
};

struct Link {
    Joint* FUN_0030ef30();
    void FUN_0030ee70(Mat4* m);
};

struct Skeleton {
    Link* FUN_0030f490(int index);
};

class RootMatrixDriver {
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
    virtual void vfunc_9(Skeleton* skeleton);
    char pad04[0x18 - 4];
    Mat4* root;     // 0x18
};

struct Frame {
    Mat4 cur;
    Mat4 out;
};

// Multiplies the root joint's matrix by the driver's root matrix and writes it back.
void RootMatrixDriver::vfunc_9(Skeleton* skeleton)
{
    Frame f;
    Link* link = skeleton->FUN_0030f490(0);
    f.cur = *link->FUN_0030ef30()->FUN_0030f100();
    f.out.FUN_0022ca90(&f.cur, root);
    f.cur = f.out;
    link->FUN_0030ee70(&f.cur);
}
