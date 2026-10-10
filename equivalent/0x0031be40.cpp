// STATUS: equivalent (tools/equiv.py level 3: 53 inputs, branch coverage 14/14)
// pure3d::d3dPrimStream::vfunc_0 @ 0x0031be40
typedef unsigned long DWORD;
extern "C" void* memcpy(void*, const void*, unsigned int);
namespace D3D8 {
char* __stdcall D3DVertexBuffer_Lock2(void*, DWORD);
}
struct ShaderInfo {
    char pad[8];
    DWORD flags;
};
void FUN_0031c230(long hr);
namespace pure3d {
class d3dBasePrimStream {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
class d3dPrimStream : public d3dBasePrimStream {
  public:
    int stride;
    char* posPtr;
    char* normalPtr;
    char* colorPtr;
    char* uvPtr;
    char pad18[4];
    int vertCount;
    int pendingCount;
    char pending[0x130 - 0x24];
    void* vbuf;
    char locked;
    char pad135[0x148 - 0x135];
    int colorCount;
    int uvCount;
    char pad150[0x158 - 0x150];
    ShaderInfo* shader;
    int total;
    virtual void vfunc_0(bool copyPending);
    virtual void vfunc_1();
};
}
void pure3d::d3dPrimStream::vfunc_0(bool copyPending) {
    char* p = D3D8::D3DVertexBuffer_Lock2(vbuf, 0);
    FUN_0031c230(0);
    locked = 1;
    if (copyPending && pendingCount > 0) {
        memcpy(p, pending, stride * pendingCount);
        p += stride * pendingCount;
        vertCount = pendingCount;
        total += pendingCount;
    } else {
        vertCount = 0;
    }
    posPtr = p;
    stride = 0xc;
    p += 0xc;
    DWORD flags = shader->flags;
    if (flags & 0x10) {
        normalPtr = p;
        stride = 0x18;
        p += 0xc;
    } else {
        normalPtr = 0;
    }
    flags = shader->flags;
    if (flags & 0x20) {
        colorPtr = p;
        stride += 4;
        p += 4;
    } else if ((flags & 0x4000) && colorCount > 0) {
        colorPtr = p;
        stride += colorCount * 4;
        p += colorCount * 4;
    } else {
        colorPtr = 0;
    }
    if (uvCount != 0) {
        uvPtr = p;
        stride += uvCount * 8;
    } else {
        uvPtr = 0;
    }
}
