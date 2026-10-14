struct R {
    char pad[0xcd];
    char f;
};
int __stdcall FUN_001fc7f0(unsigned int);
char __stdcall FUN_001fcb70(unsigned int x) {
    R* p = (R*)FUN_001fc7f0(x);
    if (p == 0)
        return 0;
    return p->f;
}
