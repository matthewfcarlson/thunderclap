// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 4/4)
// FUN_003270c0 @ 0x003270c0
struct VertexFormat { char pad[0x10]; int stride; };
struct BufferOwner { char pad0[0x1c]; int count; char pad1[0x10]; void *buffer; char pad2[8]; VertexFormat *format; void FUN_003270c0(int n); };
namespace D3D8 { void __stdcall D3DResource_Release(void *); void * __stdcall D3DDevice_CreateVertexBuffer2(int); }
void __cdecl FUN_0031e210(void *);
void __cdecl FUN_0031e1f0(void *,int);
void __cdecl FUN_0031c230(int);
void BufferOwner::FUN_003270c0(int n) {
    count = n;
    if (buffer) {
        D3D8::D3DResource_Release(buffer);
        FUN_0031e210(buffer);
    }
    buffer = D3D8::D3DDevice_CreateVertexBuffer2(format->stride * count);
    int result = buffer ? 0 : 0x8007000e;
    FUN_0031e1f0(buffer, format->stride * count);
    FUN_0031c230(result);
}