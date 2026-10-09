namespace pure3d {
extern const float defaultValue;
class BlendFrameController {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual float vfunc_10();
    char pad[0x24];
    unsigned int count;
};
float BlendFrameController::vfunc_10() {
    unsigned int n = count;
    if (n > 0)
        return *(float*)(*(int*)((char*)this + 0x28 + n * 0x2c) + 0x14);
    return defaultValue;
}
} // namespace pure3d
