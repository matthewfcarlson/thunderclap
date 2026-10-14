// STATUS: equivalent (tools/equiv.py level 3: 55 inputs, branch coverage 6/6)
// pure3d::PoseAnimationController::vfunc_24 @ 0x00287fc0
namespace pure3d {
class BlendFrameController {
  public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void vfunc_24(int a, float b, int c);
    char pad04[0x24];
    unsigned int count;
};
}
class PoseAnimationController : public pure3d::BlendFrameController {
  public:
    char pad2c[0x11c - 0x2c - 0x0];
    char* tracks[1];
    char pad120[0x130 - 0x120];
    unsigned char dirty;
    char pad131[0x148 - 0x131];
    int index;
    void FUN_00287db0();
    void FUN_00287fc0(int a, float b, int c);
};
void PoseAnimationController::FUN_00287fc0(int a, float b, int c) {
    pure3d::BlendFrameController::vfunc_24(a, b, c);
    dirty = 1;
    FUN_00287db0();
    if (index != 0xffff) {
        for (unsigned int i = 0; i < count; i++) {
            *(float*)(tracks[i] + index * 12 + 8) = b;
        }
    }
}
