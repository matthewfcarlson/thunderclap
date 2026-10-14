// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 11/12, incomplete)
// FUN_001e8d40 @ 0x001e8d40
extern "C" int __cdecl sprintf(char *, const char *, ...);
extern unsigned int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern int DAT_004e3694;
extern float DAT_004e369c, DAT_004e36a0;
struct Manager { void FUN_00265920(char *, int *, int); };
extern Manager *DAT_00527c58;
struct Clip {
 int active;
 int reserved;
 unsigned int size;
 int reserved2;
 unsigned int kind;
 void FUN_001e8d40();
};
void Clip::FUN_001e8d40() {
 unsigned int cookie = DAT_004d9968;
 if (active == 0 && DAT_004e3694 == 0) {
 char name[16];
 sprintf(name, "%d.%s", this, "clips");
 DAT_00527c58->FUN_00265920(name, &DAT_004e3694, 1);
 unsigned int type = kind;
 active = 1;
 double amount = (int)size;
 if ((int)size < 0) amount += 4294967296.0f;
 if (type > 0) DAT_004e369c = amount + DAT_004e369c;
 else DAT_004e36a0 = amount + DAT_004e36a0;
 }
 __security_check_cookie(cookie);
}
