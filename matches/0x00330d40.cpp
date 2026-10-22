typedef unsigned int u32_330d40;
class d3dShader_330d40 {
  public:
    void Init(u32_330d40);
};
extern int vtableSymbol;
class d3dToonVertexShader_330d40 : public d3dShader_330d40 {
  public:
    char p[0x94];
    u32_330d40 x94;
    u32_330d40 x98;
    u32_330d40 x9c;
    char q[0xe0 - 0xa0];
    u32_330d40 xe0;
    u32_330d40 xe4;
    u32_330d40 xe8;
    d3dToonVertexShader_330d40* Run(u32_330d40);
};
d3dToonVertexShader_330d40* d3dToonVertexShader_330d40::Run(u32_330d40 arg) {
    Init(arg);
    x94 = 0;
    x98 = 0;
    xe0 = 0;
    x9c = 0;
    *(int**)this = &vtableSymbol;
    xe4 = 4;
    xe8 = 0x3c03126f;
    return this;
}