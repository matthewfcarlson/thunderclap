// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 3/4, incomplete)
// pure3d::d3dPrimBuffer::vfunc_4 @ 0x00327190
namespace D3D8 { int __stdcall D3DVertexBuffer_Lock2(void* buffer, int flags); }
void __cdecl FUN_0031c230(int);
struct Record {
    int header;
    unsigned char active;
    char remaining[0x4f];
    void FUN_00326e90(int data, int value, int count, int flags);
};
extern Record DAT_004d3ed0[4];
namespace pure3d {
struct d3dPrimBuffer {
    char padding0[0x1c];
    int count;
    char padding20[0x10];
    void* buffer;
    unsigned char locked;
    char padding35[7];
    int value;
    Record* vfunc_4();
};
Record* d3dPrimBuffer::vfunc_4() {
    int data = D3D8::D3DVertexBuffer_Lock2(buffer, 0);
    FUN_0031c230(0);
    locked = 1;
    Record* available = 0;
    for (int i = 0; i < 4; ++i) {
        if (!DAT_004d3ed0[i].active) {
            available = &DAT_004d3ed0[i];
            break;
        }
    }
    available->active = 1;
    available->FUN_00326e90(data, value, count, 0);
    return available;
}
}
