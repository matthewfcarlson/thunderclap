// STATUS: equivalent (tools/equiv.py level 3: 2977 inputs, branch coverage 6/6)
// physics::SimStateArticulated::vfunc_7 @ 0x002fd520
struct Joint {
    char pad0[4];
    int f4, f8, fc, f10, f14, f18;
    unsigned char f1c;
    char pad1d[0x64 - 0x1d];
};

struct Chain {
    char pad0[8];
    int FUN_0030f450();
};

namespace physics {
class SimStateArticulated {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    char pad04[0x50 - 4];
    int f50, f54, f58, f5c, f60, f64;
    char pad68[0x80 - 0x68];
    int f80;
    char pad84[4];
    Chain *chain;
    Joint *joints;
};
}

void physics::SimStateArticulated::vfunc_7()
{
    f58 = 0;
    f54 = 0;
    f50 = 0;
    f64 = 0;
    f60 = 0;
    f5c = 0;
    f80 = 0;
    if (chain != 0) {
        for (int i = 0; i < chain->FUN_0030f450(); i++) {
            Joint *j = &joints[i];
            j->f1c = 1;
            j->fc = 0;
            j->f8 = 0;
            j->f4 = 0;
            j->f18 = 0;
            j->f14 = 0;
            j->f10 = 0;
        }
    }
}
