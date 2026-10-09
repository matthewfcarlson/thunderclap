namespace pure3d {
extern const float defaultFrame;
class SimpleFrameController {
  public:
    char pad[0x38];
    struct Data {
        char pad2[0x14];
        float value;
    }* data;
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual float vfunc_10();
};
float SimpleFrameController::vfunc_10() {
    if (data)
        return data->value;
    return defaultFrame;
}
} // namespace pure3d