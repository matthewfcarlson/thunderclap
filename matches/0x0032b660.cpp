class d3dLightMapShader {
  public:
    char pad[0x48];
    unsigned char a;
    char pad2[0x3f];
    unsigned char b;
    unsigned char c;
    int vfunc_22();
};
int d3dLightMapShader::vfunc_22() {
    return !a && (b || c);
}