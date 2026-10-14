extern void* vShader[];
class pddiShaderBase {
  public:
    void* vptr;
    pddiShaderBase();
};
class pddiShader : public pddiShaderBase {
  public:
    pddiShader();
};
pddiShader::pddiShader() : pddiShaderBase() {
    vptr = vShader;
}
