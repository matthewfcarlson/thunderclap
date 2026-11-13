// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00274a50..0x00274af0 (kind game, layer engine, confidence high), dominant class core::DriveCancelRequest
#include "tree_prelude.h"
#include "decls/instance_drive.h"
#include "compat/ptr.h"
#include "gen/core.h"
#define TREE_TU_BEGIN namespace fn_f0858443 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f0858443 {} using namespace fn_f0858443;
#include "engine/core.h"

// ---- declarations shared by the functions below
namespace fn_f0858443 {
class V {
  public:
    virtual void A();
    virtual void B();
};
class Obj_274a50 {
  public:
    char pad[4];
    void* sub;   // (x64t10) the lock's vftable word: a member object's virtual call is direct natively
    char rest[0x10];
    int count;
};
class I_274a90 {
  public:
    virtual void f0();
    virtual void f1();
};
class M_274a90 {
  public:
    int dummy;
    void Call_00272b70(void* a, int b);
};
class P_274a90 {
  public:
    char pad0[4];
    void* sub;   // (x64t10) the lock's vftable word: a member object's virtual call is direct natively
    char pad8[4];
    M_274a90* obj;
    int x10;
    char pad14[4];
    int zero;
};
class pddiObject_274ad0 {
  public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
};
class pddiShader_274ad0 : public pddiObject_274ad0 {};
class pddiBaseShader_274ad0 : public pddiShader_274ad0 {
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
class d3dShader_274ad0 : public pddiBaseShader_274ad0 {
  public:
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc21();
};
class DriveRequest_274ae0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual int v6();
};

} // namespace fn_f0858443

// 0x00274a50 FUN_00274a50 (53 B): matches/0x00274a50.cpp
// sym: ?FUN_00274a50@DriveRequest@core@@QAEXXZ
void core::DriveRequest::FUN_00274a50() {
    Obj_274a50* p = (*(Obj_274a50 * *)&this->f_08);
    *(hulk_ulongptr*)this = ((hulk_intptr)DAT_0042b9bc);
    ((V*)&p->sub)->A();
    --((HulkInstanceDrive*)(*(Obj_274a50 * *)&this->f_08))->pending;   // (x64t10) decls/instance_drive.h
    p = (*(Obj_274a50 * *)&this->f_08);
    ((V*)&p->sub)->B();
    p = (*(Obj_274a50 * *)&this->f_08);
    ((V*)p)->B();
    *(hulk_ulongptr*)this = ((hulk_intptr)DAT_0042b914);
}


// 0x00274a90 core::DriveCancelRequest::vfunc_1 (59 B): matches/0x00274a90.cpp
// sym: ?vfunc_1@DriveCancelRequest@core@@UAEHXZ
int core::DriveCancelRequest::vfunc_1() {
    (*(P_274a90 * *)&this->f_08)->obj->Call_00272b70((*(P_274a90 * *)&this->f_08), (*(P_274a90 * *)&this->f_08)->x10);
    ((I_274a90*)&(*(P_274a90 * *)&this->f_08)->sub)->f0();
    (*(P_274a90 * *)&this->f_08)->zero = 0;
    ((I_274a90*)&(*(P_274a90 * *)&this->f_08)->sub)->f1();
    return 1;
}


// 0x00274ad0 core::DriveCancelRequest::vfunc_4 (6 B): matches/0x00274ad0.cpp
// sym: ?vfunc_4@DriveCancelRequest@core@@UAEHXZ
// Same code shape as 0x0032d960 (propagated; names are from that function)
int core::DriveCancelRequest::vfunc_4() {
    return 1;
}


// 0x00274ae0 core::DriveCancelRequest::vfunc_6 (6 B): matches/0x00274ae0.cpp
// sym: ?vfunc_6@DriveCancelRequest@core@@UAEHXZ
int core::DriveCancelRequest::vfunc_6() {
    return 0x14;
}

