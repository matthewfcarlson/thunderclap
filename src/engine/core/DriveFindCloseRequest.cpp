// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00274860..0x002749a0 (kind game, layer engine, confidence high), dominant class core::DriveFindCloseRequest
#include "tree_prelude.h"
#include "decls/instance_drive.h"
#include "compat/ptr.h"
#include "gen/core.h"
#define TREE_TU_BEGIN namespace fn_ffa549b9 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_ffa549b9 {} using namespace fn_ffa549b9;
#include "engine/core.h"

// ---- declarations shared by the functions below
namespace fn_ffa549b9 {
class Drive {
  public:
    virtual void A();
    virtual void B();
};
class DriveSub {
  public:
    virtual void A();
    virtual void B();
};
class DriveRequest_274860 {
  public:
    hulk_intptr vf;
    char pad[4];
    HulkInstanceDrive* drive;   // (x64t10) decls/instance_drive.h
    void Run();
};
class Obj_2748a0 {
  public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual int call19(void*, int);
    int* Fetch_00272880();
};
class Sub_2748a0 {
  public:
    virtual void a();
    virtual void b();
};
struct Drive_2748a0 {
    char p0[4];
    Sub_2748a0 sub;
    char p1[4];
    Obj_2748a0* obj;
    char p2[8];
    hulk_intptr result;
    char p3[4];
};
class V {
  public:
    virtual void A();
    virtual void B();
};
class Obj_274900 {
  public:
    char pad[4];
    void* sub;   // (x64t10) the lock's vftable word: a member object's virtual call is direct natively
    char rest[0x10];
    int count;
};
class Service_274940 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j();
    virtual void k();
    virtual void l();
    virtual void m();
    virtual void n();
    virtual void o();
    virtual void p();
    virtual void q();
    virtual void r();
    virtual void s();
    virtual void t();
    virtual void u(void*);
};
class Inner_274940 {
  public:
    virtual void close();
    virtual void done();
};
struct Drive_274940 {
    virtual void v0();
    char pad[8];
    Service_274940* service;
    char pad2[0x10];
    unsigned char flag;
};
class pddiObject_274980 {
  public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
};
class pddiShader_274980 : public pddiObject_274980 {};
class pddiBaseShader_274980 : public pddiShader_274980 {
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
class d3dShader_274980 : public pddiBaseShader_274980 {
  public:
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc21();
};


// 0x00274860 FUN_00274860 (53 B): matches/0x00274860.cpp
// sym: ?Run@DriveRequest_274860@fn_ffa549b9@@QAEXXZ
void DriveRequest_274860::Run() {
    vf = ((hulk_intptr)DAT_0042b9bc);
    ((DriveSub*)&drive->mutableVftable)->A();
    --drive->pending;
    ((DriveSub*)&drive->mutableVftable)->B();
    ((Drive*)drive)->B();
    vf = ((hulk_intptr)DAT_0042b914);
}

} // namespace fn_ffa549b9

// 0x002748a0 core::DriveFindNextRequest::vfunc_1 (72 B): matches/0x002748a0.cpp
// sym: ?vfunc_1@DriveFindNextRequest@core@@UAEHXZ
int core::DriveFindNextRequest::vfunc_1() {
    // (x64t10) the InstanceDrive's words (decls/instance_drive.h): the drive, the find handle, the status
    Obj_2748a0* o = (Obj_2748a0*)(*(HulkInstanceDrive * *)&this->f_08)->source;
    int r = o->call19((char*)&(*(HulkInstanceDrive * *)&this->f_08)->handle, this->f_0c);
    int v = (int)(hulk_intptr)o->Fetch_00272880();
    ((Sub_2748a0*)&(*(HulkInstanceDrive * *)&this->f_08)->mutableVftable)->a();
    (*(HulkInstanceDrive * *)&this->f_08)->status = v;
    ((Sub_2748a0*)&(*(HulkInstanceDrive * *)&this->f_08)->mutableVftable)->b();
    return r;
}


// 0x002748f0 core::DriveFindNextRequest::vfunc_6 (6 B): matches/0x002748f0.cpp
// sym: ?vfunc_6@DriveFindNextRequest@core@@UAEHXZ
int core::DriveFindNextRequest::vfunc_6() {
    return (int)(0x11);
}


// 0x00274900 FUN_00274900 (53 B): matches/0x00274900.cpp
// sym: ?FUN_00274900@DriveRequest@core@@QAEXXZ
void core::DriveRequest::FUN_00274900() {
    Obj_274900* p = (*(Obj_274900 * *)&this->f_08);
    *(hulk_ulongptr*)this = ((hulk_intptr)DAT_0042b9bc);
    ((V*)&p->sub)->A();
    --((HulkInstanceDrive*)(*(Obj_274900 * *)&this->f_08))->pending;   // (x64t10) decls/instance_drive.h
    p = (*(Obj_274900 * *)&this->f_08);
    ((V*)&p->sub)->B();
    p = (*(Obj_274900 * *)&this->f_08);
    ((V*)p)->B();
    *(hulk_ulongptr*)this = ((hulk_intptr)DAT_0042b914);
}


// 0x00274940 core::DriveFindCloseRequest::vfunc_1 (64 B): matches/0x00274940.cpp
// sym: ?vfunc_1@DriveFindCloseRequest@core@@UAEHXZ
int core::DriveFindCloseRequest::vfunc_1() {
    // (x64t10) the InstanceDrive's words (decls/instance_drive.h): the drive, the find flag and handle, the status
    HulkInstanceDrive* d = (*(HulkInstanceDrive *volatile *)&this->f_08);
    Service_274940* s = (Service_274940*)d->source;
    d->active = 0;
    s->u(&(*(HulkInstanceDrive *volatile *)&this->f_08)->handle);
    ((Inner_274940*)&(*(HulkInstanceDrive *volatile *)&this->f_08)->mutableVftable)->close();
    (*(HulkInstanceDrive *volatile *)&this->f_08)->status = 0;
    ((Inner_274940*)&(*(HulkInstanceDrive *volatile *)&this->f_08)->mutableVftable)->done();
    return 1;
}


// 0x00274980 core::DriveFindCloseRequest::vfunc_4 (6 B): matches/0x00274980.cpp
// sym: ?vfunc_4@DriveFindCloseRequest@core@@UAEHXZ
// Same code shape as 0x0032d960 (propagated; names are from that function)
int core::DriveFindCloseRequest::vfunc_4() {
    return 1;
}


// 0x00274990 core::DriveFindCloseRequest::vfunc_6 (6 B): matches/0x00274990.cpp
// sym: ?vfunc_6@DriveFindCloseRequest@core@@UAEHXZ
int core::DriveFindCloseRequest::vfunc_6() {
    return (int)(0x12);
}

