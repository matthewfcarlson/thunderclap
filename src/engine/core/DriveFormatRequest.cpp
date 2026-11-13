// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00274590..0x00274630 (kind game, layer engine, confidence high), dominant class core::DriveFormatRequest
#include "tree_prelude.h"
#include "decls/instance_drive.h"
#include "compat/ptr.h"
#include "gen/core.h"
#define TREE_TU_BEGIN namespace fn_ff492841 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_ff492841 {} using namespace fn_ff492841;
#include "engine/core.h"

// ---- declarations shared by the functions below
namespace fn_ff492841 {
class V {
  public:
    virtual void A();
    virtual void B();
};
class Obj_274590 {
  public:
    char pad[4];
    void* sub;   // (x64t10) the lock's vftable word: a member object's virtual call is direct natively
    char rest[0x10];
    int count;
};
class Req_2745d0 {
  public:
    virtual void v0();
    virtual void v1();
};
class Dev_2745d0 {
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
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual unsigned g();
    unsigned MakeValue_00272880();
};
struct Ctx_2745d0 {
    char pad0[4];
    void* sub;   // (x64t10) the lock's vftable word: a member object's virtual call is direct natively
    char pad1[4];
    Dev_2745d0* dev;
    char pad2[8];
    unsigned value;
};
class DriveRequest_274610 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
class pddiObject_274620 {
  public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
};
class pddiShader_274620 : public pddiObject_274620 {};
class pddiBaseShader_274620 : public pddiShader_274620 {
  public:
    virtual void vfunc5();
    virtual void vfunc6();
    virtual void vfunc7();
    virtual void vfunc8();
    virtual void vfunc9();
    virtual void vfunc10();
    virtual int UsesLayeredTexture();
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc19();
    virtual void vfunc20();
};
class d3dShader_274620 : public pddiBaseShader_274620 {
  public:
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc21();
};

} // namespace fn_ff492841

// 0x00274590 FUN_00274590 (53 B): matches/0x00274590.cpp
// sym: ?FUN_00274590@DriveRequest@core@@QAEXXZ
void core::DriveRequest::FUN_00274590() {
    Obj_274590* p = (*(Obj_274590 * *)&this->f_08);
    *(hulk_ulongptr*)this = ((hulk_intptr)DAT_0042b9bc);
    ((V*)&p->sub)->A();
    --((HulkInstanceDrive*)(*(Obj_274590 * *)&this->f_08))->pending;   // (x64t10) decls/instance_drive.h
    p = (*(Obj_274590 * *)&this->f_08);
    ((V*)&p->sub)->B();
    p = (*(Obj_274590 * *)&this->f_08);
    ((V*)p)->B();
    *(hulk_ulongptr*)this = ((hulk_intptr)DAT_0042b914);
}


// 0x002745d0 core::DriveFormatRequest::vfunc_1 (63 B): matches/0x002745d0.cpp
// sym: ?vfunc_1@DriveFormatRequest@core@@UAEHXZ
int core::DriveFormatRequest::vfunc_1() {
    Dev_2745d0* d = (*(Ctx_2745d0 * *)&this->f_08)->dev;
    unsigned x = d->g();
    unsigned y = d->MakeValue_00272880();
    ((Req_2745d0*)&(*(Ctx_2745d0 * *)&this->f_08)->sub)->v0();
    (*(Ctx_2745d0 * *)&this->f_08)->value = y;
    ((Req_2745d0*)&(*(Ctx_2745d0 * *)&this->f_08)->sub)->v1();
    return (int)(x);
}


// 0x00274610 core::DriveFormatRequest::vfunc_6 (6 B): matches/0x00274610.cpp
// sym: ?vfunc_6@DriveFormatRequest@core@@UAEHXZ
int core::DriveFormatRequest::vfunc_6() {
    return 0xd;
}


// 0x00274620 core::DriveFormatRequest::vfunc_4 (6 B): matches/0x00274620.cpp
// sym: ?vfunc_4@DriveFormatRequest@core@@UAEHXZ
// Same code shape as 0x0032d960 (propagated; names are from that function)
int core::DriveFormatRequest::vfunc_4() {
    return 1;
}

