// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00170400 @ 0x00170400
namespace hulkfight { namespace motion {
struct FUN_00236d40 {
    virtual void tick();
    FUN_00236d40();
    char padding[4];
    int active;
    int value;
    float factor;
    bool enabled;
    char pad15[3];
    int position;
    int velocity;
    int acceleration;
    bool flag;
    bool flag2;
    char pad26[2];
    int target;
};
struct DriftToPositionTrack : FUN_00236d40 {
    virtual void tick();
    DriftToPositionTrack();
};
DriftToPositionTrack::DriftToPositionTrack() {
    value = 0;
    enabled = false;
    factor = -1.0f;
    position = 0;
    velocity = 0;
    acceleration = 0;
    flag2 = false;
    target = 0;
    flag = true;
    active = 1;
}
} }
