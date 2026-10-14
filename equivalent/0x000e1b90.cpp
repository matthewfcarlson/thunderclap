// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000e1b90 @ 0x000e1b90
extern "C" int __cdecl FUN_000dfcc0(char*, int, const char*, ...);
struct FEDoPushDialog {
 virtual void placeholder();
 int unused;
 int stateA;
 int stateB;
 int owner;
 char flag;
 char padding[31];
 char text1[32];
 char text2[256];
 char text3[32];
 char text4[32];
 char text5[32];
 int finalValue;
 FEDoPushDialog(int, const char*, const char*, const char*, const char*, const char*, int);
};
FEDoPushDialog::FEDoPushDialog(int value, const char* a, const char* b, const char* c, const char* d, const char* e, int last) {
 stateA = -1;
 stateB = -1;
 owner = value;
 flag = 0;
 FUN_000dfcc0(text1,32,"%s",a);
 FUN_000dfcc0(text2,256,"%s",b);
 FUN_000dfcc0(text3,32,"%s",c);
 FUN_000dfcc0(text4,32,"%s",d);
 FUN_000dfcc0(text5,32,"%s",e);
 finalValue = last;
}
