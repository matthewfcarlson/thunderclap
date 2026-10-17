// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// pure3d::SimpleFrameController::vfunc_6 @ 0x00284d20
namespace pure3d {
struct SimpleFrameController {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6(float delta, char force);
    virtual void vfunc_7();
    char pad04[12];
    unsigned char flag;
    char pad11[7];
    float speed;
    char pad1c[4];
    int mode;
    int state;
    float frame;
    int range;
    int end;
    float time;
    int otherFrame;
    int animation;
};
}
// equiv-conv: FUN_00289db0 ecx stack stack stack stack stack stack stack stack
float __stdcall FUN_00289db0(int animation, float *, int *, float, float, int, int, int, int);
void pure3d::SimpleFrameController::vfunc_6(float delta, char force) {
    if (animation) {
        time = FUN_00289db0(animation, &frame, &otherFrame, time, delta * speed, range, end, state == 0, mode);
        if (flag == 1 || force == 1)
            vfunc_7();
    }
}