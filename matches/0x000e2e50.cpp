class HSlider {
  public:
    char pad[0x17c];
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual float vfunc_9();
};
float HSlider::vfunc_9() {
    return *(float*)((char*)this + 0x17c);
}