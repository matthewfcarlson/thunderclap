class NamedValueFloat {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    char pad[0x40 - 4];
    float value40;
    float value44;
    void* callback48;
};
struct Callback {
    virtual void changed(float);
};
void NamedValueFloat::vfunc_1() {
    float v = value44;
    value40 = v;
    if (callback48)
        ((Callback*)callback48)->changed(v);
    vfunc_0();
}