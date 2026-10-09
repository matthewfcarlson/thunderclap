struct Callback {
    volatile int a;
    volatile int b;
    volatile int c;
    volatile int d;
};
extern void __fastcall helper(Callback*);
Callback* __fastcall FUN_003350f0(Callback* p) {
    p->a = 0x42afa8;
    p->b = *(volatile int*)0x4cdbb0;
    helper(p);
    p->c = 0x42bf6c;
    p->a = 0x4342fc;
    p->c = 0x4342e8;
    p->d = 0;
    return p;
}