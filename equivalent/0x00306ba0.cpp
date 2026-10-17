// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00306ba0 @ 0x00306ba0
namespace physics {
struct Block { void FUN_0030eaa0(); char data[0x40]; };
class CollisionOBB {
public:
    virtual void virtualMethod();
    int field4;
    int field8;
    int fieldC;
    int field10;
    int field14;
    unsigned char field18;
    unsigned char field19;
    char pad1A[2];
    int field1C, field20, field24, field28, field2C, field30;
    float field34;
    char pad38[4];
    Block block3C;
    Block block7C;
    CollisionOBB();
};
CollisionOBB::CollisionOBB() {
    field4 = 0;
    field10 = 0;
    field14 = 0;
    field18 = 1;
    field19 = 0;
    field8 = -1;
    fieldC = -1;
    field1C = 0;
    field20 = 0;
    field24 = 0;
    field28 = 0;
    field2C = 0;
    field30 = 0;
    field34 = 1.0f;
    block3C.FUN_0030eaa0();
    block7C.FUN_0030eaa0();
}
}