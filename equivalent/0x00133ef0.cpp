// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00133ef0 @ 0x00133ef0
namespace hulkfight { namespace motion {
struct FUN_00236d40 {
    virtual void unused();
    char baseData[8];
    FUN_00236d40();
};
struct FlyingAttackTrack : FUN_00236d40 {
    int field0c;
    float field10;
    int field14;
    int field18;
    float field1c;
    float field20;
    int field24;
    int field28;
    float field2c;
    unsigned char field30;
    char reserved31[3];
    int field34;
    int field38;
    int field3c;
    virtual void unused();
    FlyingAttackTrack();
};
FlyingAttackTrack::FlyingAttackTrack() : FUN_00236d40() {
    field0c = 0;
    field10 = -1.0f;
    field14 = 0;
    field18 = 0;
    field1c = -1.0f;
    field24 = 0;
    field28 = 0;
    field30 = 0;
    field38 = 0;
    field3c = 0;
    field20 = 50.0f;
    field2c = 3.14159274f;
    field34 = -5;
}
}}