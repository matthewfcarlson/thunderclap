// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001243a0 @ 0x001243a0
struct FUN_00236d40 {
    virtual void slot0();
    char data[8];
    FUN_00236d40();
};
namespace hulkfight { namespace ai {
struct AcquireTargetTrack : FUN_00236d40 {
    int state;
    float minimum;
    float angle;
    float distance;
    bool enabled;
    char pad[3];
    int value20;
    int value24;
    float value28;
    AcquireTargetTrack();
};
} }
hulkfight::ai::AcquireTargetTrack::AcquireTargetTrack() : FUN_00236d40() {
    state = 0;
    enabled = false;
    minimum = -1.0f;
    angle = 6.2831855f;
    distance = 100.0f;
    value20 = 0;
    value24 = 0;
    value28 = -1.0f;
    *(int*)(data + 4) = 1;
}
