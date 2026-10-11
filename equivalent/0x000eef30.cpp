// STATUS: equivalent (tools/equiv.py level 3: 62 inputs, branch coverage 14/14)
// FEContainer::vfunc_10 @ 0x000eef30
extern "C" double __cdecl sin(double);
struct Item {
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
    Item* groupA[0x80];
    char gap[0x64c - 0x24c];
    Item* groupB[0x80];
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
    float t = DAT_004de948() * 6.2831855f + phase;
    pulse = ((float)sin((double)t) + 1.0f) * 0.5f;
    phase = t - (float)(int)(t * 0.15915494f) * 6.2831855f;
    if (phase >= 0.0f && phase <= 6.2831855f) {
        phase = phase;
    } else if (phase > 6.2831855f) {
        phase = 6.2831855f;
    } else {
        phase = 0.0f;
    }
}
