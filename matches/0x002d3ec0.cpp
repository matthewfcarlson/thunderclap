// Same code shape as 0x000d7a30 (propagated; names are from that function)
class DrawablePrimitive_2d3ec0 {
  public:
    virtual void f0();
};
class IValueChangedReceiver {
  public:
    virtual void f1();
};
class ParticleEmitter_2d3ec0 : public DrawablePrimitive_2d3ec0, public IValueChangedReceiver {
  public:
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual float vfunc_9();
    char pad[0xA0 - 8];
    float value;
};
float ParticleEmitter_2d3ec0::vfunc_9() {
    return value;
}