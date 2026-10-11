extern "C" char DAT_0042afa8[];
extern "C" char DAT_0042bf6c[];
extern "C" char DAT_004342e8[];
extern "C" char DAT_004342fc[];
extern "C" char DAT_004cdbb0[];
struct Callback {
    volatile int a;
    volatile int b;
    volatile int c;
    volatile int d;
};
extern void __fastcall helper(Callback*);
Callback* __fastcall FUN_003350f0(Callback* p) {
    p->a = ((int)DAT_0042afa8);
    p->b = *(volatile int*)((int)DAT_004cdbb0);
    helper(p);
    p->c = ((int)DAT_0042bf6c);
    p->a = ((int)DAT_004342fc);
    p->c = ((int)DAT_004342e8);
    p->d = 0;
    return p;
}