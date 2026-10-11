extern "C" char DAT_003f7404[];
extern "C" void* __cdecl Alloc(unsigned int);
struct InitObj {
    void Init(int);
};
struct CAlertStatusCondition {
    int a, b, c, d, e;
};
struct Factory {
    void* MakeAlert();
};
void* Factory::MakeAlert() {
    CAlertStatusCondition* p = (CAlertStatusCondition*)Alloc(0x14);
    if (p != 0) {
        ((InitObj*)p)->Init(0);
        p->a = ((int)DAT_003f7404);
        p->d = 0;
        p->e = 0;
        return p;
    }
    return 0;
}