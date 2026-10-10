// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 16/16)
// FUN_00322610 @ 0x00322610
typedef unsigned long DWORD;
namespace D3D8 {
void __stdcall D3DResource_Release(void*);
void __stdcall D3DDevice_DeletePixelShader(DWORD);
}
struct RefObj {
    virtual void vfunc_0();
    virtual void vfunc_1();
};
class pddiExtension {
  public:
    virtual ~pddiExtension() throw() {}
};
class d3dExtFramebufferEffects : public pddiExtension {
  public:
    char pad4[4];
    RefObj* objA;
    RefObj* objB;
    char pad0[0x20 - 0x10];
    void* res20;
    DWORD shaders[8][2];
    DWORD shader64;
    char pad1[0xa8 - 0x68];
    void* resA8;
    virtual ~d3dExtFramebufferEffects() throw();
};
d3dExtFramebufferEffects::~d3dExtFramebufferEffects() throw() {
    if (objA)
        objA->vfunc_1();
    if (objB)
        objB->vfunc_1();
    if (res20) {
        D3D8::D3DResource_Release(res20);
        res20 = 0;
    }
    if (resA8) {
        D3D8::D3DResource_Release(resA8);
        resA8 = 0;
    }
    if (shader64) {
        D3D8::D3DDevice_DeletePixelShader(shader64);
        shader64 = 0;
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 2; j++) {
            if (shaders[i][j]) {
                D3D8::D3DDevice_DeletePixelShader(shaders[i][j]);
                shaders[i][j] = 0;
            }
        }
    }
}
