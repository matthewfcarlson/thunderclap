struct FUN_00236d40 {
    FUN_00236d40();
    virtual void virtual0();
    int field4;
};
struct CMoveTrack : FUN_00236d40 {
    virtual void virtual0();
    CMoveTrack();
    int field8;
    int fieldC;
    float field10;
    float field14;
    int field18;
    int field1C;
    int field20;
    int field24;
};
CMoveTrack::CMoveTrack()
    : FUN_00236d40(), fieldC(0), field10(1.0f), field14(1.0f), field18(0), field1C(-1), field20(0),
      field24(0) {
    field8 = 1;
}