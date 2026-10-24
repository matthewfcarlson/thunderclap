// STATUS: equivalent (tools/equiv.py level 3: 2976 inputs, branch coverage 14/14)
// FEScreenBase::vfunc_10 @ 0x000ef4f0
struct ScreenItem {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6(float value, int arg);
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
};
struct CameraLike {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5(float angle, float scale);
};
struct Clock_ef4f0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual float vf16();
};
struct Widget_ef4f0 {
    void FUN_000dff70();
};
extern Clock_ef4f0* DAT_0052c2a4;
extern float (__stdcall *DAT_004de948)();
void __cdecl FUN_0009f790(void* obj, float t, float* a, float* b);
void __cdecl FUN_000f61e0(CameraLike* cam);

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
    char pad[0x98c - 4];
};
class FEScreenBase : public FEContainer {
public:
    void* camData;
    CameraLike* camera;
    char pad994[0x9a4 - 0x994];
    ScreenItem* groupA[4];
    char pad9b4[0x9c4 - 0x9b4];
    ScreenItem* groupB[6];
    Widget_ef4f0 widget;
    char pad9dd[0xab8 - 0x9dd];
    bool active;
    ScreenItem* items[0x20];
    int itemCount;
    virtual void vfunc_10();
};
void FEScreenBase::vfunc_10() {
    if (!active)
        return;
    float a, b;
    FUN_0009f790(camData, DAT_0052c2a4->vf16(), &a, &b);
    camera->vf5(a * 0.017453292f, 1.0f);
    widget.FUN_000dff70();
    FUN_000f61e0(camera);
    for (int i = 0; i < 4; i++) {
        if (!groupA[i])
            break;
        groupA[i]->vf6(DAT_004de948() * 1000.0f, 1);
    }
    for (int i = 0; i < 6; i++) {
        if (!groupB[i])
            break;
        groupB[i]->vf6(DAT_004de948() * 1000.0f, 1);
    }
    FEContainer::vfunc_10();
    for (int i = 0; i < itemCount; i++)
        items[i]->vf10();
}
