typedef unsigned int u32_32c490;
class d3dShader_32c490 {
  public:
    d3dShader_32c490(u32_32c490 x);
    virtual void Base0();
    char pad[0x7c];
};
class d3dReflShader_32c490 : public d3dShader_32c490 {
  public:
    d3dReflShader_32c490(u32_32c490 x);
    virtual void Run();
    u32_32c490 a;
    u32_32c490 b;
    u32_32c490 c;
};
d3dReflShader_32c490::d3dReflShader_32c490(u32_32c490 x) : d3dShader_32c490(x) {
    a = 0;
    b = 0;
    c = 0x80808080;
}
