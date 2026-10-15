class pure3d_d3dLayeredLMapShader {
  public:
    char pad[0x48];
    char a;
    char pad2[0x47];
    char b;
    char c;
    const char* vfunc_23();
};
extern const char zeroName[];
extern const char multiName[];
extern const char proximityName[];
const char* pure3d_d3dLayeredLMapShader::vfunc_23() {
    if (!a && b)
        return multiName;
    if (!a && c)
        return proximityName;
    return zeroName;
}