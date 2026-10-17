// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00306b40 @ 0x00306b40
namespace physics {
struct Triple {
    char data[0x2c];
    void FUN_00306e70();
};
class CollisionCylinder {
public:
    virtual void virtual_0();
    unsigned int value04;
    int value08;
    int value0c;
    unsigned int value10;
    unsigned int value14;
    unsigned char enabled;
    unsigned char flag;
    char padding1a[2];
    unsigned int value1c;
    unsigned int value20;
    unsigned int value24;
    unsigned int value28;
    unsigned int value2c;
    unsigned int value30;
    float scale;
    Triple first;
    Triple second;
    CollisionCylinder();
};
CollisionCylinder::CollisionCylinder() {
    value04 = 0;
    value10 = 0;
    value14 = 0;
    enabled = 1;
    flag = 0;
    value08 = -1;
    value0c = -1;
    value1c = 0;
    value20 = 0;
    value24 = 0;
    value28 = 0;
    value2c = 0;
    value30 = 0;
    scale = 1.0f;
    first.FUN_00306e70();
    second.FUN_00306e70();
}
}