// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 6/6)
// FUN_0031bfa0 @ 0x0031bfa0
namespace D3D8 {
int __stdcall D3DDevice_CreateVertexBuffer2(int);
}
extern void* __cdecl FUN_0008d690(int);
extern void __cdecl FUN_0031c230(int);
extern int DAT_004d367c;
extern int DAT_004d3678;
struct OwnerInner {
    char pad[0x10];
    int value;
};
struct Owner_31bfa0 {
    char pad[0x154];
    OwnerInner* inner;
};
namespace pure3d {
class d3dPrimStream {
  public:
    d3dPrimStream(Owner_31bfa0* owner) throw();
    virtual void v0();
    int f4, f8, fc, f10, f14;
    char pad18[4];
    int f1c;
    char pad20[0x124 - 0x20];
    Owner_31bfa0* owner;
    int f128;
    int* buffers;
    int current;
    char f134;
    char pad135[0x140 - 0x135];
    int f140;
    int f144;
    char pad148[0x154 - 0x148];
    int f154;
};
d3dPrimStream::d3dPrimStream(Owner_31bfa0* o) throw() {
    owner = o;
    f128 = 0;
    f134 = 0;
    f1c = 0;
    f4 = 0;
    f8 = 0;
    fc = 0;
    f10 = 0;
    f14 = 0;
    f154 = 0;
    f128 = o->inner->value;
    f144 = 0;
    buffers = (int*)FUN_0008d690(DAT_004d367c * 4);
    for (int i = 0; i < DAT_004d367c; i++) {
        int* slot = &buffers[i];
        int vb = D3D8::D3DDevice_CreateVertexBuffer2(DAT_004d3678);
        *slot = vb;
        FUN_0031c230((vb != 0) - 1 & 0x8007000e);
    }
    f140 = 0;
    current = buffers[f144];
}
}
