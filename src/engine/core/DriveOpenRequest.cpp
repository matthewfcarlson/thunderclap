// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00274440..0x002744e0 (kind game, layer engine, confidence high), dominant class core::DriveOpenRequest
#include "tree_prelude.h"
#include "decls/instance_drive.h"
#include "compat/ptr.h"
#include "gen/core.h"
#define TREE_TU_BEGIN namespace fn_fab94264 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fab94264 {} using namespace fn_fab94264;
#include "engine/core.h"

// ---- declarations shared by the functions below
namespace fn_fab94264 {
class V {
  public:
    virtual void A();
    virtual void B();
};
class Obj_274440 {
  public:
    char pad[4];
    void* sub;   // (x64t10) the lock's vftable word: a member object's virtual call is direct natively
    char rest[0x10];
    int count;
};
class D {
  public:
    virtual int s0();
    virtual int s1();
    virtual int s2();
    virtual int s3();
    virtual int s4();
    virtual int s5();
    virtual int s6();
    virtual int s7();
    int Helper_00272880();
};
class Q_274480 {
  public:
    virtual void s0();
    virtual void s1();
};
class P_274480 {
  public:
    int pad0;
    void* q;   // (x64t10) the lock's vftable word (a member object's virtual call is direct natively)
    int pad8;
    D* d;
    int pad10;
    int pad14;
    int f18;
};
class pddiObject_2744c0 {
  public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
};
class pddiShader_2744c0 : public pddiObject_2744c0 {};
class pddiBaseShader_2744c0 : public pddiShader_2744c0 {
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
class d3dShader_2744c0 : public pddiBaseShader_2744c0 {
  public:
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc21();
};
class ParamValue_2744d0 {
  public:
    virtual void f0();
    virtual int f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};

} // namespace fn_fab94264

// 0x00274440 FUN_00274440 (53 B): matches/0x00274440.cpp
// sym: ?FUN_00274440@DriveRequest@core@@QAEXXZ
void core::DriveRequest::FUN_00274440() {
    Obj_274440* p = (*(Obj_274440 * *)&this->f_08);
    *(hulk_ulongptr*)this = ((hulk_intptr)DAT_0042b9bc);
    ((V*)&p->sub)->A();
    --((HulkInstanceDrive*)(*(Obj_274440 * *)&this->f_08))->pending;   // (x64t10) decls/instance_drive.h
    p = (*(Obj_274440 * *)&this->f_08);
    ((V*)&p->sub)->B();
    p = (*(Obj_274440 * *)&this->f_08);
    ((V*)p)->B();
    *(hulk_ulongptr*)this = ((hulk_intptr)DAT_0042b914);
}


// 0x00274480 core::DriveOpenRequest::vfunc_1 (63 B): matches/0x00274480.cpp
// sym: ?vfunc_1@DriveOpenRequest@core@@UAEHXZ
// Same code shape as 0x002743f0 (propagated; names are from that function)
int core::DriveOpenRequest::vfunc_1() {
    D* d = (*(P_274480 * *)&this->f_08)->d;
    int a = d->s7();
    int b = d->Helper_00272880();
    ((Q_274480*)&(*(P_274480 * *)&this->f_08)->q)->s0();
    (*(P_274480 * *)&this->f_08)->f18 = b;
    ((Q_274480*)&(*(P_274480 * *)&this->f_08)->q)->s1();
    return a;
}


// 0x002744c0 core::DriveOpenRequest::vfunc_4 (6 B): matches/0x002744c0.cpp
// sym: ?vfunc_4@DriveOpenRequest@core@@UAEHXZ
// Same code shape as 0x0032d960 (propagated; names are from that function)
int core::DriveOpenRequest::vfunc_4() {
    return 1;
}


// 0x002744d0 core::DriveOpenRequest::vfunc_6 (6 B): matches/0x002744d0.cpp
// sym: ?vfunc_6@DriveOpenRequest@core@@UAEHXZ
// Same code shape as 0x0005bd60 (propagated; names are from that function)
int core::DriveOpenRequest::vfunc_6() {
    return 11;
}

