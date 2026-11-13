// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00274790..0x00274860 (kind game, layer engine, confidence high), dominant class core::DriveFindFirstRequest
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/core.h"
#define TREE_TU_BEGIN namespace fn_f6660075 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f6660075 {} using namespace fn_f6660075;
#include "engine/core.h"

// ---- declarations shared by the functions below
namespace fn_f6660075 {
class V {
  public:
    virtual void A();
    virtual void B();
};
class Inner_274790 {
  public:
    virtual void X();
    virtual void Y();
    V obj;
    int x[3];
    int refs;
};
class DriveRequest_274790 : public core::Request {
  public:
    char p[4];
    Inner_274790* sub;
    void Cleanup();
};
class HalStream_274840 {
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
};


// 0x00274790 FUN_00274790 (53 B): matches/0x00274790.cpp
// sym: ?Cleanup@DriveRequest_274790@fn_f6660075@@QAEXXZ
void DriveRequest_274790::Cleanup() {
    *(hulk_intptr*)this = ((hulk_intptr)DAT_0042b9bc);
    sub->obj.A();
    --sub->refs;
    sub->obj.B();
    sub->Y();
    *(hulk_intptr*)this = ((hulk_intptr)DAT_0042b914);
}

} // namespace fn_f6660075

// 0x002747d0 core::DriveFindFirstRequest::vfunc_1 (111 B): equivalent/0x002747d0.cpp [wrapped: conflict: core::Drive; core::DriveFindFirstRequest]
// sym: ?vfunc_1@DriveFindFirstRequest@core@fn_002747d0@@UAEHXZ @b0e3af88f1f3 @wdcb231391aa0
namespace fn_002747d0 {
// STATUS: equivalent (tools/equiv.py level 3: 19866 inputs, branch coverage 4/4)
// core::DriveFindFirstRequest::vfunc_1 @ 0x002747d0
namespace core {
struct Lock_2747d0 { virtual void lock(); virtual void unlock(); };
struct Drive {
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17();
 virtual int find(void*, unsigned int, unsigned int*, bool);
 unsigned int FUN_00272880();
};
struct State_2747d0 { unsigned int unk; Lock_2747d0 lock; unsigned int unk8; Drive* drive; char pad[8]; unsigned int result; unsigned int handle; unsigned char active; };
struct DriveFindFirstRequest {
 virtual void vfunc_0(); virtual int vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6();
 unsigned int unk4; State_2747d0* state; char buffer[0x104]; unsigned int flags;
};
int DriveFindFirstRequest::vfunc_1() {
 Drive* drive = state->drive;
 int result = drive->find(buffer, flags, &state->handle, state->active == 0);
 state->active = result == 1 ? 1 : 0;
 unsigned int status = drive->FUN_00272880();
 (&state->lock)->lock();
 state->result = status;
 (&state->lock)->unlock();
 return result;
}
}
} // namespace fn_002747d0


// 0x00274840 core::DriveFindFirstRequest::vfunc_5 (4 B): matches/0x00274840.cpp
// sym: ?vfunc_5@DriveFindFirstRequest@core@@UAEPAXXZ
// Same code shape as 0x0025c0b0 (propagated; names are from that function)
 // namespace audio
void* core::DriveFindFirstRequest::vfunc_5() {
    return (void*)((core::DriveFindFirstRequest*)((char*)&this->f_0c));
}


// 0x00274850 core::DriveFindFirstRequest::vfunc_6 (6 B): matches/0x00274850.cpp
// sym: ?vfunc_6@DriveFindFirstRequest@core@@UAEHXZ
int core::DriveFindFirstRequest::vfunc_6() {
    return (int)(0x10);
}

