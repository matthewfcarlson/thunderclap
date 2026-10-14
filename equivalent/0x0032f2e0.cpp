// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_0032f2e0 @ 0x0032f2e0
struct Resource_32f2e0 { Resource_32f2e0* FUN_00326110(void* owner, int flag); };
extern "C" void* __cdecl FUN_0008d690(unsigned int size);
struct FUN_00333520 {
    virtual void dummy();
    char pad04[12];
    void* owner;
    char pad14[108];
    FUN_00333520(void* arg);
};
namespace pure3d {
struct d3dRefractVertexShader : FUN_00333520 {
    unsigned int field80;
    Resource_32f2e0* resource;
    float field88;
    float field8c;
    int field90;
    virtual void dummy();
    d3dRefractVertexShader(void* arg);
};
d3dRefractVertexShader::d3dRefractVertexShader(void* arg) : FUN_00333520(arg) {
    field80 = 0;
    resource = 0;
    field88 = 10.0f;
    field8c = 1.0f;
    field90 = -1;
    Resource_32f2e0* allocation = (Resource_32f2e0*)FUN_0008d690(248);
    if (allocation) resource = allocation->FUN_00326110(owner, 0);
    else resource = 0;
}
}
