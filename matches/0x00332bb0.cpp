struct I {
    virtual void f();
    virtual void Release();
};
class Shader {
  public:
    virtual void v0();
    char pad[0x7c];
    I* m80;
    I* m84;
    void target();
    void common();
};
void Shader::target() {
    *(volatile unsigned long*)this = 0x433f74;
    if (m84)
        m84->Release();
    if (m80)
        m80->Release();
    common();
}