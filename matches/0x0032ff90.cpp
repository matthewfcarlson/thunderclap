class Base_32ff90 {
  public:
    virtual void v();
    Base_32ff90(int);
    char pad[0x7c];
    int a, b, c;
    char p[0x44];
    float d;
    int e, f;
};
class Shader : public Base_32ff90 {
  public:
    virtual void v();
    Shader(int);
};
Shader::Shader(int x) : Base_32ff90(x) {
    c = 0;
    b = 0;
    a = 0;
    d = 1.0f;
    e = 4;
    f = 0x20;
}