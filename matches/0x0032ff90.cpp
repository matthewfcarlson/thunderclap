class d3dShader_32ff90 {
  public:
    virtual void v();
    d3dShader_32ff90(int);
    char pad[0x7c];
    int a, b, c;
    char p[0x44];
    float d;
    int e, f;
};
class d3dToon2VertexShader_32ff90 : public d3dShader_32ff90 {
  public:
    virtual void v();
    d3dToon2VertexShader_32ff90(int);
};
d3dToon2VertexShader_32ff90::d3dToon2VertexShader_32ff90(int x) : d3dShader_32ff90(x) {
    c = 0;
    b = 0;
    a = 0;
    d = 1.0f;
    e = 4;
    f = 0x20;
}