extern "C" char DAT_00433f74[];
struct I_332bb0 {
    virtual void f();
    virtual void Release();
};
class Shader {
  public:
    virtual void v0();
    char pad[0x7c];
    I_332bb0* m80;
    I_332bb0* m84;
    void target();
    void common();
};
void Shader::target() {
    *(volatile unsigned long*)this = ((int)DAT_00433f74);
    if (m84)
        m84->Release();
    if (m80)
        m80->Release();
    common();
}