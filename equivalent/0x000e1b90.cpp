// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000e1b90 @ 0x000e1b90
extern "C" char DAT_0040c074[];

void __cdecl FUN_000dfcc0(char *dst, int size, const char *fmt, const char *arg);

struct FEDoPushDialog {
    int vptr;
    char pad04[4];
    int f08;
    int f0c;
    int f10;
    char f14;
    char pad15[0x34 - 0x15];
    char text0[0x20];           // 0x34
    char text1[0x100];          // 0x54
    char text2[0x20];           // 0x154
    char text3[0x20];           // 0x174
    char text4[0x20];           // 0x194
    int f1b4;                   // 0x1b4
    FEDoPushDialog *FUN_000e1b90(int a, const char *s0, const char *s1, const char *s2,
                                 const char *s3, const char *s4, int b);
};

FEDoPushDialog *FEDoPushDialog::FUN_000e1b90(int a, const char *s0, const char *s1, const char *s2,
                                             const char *s3, const char *s4, int b)
{
    f08 = -1;
    f0c = -1;
    f10 = a;
    f14 = 0;
    vptr = (int)DAT_0040c074;
    FUN_000dfcc0(text0, 0x20, "%s", s0);
    FUN_000dfcc0(text1, 0x100, "%s", s1);
    FUN_000dfcc0(text2, 0x20, "%s", s2);
    FUN_000dfcc0(text3, 0x20, "%s", s3);
    FUN_000dfcc0(text4, 0x20, "%s", s4);
    f1b4 = b;
    return this;
}
