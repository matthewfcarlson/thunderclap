// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00133ac0 @ 0x00133ac0
struct FUN_00236d40 {
    virtual void slot0();
    char pad[8];
    FUN_00236d40();
};
struct FlyingBrakeTrack : FUN_00236d40 {
    int value0c;
    float min0;
    float max0;
    float ten;
    float max1;
    float min1;
    int index;
    int flag28;
    int flag2c;
    FlyingBrakeTrack();
    virtual void slot0();
};
FlyingBrakeTrack::FlyingBrakeTrack() {
    value0c = 0;
    flag28 = 0;
    flag2c = 0;
    min0 = -1.0f;
    max0 = 50.0f;
    ten = 10.0f;
    max1 = 50.0f;
    min1 = -1.0f;
    index = -5;
}