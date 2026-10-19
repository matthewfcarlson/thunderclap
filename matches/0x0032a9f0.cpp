extern "C" char DAT_0043386c[];
class ShaderBase_32a9f0 {
  public:
    int v;
    char pad[0x7c];
    int a;
    char b;
    int c;
    char d;
    int e;
};
struct ThisCall_00333520 {
    void BaseInit(int);
};
class SimpleShader : public ShaderBase_32a9f0 {
  public:
    SimpleShader* Init(int);
};
SimpleShader* SimpleShader::Init(int x) {
    ((ThisCall_00333520*)(this))->BaseInit(x);
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    e = 0;
    v = ((int)DAT_0043386c);
    return this;
}