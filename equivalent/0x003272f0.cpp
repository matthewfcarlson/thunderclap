// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 10/10)
// FUN_003272f0 @ 0x003272f0
#include "decls/data/platform/xbox/pure3d.h"

typedef unsigned long DWORD;
namespace D3D8 {
void __stdcall D3DDevice_SetIndices(DWORD, DWORD);
void __stdcall D3DDevice_SetVertexShader(DWORD);
void __stdcall D3DDevice_SetStreamSource(DWORD, DWORD, DWORD);
void __stdcall D3DDevice_DrawIndexedVertices(DWORD, DWORD, const void*);
void __stdcall D3DDevice_DrawVertices(DWORD, DWORD, DWORD);
}
struct PrimInfo {
    int mul;
    int add;
};
struct VertexFormat_3272f0 {
    char pad[0x10];
    DWORD stride;
    DWORD shader;
};
extern const void* DAT_0039db04;
// equiv-conv: FUN_00326dc0 eax ecx
int FUN_00326dc0(int primType, int count);
void FUN_0031c230(int);
struct MeshBatch {
    char pad[0x10];
    int primType;
    int primKind;
    char pad1[4];
    int vertexCount;
    char pad2[0x24 - 0x20];
    int indexCount;
    int overrideCount;
    DWORD indexBuffer;
    DWORD vertexBuffer;
    char pad3[0x3c - 0x34];
    VertexFormat_3272f0* format;
    void Draw();
};
void MeshBatch::Draw() {
    int saved;
    if (overrideCount != 0) {
        if (indexCount > 0) {
            saved = indexCount;
            indexCount = overrideCount;
        } else {
            saved = vertexCount;
            vertexCount = overrideCount;
        }
    }
    if (indexCount > 0) {
        D3D8::D3DDevice_SetIndices(indexBuffer, 0);
        D3D8::D3DDevice_SetVertexShader(format->shader);
        D3D8::D3DDevice_SetStreamSource(0, vertexBuffer, format->stride);
        int type = primType;
        int n = FUN_00326dc0(primKind, indexCount);
        D3D8::D3DDevice_DrawIndexedVertices(type, n * ((PrimInfo*)&DAT_003f3260)[type].mul + ((PrimInfo*)&DAT_003f3260)[type].add, DAT_0039db04);
    } else {
        D3D8::D3DDevice_SetVertexShader(format->shader);
        D3D8::D3DDevice_SetStreamSource(0, vertexBuffer, format->stride);
        int type = primType;
        int n = FUN_00326dc0(primKind, vertexCount);
        D3D8::D3DDevice_DrawVertices(type, 0, n * ((PrimInfo*)&DAT_003f3260)[type].mul + ((PrimInfo*)&DAT_003f3260)[type].add);
    }
    FUN_0031c230(0);
    if (overrideCount != 0) {
        if (indexCount > 0)
            indexCount = saved;
        else
            vertexCount = saved;
    }
}
