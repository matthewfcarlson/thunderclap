class HSlider {
  public:
    virtual void v0();
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
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    char pad[0x14c];
    float val;
    int mode;
    char p[4];
    float low;
    float high;
    char p2[0x14];
    float accum;
    void UpdateA(float);
    void UpdateB(float);
};
extern "C" float(__cdecl* RandomValue)();
void HSlider::vfunc_4() {
    if (mode == 1) {
        if (val < high) {
            accum = RandomValue() + accum;
            float x = RandomValue();
            UpdateA(x + x);
        }
    } else if (mode == 2) {
        if (val > low) {
            accum = RandomValue() + accum;
            float x = RandomValue();
            UpdateB(x + x);
        }
    }
}