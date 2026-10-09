namespace pure3d {
class d3dSimpleShader {
  public:
    char pad0[0x48];
    bool b48;
    char pad1[0x3b];
    bool b84;
    char pad2[7];
    bool b8c;
    const char* vfunc_23();
};
} // namespace pure3d
static const char s_empty[] = "";
static const char s_multi[] = "simple_multicbv";
static const char s_prox[] = "simple_proximity";
const char* pure3d::d3dSimpleShader::vfunc_23() {
    if (!b48 && b84)
        return s_multi;
    if (!b48 && b8c)
        return s_prox;
    return s_empty;
}
