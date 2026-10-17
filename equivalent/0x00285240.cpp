// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 12/12)
// pure3d::BlendFrameController::vfunc_18 @ 0x00285240
namespace pure3d {
struct BlendFrameController {
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(int); virtual void vfunc_19();
    virtual float vfunc_20();
    char pad[0x20];
    int frame;
    unsigned int count;
    struct Entry { char pad[0x18]; float value; int frame; int mode; unsigned char active; };
};
void BlendFrameController::vfunc_18(int newFrame) {
    if (frame == newFrame) return;
    frame = newFrame;
    if (count == 0) return;
    Entry *entry = (Entry *)((char *)this + 0x2c * (count - 1) + 0x2c);
    entry->frame = newFrame;
    if (entry->mode == 0 && *(unsigned int *)&entry->value == 0x7f7fffff) frame = 0;
    entry->value = vfunc_20();
    entry->active = entry->mode != 3 && entry->mode != 5;
}
}