class d3dToon2VertexShader_328010 {
  public:
    d3dToon2VertexShader_328010* Init(int x);
};
d3dToon2VertexShader_328010* Alloc(int n);
d3dToon2VertexShader_328010* FUN_00328010(int x) {
    d3dToon2VertexShader_328010* r = Alloc(0xdc);
    if (r)
        return r->Init(x);
    return 0;
}
