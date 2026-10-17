// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00362240 @ 0x00362240
void FUN_0032cb40();
void FUN_0032cb70();
struct StateA { void (*callback)(); unsigned int first; unsigned int second; unsigned int third; char pad[8]; };
struct StateB { void (*callback)(); unsigned int first; unsigned int second; unsigned int third; char pad[8]; };
struct StateC { unsigned int first; unsigned int second; unsigned int third; int fourth; };
extern StateA DAT_004d8150;
extern StateB DAT_004d8168;
extern StateC DAT_004d8180;
void FUN_00362240() {
    DAT_004d8150.callback = FUN_0032cb40;
    DAT_004d8150.first = 0;
    DAT_004d8150.second = 0;
    DAT_004d8150.third = 0;
    DAT_004d8168.callback = FUN_0032cb70;
    DAT_004d8168.first = 0;
    DAT_004d8168.second = 0;
    DAT_004d8168.third = 0;
    DAT_004d8180.first = 0;
    DAT_004d8180.second = 0;
    DAT_004d8180.third = 0;
    DAT_004d8180.fourth = -1;
}