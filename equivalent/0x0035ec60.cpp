// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0035ec60 @ 0x0035ec60
typedef unsigned __int64 Key;
extern Key __cdecl FUN_0027b020(const char*);

extern Key DAT_004e25a0;
extern Key DAT_004e25a8;
extern Key DAT_004e25b0;
extern Key DAT_004e25b8;
extern Key DAT_004e25c0;
extern Key DAT_004e25c8;

void FUN_0035ec60()
{
    DAT_004e25a0 = FUN_0027b020("0 - Small");
    DAT_004e25a8 = FUN_0027b020("1 - Medium");
    DAT_004e25b0 = FUN_0027b020("2 - Large");
    DAT_004e25b8 = FUN_0027b020("3 - Tiny");
    DAT_004e25c0 = FUN_0027b020("4 - Hulk Small");
    DAT_004e25c8 = FUN_0027b020("5 - Hulk Medium");
}
