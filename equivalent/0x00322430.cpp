// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// pure3d::d3dExtVertexProgram::vfunc_3 @ 0x00322430
// pure3d::d3dExtVertexProgram::vfunc_3 @ 0x00322430
namespace pure3d {
struct VertexProgramState {
    char reserved[0x208];
    struct VertexProgramDevice* device;
};
struct VertexProgramDevice {
    void FUN_003290e0(int, int, int, int);
};
struct d3dExtVertexProgram {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3(int, int, int, int);
    VertexProgramState* state;
};
void d3dExtVertexProgram::vfunc_3(int a0, int a1, int a2, int a3) {
    state->device->FUN_003290e0(a0, a1, a2, a3);
}
}
