// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_0032fd40 @ 0x0032fd40
struct Vec4 {
    float x, y, z, w;
};
struct Matrix {
    float m[16];
    void FUN_0022ca90(Matrix*, Matrix*);
    void FUN_0022cdb0();
    void FUN_0022c310(Vec4* in, Vec4* out);
};
namespace D3D8 {
void __stdcall D3DDevice_GetTransform(unsigned long type, Matrix* out);
}
void __stdcall FUN_0032fd40(Vec4* result) {
    Vec4 origin;
    Vec4 transformed;
    Matrix view;
    Matrix world;
    Matrix product;
    Matrix inverse;
    origin.x = 0.0f;
    origin.y = 0.0f;
    origin.z = 0.0f;
    origin.w = 1.0f;
    D3D8::D3DDevice_GetTransform(6, &view);
    D3D8::D3DDevice_GetTransform(0, &world);
    product.FUN_0022ca90(&view, &world);
    inverse = product;
    inverse.FUN_0022cdb0();
    inverse.FUN_0022c310(&origin, &transformed);
    result->x = transformed.x;
    result->y = transformed.y;
    result->z = transformed.z;
    result->w = transformed.w;
}
