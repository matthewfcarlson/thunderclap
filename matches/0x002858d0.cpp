namespace pure3d {
class SimpleFrameController {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void vfunc_12(float);
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual float v20();
    char pad[0x1c];
    int mode;
    char pad2[4];
    float current;
    float low;
    float high;
    float desired;
    unsigned char active;
};
void SimpleFrameController::vfunc_12(float frame) {
    if (!(frame >= low && frame <= high)) {
        if (frame > high)
            frame = high;
        else
            frame = low;
    }
    desired = frame;
    current = v20();
    active = (mode == 3 || mode == 5) ? 0 : 1;
}
} // namespace pure3d