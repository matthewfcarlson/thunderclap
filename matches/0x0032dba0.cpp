class Base {
  public:
    virtual void V();
    Base(int);
};
class Shader : public Base {
  public:
    char pad[0x7c];
    int a;
    int b;
    int special;
    int c;
    unsigned char d;
    unsigned char e;
    char pad2[2];
    int f;
    int g;
    Shader(int);
};
Shader::Shader(int x) : Base(x), special(4) {
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    e = 0;
    f = 0;
    g = 0;
}