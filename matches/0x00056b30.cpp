extern "C" char DAT_003f7404[];
extern "C" void* __cdecl Alloc(unsigned int);
struct InitObj_56b30 {
    void Init(int);
};
struct CAlertStatusCondition {
    int a, b, c, d, e;
};
struct Factory_56b30 {
    void* MakeAlert();
};
void* Factory_56b30::MakeAlert() {
    CAlertStatusCondition* p = (CAlertStatusCondition*)Alloc(0x14);
    if (p != 0) {
        ((InitObj_56b30*)p)->Init(0);
        p->a = ((int)DAT_003f7404);
        p->d = 0;
        p->e = 0;
        return p;
    }
    return 0;
}