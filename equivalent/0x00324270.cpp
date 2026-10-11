// STATUS: equivalent (tools/equiv.py level 3: 69 inputs, branch coverage 18/18)
// FUN_00324270 @ 0x00324270
// FUN_00324270 @ 0x00324270
namespace pure3d {
struct Vec4 {
    float x;
    float y;
    float z;
    union {
        float w;
        unsigned int wBits;
    };
};
// equiv-conv: FUN_0031ffc0 ecx stack
void FUN_0031ffc0(Vec4* self, unsigned int packed);
struct Matrix {
    float m[16];
    void FUN_0022c0b0();
};
struct ShaderColors {
    unsigned int c0;
    unsigned int c1;
    unsigned int c2;
    unsigned int c3;
    unsigned int extra;
};
struct Light {
    int type;
    Vec4 diffuse;
    Vec4 specular;
    Vec4 ambient;
    float position[3];
    Vec4 directionRange;
    float falloff;
    float attenuation[3];
    float theta;
    float phi;
};
class ColorSource {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21(ShaderColors* out);
};
class Shader {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual unsigned int* v36(unsigned int* out);
    void FUN_00321310();
    void FUN_00321dc0(int* ids, int key);
    void FUN_00324270(ColorSource* source);
};
}
namespace D3D8 {
void __stdcall D3DDevice_GetLight(int index, pure3d::Light* out);
void __stdcall D3DDevice_GetTransform(int state, pure3d::Matrix* out);
void __fastcall D3DDevice_SetVertexShaderConstant1(int reg, const void* data);
void __fastcall D3DDevice_SetVertexShaderConstant4(int reg, const void* data);
}

void pure3d::Shader::FUN_00324270(ColorSource* source) {
    int ids[4];
    Vec4 constA, zero, out1, out2, out3, out4, out5;
    ShaderColors colors;
    unsigned int scratch;
    Matrix view, inverse;
    Light light0, light1, light2, light3;

    FUN_00321310();
    constA.x = 0.0f;
    constA.y = 1.0f;
    constA.z = 256.0f;
    constA.w = 0.5f;
    FUN_00321dc0(ids, 0);
    int id0 = ids[0];
    int id1 = ids[1];
    D3D8::D3DDevice_GetLight(id0 == -1 ? 0 : id0, &light0);
    D3D8::D3DDevice_GetLight(id1 == -1 ? 0 : id1, &light1);
    D3D8::D3DDevice_GetLight(ids[2] == -1 ? 0 : ids[2], &light2);
    D3D8::D3DDevice_GetLight(ids[3] == -1 ? 0 : ids[3], &light3);
    source->v21(&colors);
    zero.x = 0.0f;
    zero.y = 0.0f;
    zero.z = 0.0f;
    zero.w = 0.0f;
    FUN_0031ffc0(&out1, colors.c1);
    FUN_0031ffc0(&out2, colors.c0);
    FUN_0031ffc0(&out3, colors.c3);
    FUN_0031ffc0(&out4, colors.c2);
    FUN_0031ffc0(&out5, *v36(&scratch));
    if (out3.w == 0.0f) {
        out3.wBits = out2.wBits;
        out2.wBits = 0;
    }
    out1.wBits = colors.extra;
    out3.x = out5.x * out4.x + out3.x;
    out3.y = out5.y * out4.y + out3.y;
    out3.z = out5.z * out4.z + out3.z;
    out3.w = out5.w * out4.w + out3.w;
    D3D8::D3DDevice_GetTransform(1, &view);
    inverse = view;
    inverse.FUN_0022c0b0();
    D3D8::D3DDevice_SetVertexShaderConstant1(0x60, &constA);
    D3D8::D3DDevice_SetVertexShaderConstant4(0x62, &inverse);
    D3D8::D3DDevice_SetVertexShaderConstant1(0x66, &out2);
    D3D8::D3DDevice_SetVertexShaderConstant1(0x67, &out1);
    D3D8::D3DDevice_SetVertexShaderConstant1(0x68, &out3);
    D3D8::D3DDevice_SetVertexShaderConstant1(0x69, &light0.directionRange);
    D3D8::D3DDevice_SetVertexShaderConstant1(0x6a, id0 != -1 ? &light0.diffuse : &zero);
    D3D8::D3DDevice_SetVertexShaderConstant1(0x6b, &light1.directionRange);
    D3D8::D3DDevice_SetVertexShaderConstant1(0x6c, id1 != -1 ? &light1.diffuse : &zero);
    D3D8::D3DDevice_SetVertexShaderConstant1(0x6d, &light2.directionRange);
    D3D8::D3DDevice_SetVertexShaderConstant1(0x6e, ids[2] != -1 ? &light2.diffuse : &zero);
    D3D8::D3DDevice_SetVertexShaderConstant1(0x6f, &light3.directionRange);
    D3D8::D3DDevice_SetVertexShaderConstant1(0x70, ids[3] != -1 ? &light3.diffuse : &zero);
}
