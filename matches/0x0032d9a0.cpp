class d3dLayeredShader {
  public:
    virtual void f0();
    char pad[0x44];
    char a;
    char pad2[0x47];
    char b;
    char c;
    const char* vfunc_23();
};
const char* d3dLayeredShader::vfunc_23() {
    if (!a && b)
        return "layered_multicbv";
    if (!a && c)
        return "layered_proximity";
    return "";
}