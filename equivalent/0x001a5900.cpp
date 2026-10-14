// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// hulkfight::scenario::EffectAction::vfunc_5 @ 0x001a5900
struct Mat_1a5900 {
    float m[16];
};

struct Xform_1a5900 {
    char data[0x10];
};

struct Holder;

class Anim_1a5900 {
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
    virtual void *v11();
};

struct Owner_1a5900 {
    Anim_1a5900 *FUN_002960d0();
};

struct Config_1a5900 {
    char pad0[0x50];
    int mode;               // 0x50
    char pad54[4];
    int arg58;              // 0x58
    int arg5c;              // 0x5c
};

struct Target_1a5900 {
    void FUN_0027ffc0(int handle, Mat_1a5900 *m);
};

struct MatOut {
    Mat_1a5900 data;
    void FUN_0022ca90(Xform_1a5900 *x, Mat_1a5900 *src);
};

Target_1a5900 *FUN_0027f250();

namespace hulkfight {
namespace scenario {
class EffectAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual bool vfunc_5(int a, int b);
    char pad04[0x1c - 4];
    Config_1a5900 *config;         // 0x1c
    char pad20[4];
    int handle;             // 0x24
    Owner_1a5900 *owner;           // 0x28
    Xform_1a5900 xform;            // 0x2c
    void FUN_001a5840(void *pos, int a, int b, Mat_1a5900 *out);
};
}
}

bool hulkfight::scenario::EffectAction::vfunc_5(int a, int b)
{
    if (owner == 0)
        return true;
    Target_1a5900 *target = FUN_0027f250();
    void *pos = owner->FUN_002960d0()->v11();
    struct Frame {
        MatOut first;
        MatOut second;
    } fr;
    switch (config->mode) {
    case 1:
        FUN_001a5840(pos, 0, 0, &fr.second.data);
        fr.first.FUN_0022ca90(&xform, &fr.second.data);
        target->FUN_0027ffc0(handle, &fr.first.data);
        break;
    case 2:
        FUN_001a5840(pos, config->arg58, config->arg5c, &fr.first.data);
        fr.second.FUN_0022ca90(&xform, &fr.first.data);
        target->FUN_0027ffc0(handle, &fr.second.data);
        break;
    }
    return true;
}
