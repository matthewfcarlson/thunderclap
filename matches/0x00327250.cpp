#include "compat/ptr.h"
typedef unsigned char uchar;
extern void* __stdcall D3DVertexBuffer_Lock2(void*, int);
extern void __cdecl FUN_0031c230(int);
class d3dPrimBuffer {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void vfunc_11();
    char pad[0x2c];
    void* buffer;
    char pad2[2];
    uchar locked;
    unsigned int target(int arg);
};
unsigned int d3dPrimBuffer::target(int arg) {
    void* p = D3DVertexBuffer_Lock2(buffer, 0);
    FUN_0031c230(0);
    locked = 1;
    return (hulk_uintptr)p;
}