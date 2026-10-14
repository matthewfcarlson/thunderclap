// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00361cf0 @ 0x00361cf0
typedef void (*Handler_361cf0)();
struct Entry_361cf0 {
    Handler_361cf0 fn;
    int a;
    int b;
    int c;
    char pad[8];
};
struct LastEntry {
    int a, b, c, d;
};
void FUN_003333c0();
extern Entry_361cf0 DAT_004d7c48;
void FUN_003333e0();
extern Entry_361cf0 DAT_004d7c60;
void FUN_003333f0();
extern Entry_361cf0 DAT_004d7c78;
void FUN_003337d0();
extern Entry_361cf0 DAT_004d7c90;
void FUN_00333770();
extern Entry_361cf0 DAT_004d7ca8;
void FUN_003333a0();
extern Entry_361cf0 DAT_004d7cc0;
void FUN_003333b0();
extern Entry_361cf0 DAT_004d7cd8;
void FUN_00333400();
extern Entry_361cf0 DAT_004d7cf0;
void FUN_0032b940();
extern Entry_361cf0 DAT_004d7d08;
void FUN_0032b960();
extern Entry_361cf0 DAT_004d7d20;
void FUN_0032b980();
extern Entry_361cf0 DAT_004d7d38;
extern LastEntry DAT_004d7d50;

void FUN_00361cf0()
{
    DAT_004d7c48.fn = FUN_003333c0;
    DAT_004d7c60.fn = FUN_003333e0;
    DAT_004d7c78.fn = FUN_003333f0;
    DAT_004d7c90.fn = FUN_003337d0;
    DAT_004d7ca8.fn = FUN_00333770;
    DAT_004d7cc0.fn = FUN_003333a0;
    DAT_004d7cd8.fn = FUN_003333b0;
    DAT_004d7cf0.fn = FUN_00333400;
    DAT_004d7d08.fn = FUN_0032b940;
    DAT_004d7d20.fn = FUN_0032b960;
    DAT_004d7d38.fn = FUN_0032b980;
    DAT_004d7c48.a = 0;
    DAT_004d7c48.b = 0;
    DAT_004d7c48.c = 0;
    DAT_004d7c60.a = 0;
    DAT_004d7c60.b = 0;
    DAT_004d7c60.c = 0;
    DAT_004d7c78.a = 0;
    DAT_004d7c78.b = 0;
    DAT_004d7c78.c = 0;
    DAT_004d7c90.a = 0;
    DAT_004d7c90.b = 0;
    DAT_004d7c90.c = 0;
    DAT_004d7ca8.a = 0;
    DAT_004d7ca8.b = 0;
    DAT_004d7ca8.c = 0;
    DAT_004d7cc0.a = 0;
    DAT_004d7cc0.b = 0;
    DAT_004d7cc0.c = 0;
    DAT_004d7cd8.a = 0;
    DAT_004d7cd8.b = 0;
    DAT_004d7cd8.c = 0;
    DAT_004d7cf0.a = 0;
    DAT_004d7cf0.b = 0;
    DAT_004d7cf0.c = 0;
    DAT_004d7d08.a = 0;
    DAT_004d7d08.b = 0;
    DAT_004d7d08.c = 0;
    DAT_004d7d20.a = 0;
    DAT_004d7d20.b = 0;
    DAT_004d7d20.c = 0;
    DAT_004d7d38.a = 0;
    DAT_004d7d38.b = 0;
    DAT_004d7d38.c = 0;
    DAT_004d7d50.a = 0;
    DAT_004d7d50.b = 0;
    DAT_004d7d50.c = 0;
    DAT_004d7d50.d = -1;
}
