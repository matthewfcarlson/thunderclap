typedef unsigned int u32;
class Shader {
public:
    Shader(u32 x);
    virtual void Base0();
    char pad[0x7c];
};
class D3dReflShader : public Shader {
public:
    D3dReflShader(u32 x);
    virtual void Run();
    u32 a;
    u32 b;
    u32 c;
};
D3dReflShader::D3dReflShader(u32 x) : Shader(x) {
    a = 0;
    b = 0;
    c = 0x80808080;
}
