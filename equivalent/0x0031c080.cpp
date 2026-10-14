// STATUS: equivalent (tools/equiv.py level 3: 94 inputs, branch coverage 14/14)
// pure3d::d3dPrimStream::vfunc_1 @ 0x0031c080
typedef unsigned long DWORD;
namespace D3D8 {
void __stdcall D3DDevice_SetVertexShader(DWORD);
void __stdcall D3DDevice_SetStreamSource(DWORD, void*, DWORD);
void __stdcall D3DDevice_DrawVertices(DWORD, DWORD, DWORD);
}
struct ShaderInfo_31c080 {
    char pad[0x14];
    DWORD handle;
};
struct PrimTypeInfo {
    int mul;
    int add;
};
extern PrimTypeInfo DAT_003f3260[];
extern int DAT_004d367c;
// equiv-conv: FUN_0031bc30 eax ecx
int FUN_0031bc30(int shapeKind, int count);
void FUN_0031c230(long hr);
namespace pure3d {
class d3dBasePrimStream {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
class d3dPrimStream : public d3dBasePrimStream {
  public:
    DWORD stride;
    char pad8[0x1c - 8];
    int vertCount;
    char pad20[0x12c - 0x20];
    void** buffers;
    void* curBuffer;
    char flag134;
    char pad135[0x138 - 0x134 - 1];
    int primType;
    int shapeKind;
    char pad140[0x144 - 0x140];
    int bufIndex;
    char pad148[0x158 - 0x148];
    ShaderInfo_31c080* shader;
    int pending;
    virtual void vfunc_0();
    virtual void vfunc_1();
};
}
void pure3d::d3dPrimStream::vfunc_1() {
    if (flag134)
        flag134 = 0;
    if (vertCount > 0 && !(primType == 6 && vertCount <= 2) && !(primType == 4 && vertCount <= 1)) {
        D3D8::D3DDevice_SetVertexShader(shader->handle);
        D3D8::D3DDevice_SetStreamSource(0, curBuffer, stride);
        int prim = primType;
        int n = FUN_0031bc30(shapeKind, vertCount);
        D3D8::D3DDevice_DrawVertices(prim, 0, n * DAT_003f3260[prim].mul + DAT_003f3260[prim].add);
        FUN_0031c230(0);
        bufIndex++;
        if (bufIndex == DAT_004d367c)
            bufIndex = 0;
        curBuffer = buffers[bufIndex];
        int cnt = vertCount;
        vertCount = 0;
        pending -= cnt;
        return;
    }
    pending -= vertCount;
    vertCount = 0;
}
