class ShaderBase {
  public:
    int v;
    char pad[0x7c];
    int a;
    char b;
    int c;
    char d;
    int e;
};
void __stdcall BaseInit(int);
class SimpleShader : public ShaderBase {
  public:
    SimpleShader* Init(int);
};
SimpleShader* SimpleShader::Init(int x) {
    BaseInit(x);
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    e = 0;
    v = 0x43386c;
    return this;
}