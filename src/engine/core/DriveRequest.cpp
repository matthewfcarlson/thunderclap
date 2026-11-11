// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00274350..0x00274440 (kind game, layer engine, confidence high), dominant class core::DriveRequest
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/core.h"
#define TREE_TU_BEGIN namespace fn_fad045c4 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fad045c4 {} using namespace fn_fad045c4;
#include "engine/core.h"

// ---- declarations shared by the functions below
namespace fn_fad045c4 {
class V {
  public:
    virtual void A();
    virtual void B();
};
class Obj_274350 {
  public:
    char pad[4];
    V sub;
    char rest[0x10];
    int count;
};
class Sub_274390 {
  public:
    virtual void A();
    virtual void B();
};
struct Container_274390 {
    char pad[4];
    Sub_274390 sub;
    char pad2[0x10];
    unsigned int value;
};
class Outer_274390 {
  public:
    char pad[8];
    Container_274390* obj;
    unsigned int target(unsigned int a, unsigned int b);
};
class Request_2743c0 {
  public:
    char pad[8];
    int field;
};
struct Owner_2743e0 {
    const void* vftable;
    const void* vftableMutable;
    int refs;
    void* drive;
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
    int Helper();
};
class Q_2743f0 {
  public:
    virtual void s0();
    virtual void s1();
};
class P_2743f0 {
  public:
    int pad0;
    Q_2743f0 q;
    int pad8;
    D* d;
    int pad10;
    int pad14;
    int f18;
};

} // namespace fn_fad045c4

// 0x00274350 FUN_00274350 (53 B): matches/0x00274350.cpp
// sym: ?FUN_00274350@DriveRequest@core@@QAEXXZ
void core::DriveRequest::FUN_00274350() {
    Obj_274350* p = (*(Obj_274350 * *)&this->f_08);
    *(hulk_ulongptr*)this = ((hulk_intptr)DAT_0042b9bc);
    p->sub.A();
    --(*(int*)((char*)(*(Obj_274350 * *)&this->f_08) + 0x14));
    p = (*(Obj_274350 * *)&this->f_08);
    p->sub.B();
    p = (*(Obj_274350 * *)&this->f_08);
    ((V*)p)->B();
    *(hulk_ulongptr*)this = ((hulk_intptr)DAT_0042b914);
}

namespace fn_fad045c4 {

// 0x00274390 FUN_00274390 (43 B): matches/0x00274390.cpp
// sym: ?target@Outer_274390@fn_fad045c4@@QAEIII@Z
unsigned int Outer_274390::target(unsigned int a, unsigned int b) {
    obj->sub.A();
    obj->value = b;
    obj->sub.B();
    return a;
}

} // namespace fn_fad045c4

// 0x002743c0 core::DriveRequest::vfunc_2 (19 B): matches/0x002743c0.cpp
// sym: ?vfunc_2@DriveRequest@core@@UAE_NH@Z
// Same code shape as 0x00273860 (propagated; names are from that function)
bool core::DriveRequest::vfunc_2(int value) {
    return value == (*(int *)&this->f_08);
}


// 0x002743e0 core::DriveRequest::vfunc_3 (7 B): matches/0x002743e0.cpp
// sym: ?vfunc_3@DriveRequest@core@@UAEHXZ
// the request's drive: the drive of the object it works on (an instance drive or a file: their +0xc word, after
// two vftables and the reference count)
hulk_intptr core::DriveRequest::vfunc_3() {
    return (hulk_intptr)((Owner_2743e0*)this->f_08)->drive;
}


// 0x002743f0 core::DriveRequest::vfunc_4 (63 B): matches/0x002743f0.cpp
// sym: ?vfunc_4@DriveRequest@core@@UAEHXZ
int core::DriveRequest::vfunc_4() {
    D* d = (*(P_2743f0 * *)&this->f_08)->d;
    int a = d->s7();
    int b = d->Helper();
    (*(P_2743f0 * *)&this->f_08)->q.s0();
    (*(P_2743f0 * *)&this->f_08)->f18 = b;
    (*(P_2743f0 * *)&this->f_08)->q.s1();
    return a;
}

namespace fn_fad045c4 {

// 0x00274430 core::DriveRequest::vfunc_5 (3 B): matches/0x00274430.cpp
// sym: ?GetZero@fn_fad045c4@@YAIXZ
// Same code shape as 0x0026ef40 (propagated; names are from that function)
unsigned int GetZero() {
    return 0;
}

} // namespace fn_fad045c4
