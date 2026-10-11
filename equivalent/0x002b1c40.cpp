// STATUS: equivalent (tools/equiv.py level 3: 160 inputs, branch coverage 29/30, incomplete)
// pure3d::MultiController::vfunc_20 @ 0x002b1c40
struct Controller {
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
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual int v19();
};

struct MultiController {
    char pad0[0x18];
    float scale;
    char pad1[0x4];
    float t_d;
    float t_a;
    float t_b;
    char pad1b[0x8];
    unsigned count;
    int mode;
    char pad2[0x4];
    unsigned numChildren;
    Controller **children;

    virtual float vfunc_20();
};

float MultiController::vfunc_20()
{
    float a = t_a * scale;
    float dur = t_b * scale - a;

    switch (mode) {
    case 0: {
        for (unsigned i = 0; i < numChildren; i++) {
            if (!children[i]->v19())
                return 3.4028235e+38f;
        }
        return dur;
    }
    case 2:
        if (count == 0)
            return 3.4028235e+38f;
        return (float)count * dur - (t_d - a);
    case 3:
        if (count == 0)
            return 3.4028235e+38f;
        return (float)count * dur - (t_b * scale - t_d);
    case 4:
        if (count == 0)
            return 3.4028235e+38f;
        {
            float v = (float)count * dur;
            return (v + v) - (t_d - a);
        }
    case 5:
        if (count == 0)
            return 3.4028235e+38f;
        {
            float v = (float)count * dur;
            return (v + v) - (t_b * scale - t_d);
        }
    default:
        return 0.0f;
    }
}
