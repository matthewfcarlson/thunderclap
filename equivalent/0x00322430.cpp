// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// pure3d::d3dExtVertexProgram::vfunc_3 @ 0x00322430
namespace pure3d {
struct VertexProgramState {
    char reserved[0x208];
    struct VertexProgramDevice* device;
};
struct VertexProgramDevice {
    void FUN_003290e0();
};
struct d3dExtVertexProgram {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    VertexProgramState* state;
};
void d3dExtVertexProgram::vfunc_3() {
    state->device->FUN_003290e0();
}
}