// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00225e00 @ 0x00225e00
struct V3_225e00 {
    float x, y, z;
};

struct Node {
    char pad0[0x10];
    float f10;              // 0x10
};

class AnimationDriver {
public:
    char pad00[0x20];
    Node *node;             // 0x20
    char pad24[0x200];
    char b224;              // 0x224
    char pad225[3];
    float f228;             // 0x228
    void FUN_002250e0(float v);
    void FUN_00225140(float v);
    float FUN_00225ab0();
    void FUN_00225e00(float t, V3_225e00 v);
};

void AnimationDriver::FUN_00225e00(float t, V3_225e00 v)
{
    FUN_002250e0(v.y);
    if (v.z < 0.0f)
        FUN_00225140(node->f10 - 1.0f);
    else
        FUN_00225140(v.z);
    if (t > 0.0f && !b224) {
        f228 = 1.0f;
        f228 = FUN_00225ab0() / t;
    } else {
        f228 = v.x;
    }
}
