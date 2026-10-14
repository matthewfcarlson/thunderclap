// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_002f5480 @ 0x002f5480
struct Part30_2f5480 { char data[0xac]; void FUN_0027af00(); };
struct Part1c { char data[0x1c]; void FUN_002fca90(); };
struct Part168 { char data[0x6c]; void FUN_00308cc0(); };
extern unsigned int DAT_004d2b74;
extern float DAT_004d2b7c, DAT_004d2b80;
struct FUN_002fe640 {
 virtual void slot0();
 char pad04[0x20];
 unsigned int field24;
 char pad28[8];
 FUN_002fe640();
};
namespace physics {
struct PhysicsObject : FUN_002fe640 {
 virtual void slot0();
 Part30_2f5480 part30;
 Part1c partdc, partf8, part114;
 char pad130[0x38];
 Part168 part168;
 unsigned int field1d4;
 float field1d8;
 unsigned int field1dc;
 float field1e0, field1e4, field1e8;
 unsigned int field1ec, field1f0;
 unsigned char field1f4;
 PhysicsObject();
};
PhysicsObject::PhysicsObject() {
 part30.FUN_0027af00();
 partdc.FUN_002fca90();
 partf8.FUN_002fca90();
 part114.FUN_002fca90();
 part168.FUN_00308cc0();
 field1d4=0;
 field1d8=1.0f / (double)DAT_004d2b74;
 field1dc=0;
 field1e0=1.0f / (double)DAT_004d2b74;
 field1e4=DAT_004d2b80;
 field1e8=DAT_004d2b7c;
 field1f0 &= 0xffffff00;
 field1ec=0;
 field24=0;
 field1f0 |= 0xff00;
 field1f4 |= 3;
}
}
