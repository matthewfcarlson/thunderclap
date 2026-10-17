// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0011c220 @ 0x0011c220
namespace hulkfight { namespace ai {
struct FUN_00234590 {
    FUN_00234590(int);
    virtual void virtualMethod();
    char padding[8];
};
struct PathLocatorTestCondition : FUN_00234590 {
    int first;
    int second;
    int third;
    unsigned char flags[8];
    float radius;
    float height;
    float distance;
    PathLocatorTestCondition();
};
PathLocatorTestCondition::PathLocatorTestCondition() : FUN_00234590(0) {
    first = 0;
    second = 0;
    third = 0;
    for (int i = 0; i < 8; ++i) flags[i] = 0;
    radius = 50.0f;
    height = 4.0f;
    distance = 50.0f;
}
} }