// STATUS: equivalent (tools/equiv.py level 3: 19853 inputs, branch coverage 14/14)
// FEContainer::vfunc_10 @ 0x000eef30
extern "C" double __cdecl sin(double);
struct Item_eef30 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
};
extern float (__cdecl *DAT_004de948)();
class FEContainer {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    char pad[0x4c - 4];
    Item_eef30* groupA[0x80];
    char gap[0x64c - 0x24c];
    Item_eef30* groupB[0x80];
    char pad2[0x96c - 0x84c];
    float pulse;
    float pad3;
    float phase;
};
void FEContainer::vfunc_10() {
    for (int i = 0; i < 0x80; i++) {
        if (!groupA[i])
            break;
        groupA[i]->v1();
    }
    for (int i = 0; i < 0x80; i++) {
        if (!groupB[i])
            break;
        groupB[i]->v2();
    }
    double t = DAT_004de948() // t stays unrounded in an x87 register
         * 6.2831855f + phase;
    pulse = (sin(t) + 1.0f) * 0.5f;
    phase = t - (float)(int)(t * 0.15915494f) * 6.2831855f;
    volatile float *ph = &phase; // the original compares and reloads the rounded member
    if (*ph >= 0.0f && *ph <= 6.2831855f) {
        phase = *ph;
    } else if (*ph > 6.2831855f) {
        phase = 6.2831855f;
    } else {
        phase = 0.0f;
    }
}
