// STATUS: equivalent (tools/equiv.py level 3: 74 inputs, branch coverage 16/16)
// FUN_00329f70 @ 0x00329f70
// FUN_00329f70 @ 0x00329f70
struct Mat {
    float diffuse[4];
    float ambient[4];
    float specular[4];
    float emissive[4];
    float power;
};
struct MatSrc {
    unsigned int diffuse;
    unsigned int specular;
    unsigned int ambient;
    unsigned int emissive;
    float power;
};
struct CullState {
    void FUN_003219c0();
};
extern void __stdcall D3DDevice_SetRenderState_CullMode(unsigned int mode);
extern void __stdcall D3DDevice_SetRenderState_TwoSidedLighting(unsigned int on);
extern void __stdcall D3DDevice_SetMaterial(Mat* m);
extern void __stdcall D3DDevice_SetBackMaterial(Mat* m);
extern unsigned int DAT_0039db08;
extern unsigned int DAT_0039dea8;
extern unsigned int DAT_0039deac;
struct Color {};
// equiv-conv: FUN_00329b40 ecx stack
void FUN_00329b40(Color* self, unsigned int packed);
class Context {
  public:
    CullState* cull;
    char pad04[0x104 - 4];
    unsigned char lit;
    unsigned char twoSided;
    void FUN_00329f70(unsigned char enable, unsigned char two, MatSrc* src);
};
void Context::FUN_00329f70(unsigned char enable, unsigned char two, MatSrc* src) {
    if (twoSided != two || lit != enable) {
        twoSided = two;
        if (two) {
            D3DDevice_SetRenderState_CullMode(0);
            D3DDevice_SetRenderState_TwoSidedLighting(enable);
        } else {
            D3DDevice_SetRenderState_TwoSidedLighting(0);
            cull->FUN_003219c0();
        }
    }
    if (lit) {
        if (!enable) {
            lit = enable;
            DAT_0039db08 = DAT_0039db08 | 0x3200;
            DAT_0039dea8 = 0;
            DAT_0039deac = 0;
            return;
        }
    } else if (!enable) {
        return;
    }
    Mat mat;
    lit = enable;
    DAT_0039db08 = DAT_0039db08 | 0x1200;
    DAT_0039dea8 = 1;
    unsigned int spec = 0;
    if (src->power > 0.0f)
        spec = 1;
    DAT_0039deac = spec;
    DAT_0039db08 = DAT_0039db08 | 0x3000;
    FUN_00329b40((Color*)mat.diffuse, src->diffuse);
    FUN_00329b40((Color*)mat.ambient, src->ambient);
    FUN_00329b40((Color*)mat.specular, src->specular);
    FUN_00329b40((Color*)mat.emissive, src->emissive);
    mat.power = src->power;
    D3DDevice_SetMaterial(&mat);
    if (twoSided)
        D3DDevice_SetBackMaterial(&mat);
}
