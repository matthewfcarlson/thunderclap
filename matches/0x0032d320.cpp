namespace pure3d {
class Base_32d320 {
  public:
    Base_32d320(void* a);
    virtual void f();
    char pad[0x3c];
    int m40;
    char p[0x3c];
};
class d3dPointSpriteShader : public Base_32d320 {
  public:
    d3dPointSpriteShader(void* a);
    virtual void f();
    int m80;
    unsigned char m84;
    int m88, m8c, m90, m94, m98, m9c, ma0;
};
d3dPointSpriteShader::d3dPointSpriteShader(void* a) : Base_32d320(a) {
    m80 = 0;
    m84 = 1;
    m88 = 0x3f800000;
    m8c = 0;
    m90 = 0x42c80000;
    m94 = 0x3f800000;
    m98 = 0;
    m9c = 0;
    ma0 = 0x41a00000;
    m40 = 1;
}
} // namespace pure3d
