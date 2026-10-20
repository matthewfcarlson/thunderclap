namespace hulkfight {
namespace motion {
struct FUN_00236d40 {
    FUN_00236d40();
    virtual void unknown();
};
struct SlowMotionTrack : FUN_00236d40 {
    int field04;
    int field08;
    int field0c;
    float field10;
    float field14;
    float field18;
    float field1c;
    unsigned char field20;
    SlowMotionTrack();
};
SlowMotionTrack::SlowMotionTrack() {
    field0c = 0;
    field18 = 1.0f;
    field1c = 1.0f;
    field10 = 0.1f;
    field14 = 0.9f;
    field20 = 0;
    field08 = 1;
}
} // namespace motion
} // namespace hulkfight