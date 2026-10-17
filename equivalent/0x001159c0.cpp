// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001159c0 @ 0x001159c0
namespace hulkfight { namespace ai {
struct FUN_00236d40 {
    virtual void unused();
    FUN_00236d40();
    char pad[8];
};
struct MotionFacingTrack : FUN_00236d40 {
    float valueC;
    float value10;
    float value14;
    float value18;
    float value1C;
    float value20;
    float value24;
    MotionFacingTrack();
    virtual void unused();
};
MotionFacingTrack::MotionFacingTrack() {
    valueC = 0.0f;
    value14 = 0.0f;
    value10 = -1.0f;
    value18 = 0.0f;
    value1C = 0.0f;
    value20 = -1.0f;
    value24 = 1.0f;
}
} }