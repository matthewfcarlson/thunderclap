class d3dLayeredShader {
  public:
    char pad[0x48];
    unsigned char a;
    char pad2[0x90 - 0x49];
    unsigned char b;
    unsigned char c;
    int vfunc_22();
};
int d3dLayeredShader::vfunc_22() {
    return !a && (b || c);
}