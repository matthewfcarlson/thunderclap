// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00170f90 @ 0x00170f90
namespace hulkfight { namespace motion {
struct Base {
    virtual void virtualMethod();
    char pad04[4];
    int field08;
    int field0c;
    float field10;
    char pad14[4];
    Base();
};
struct PivotPart {
    void FUN_0027af00();
};
struct FootPivotTrack : Base {
    PivotPart pivot;
    char pad19[7];
    int field20, field24, field28, field2c;
    float field30;
    char field34;
    char pad35[3];
    int field38;
    float field3c, field40;
    virtual void virtualMethod();
    FootPivotTrack();
};
FootPivotTrack::FootPivotTrack() : Base() {
    field0c = 0;
    field10 = -1.0f;
    pivot.FUN_0027af00();
    field20 = 0;
    field24 = 0;
    field28 = 0;
    field3c = .1f;
    field40 = .1f;
    field2c = 0;
    field34 = 0;
    field30 = 3.1415927f;
    field38 = -5;
    field08 = 1;
}
}}