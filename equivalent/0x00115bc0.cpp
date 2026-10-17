// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00115bc0 @ 0x00115bc0
namespace hulkfight { namespace ai {
struct MotionTargetTrackBase {
    virtual void FUN_00236d40_virtual();
    char unused[8];
    MotionTargetTrackBase();
};
struct MotionTargetTrack : MotionTargetTrackBase {
    float valueC;
    float value10;
    int value14;
    int value18;
    int value1C;
    float value20;
    float value24;
    virtual void FUN_00115bc0_virtual();
    MotionTargetTrack();
};
MotionTargetTrack::MotionTargetTrack() : MotionTargetTrackBase() {
    valueC = 0.0f;
    value14 = 0;
    value10 = -1.0f;
    value18 = 0;
    value1C = 0;
    value20 = -1.0f;
    value24 = 1.0f;
}
} }