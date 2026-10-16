// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001709a0 @ 0x001709a0
namespace hulkfight { namespace motion {
struct FUN_00236d40 {
    virtual void Update();
    char unknown[8];
    FUN_00236d40();
};
struct SurfTrack : FUN_00236d40 {
    int field0c;
    float field10, field14, field18, field1c, field20;
    int field24, field28;
    float field2c, field30, field34, field38;
    int field3c, field40, field44;
    virtual void Update();
    SurfTrack();
};
SurfTrack::SurfTrack() {
    field0c = field24 = field28 = field40 = field44 = 0;
    field10 = -1.0f;
    field14 = 20.0f;
    field18 = 21.0f;
    field1c = 10.0f;
    field20 = 50.0f;
    field2c = 0.7853982f;
    field30 = 6.2831855f;
    field34 = field38 = 0.7853982f;
    field3c = -5;
}
} }