typedef unsigned char u8;
namespace pure3d {
class d3dLightMapShader {
public:
    char pad[0x48];
    u8 field48;
    char pad49[0x3f];
    u8 field88;
    u8 field89;
    const char *vfunc_23();
};
const char *d3dLightMapShader::vfunc_23() {
    if (!field48 && field88) return "layered_multicbv";
    if (!field48 && field89) return "layered_proximity";
    return "";
}
}
