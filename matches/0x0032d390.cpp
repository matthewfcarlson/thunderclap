// Same code shape as 0x0032aa30 (propagated; names are from that function)
#include "gen/pure3d.h"
typedef unsigned char u8_32d390;
struct Ref_32d390 {
    virtual void f0();
    virtual void f1();
};
struct d3dPointSpriteShader_nv_32d390 {
    void run();
};
extern void thunk_FUN_00267090(void*);
extern "C" char DAT_00433b14[];
struct d3dPointSpriteShader_32d390 {
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual d3dPointSpriteShader_32d390* vfunc_3(u8_32d390);
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual void a14();
    virtual void a15();
    virtual void a16();
    virtual void a17();
    virtual void a18();
    virtual void a19();
    virtual void a20();
    virtual void a21();
    virtual void a22();
    virtual void a23();
    virtual void a24();
    char pad[0x80 - sizeof(void*)];
    Ref_32d390* member;
};
d3dPointSpriteShader_32d390* d3dPointSpriteShader_32d390::vfunc_3(u8_32d390 destroy) {
    *(int**)this = (int*)DAT_00433b14;
    if (member)
        member->f1();
    ((d3dPointSpriteShader_nv_32d390*)(((pure3d::d3dPointSpriteShader*)(((pure3d::d3dPointSpriteShader*)this)))))->run();
    if (destroy & 1)
        thunk_FUN_00267090(this);
    return this;
}