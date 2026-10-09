namespace pure3d {
class d3dExtVertexProgram {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
};
}
namespace D3D8 {
void __fastcall D3DDevice_SetVertexShaderConstant1(void* dev, int reg);
void __fastcall D3DDevice_SetVertexShaderConstant4(void* dev, int reg);
void __fastcall D3DDevice_SetVertexShaderConstantNotInline(void* dev, int reg, int bytes);
}
void __stdcall vfunc_7_impl(pure3d::d3dExtVertexProgram* self, int reg, int count) {
    char* dev = (char*)self + 0x60;
    if (count == 1) {
        D3D8::D3DDevice_SetVertexShaderConstant1(dev, reg);
        return;
    }
    if (count == 4) {
        D3D8::D3DDevice_SetVertexShaderConstant4(dev, reg);
        return;
    }
    D3D8::D3DDevice_SetVertexShaderConstantNotInline(dev, reg, count << 2);
}
