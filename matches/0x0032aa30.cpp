#include "gen/pure3d.h"
typedef unsigned char u8_32aa30;
struct Ref_32aa30 {
    virtual void f0();
    virtual void f1();
};
struct d3dSimpleShader_nv_32aa30 {
    void run();
};
extern void thunk_FUN_00267090(void*);
extern "C" char DAT_0043386c[];
struct pure3d_d3dSimpleShader_32aa30 {
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual pure3d_d3dSimpleShader_32aa30* vfunc_3(u8_32aa30);
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
    Ref_32aa30* member;
};
pure3d_d3dSimpleShader_32aa30* pure3d_d3dSimpleShader_32aa30::vfunc_3(u8_32aa30 destroy) {
    *(int**)this = (int*)DAT_0043386c;
    if (member)
        member->f1();
    ((d3dSimpleShader_nv_32aa30*)(((pure3d::d3dSimpleShader*)this)))->run();
    if (destroy & 1)
        thunk_FUN_00267090(this);
    return this;
}