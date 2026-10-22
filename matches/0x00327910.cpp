extern void* vShader[];
class pddiObject_327910 {
  public:
    void* vptr;
    pddiObject_327910();
};
class pddiShader : public pddiObject_327910 {
  public:
    pddiShader();
};
pddiShader::pddiShader() : pddiObject_327910() {
    vptr = vShader;
}
