#include "gen/pure3d.h"

namespace D3D8 {
void __fastcall D3DDevice_SetVertexShaderConstantNotInline(int, const void*, int);
}
namespace pure3d {
struct Device_322200 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual unsigned int slot18(int);
};
struct Matrix_322200 {
    float m[16];
    void FUN_0022ca90(unsigned int, unsigned int);
    void FUN_0022c0b0();
};

} // namespace pure3d
void pure3d::d3dExtHardwareSkinning::vfunc_5(int index, int __p1) { unsigned int value = (unsigned int)__p1;

    unsigned int result = (*(Device_322200 * *)&this->f_04)->slot18(0);
    Matrix_322200 matrix;
    matrix.FUN_0022ca90(value, result);
    Matrix_322200 transformed = matrix;
    transformed.FUN_0022c0b0();
    D3D8::D3DDevice_SetVertexShaderConstantNotInline(index * 3 + 0x71, &transformed, 12);
}
