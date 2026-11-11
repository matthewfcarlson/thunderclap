// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00275c80..0x00275d20 (kind game, layer engine, confidence medium), dominant class core::DriveCancelRequest
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/core.h"
#define TREE_TU_BEGIN namespace fn_f241e4e6 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f241e4e6 {} using namespace fn_f241e4e6;
#include "engine/core.h"

// ---- declarations shared by the functions below
namespace fn_f241e4e6 {
extern "C" char DAT_0042bc80[];
class DriveCancelRequest {
  public:
    hulk_intptr value;
    DriveCancelRequest(hulk_intptr);
    void Init_00275600(int);
};
extern void Helper_002705f0();
struct Lock_275ca0 {
    virtual void lock();
    virtual void unlock();
};
struct Drive {
    virtual void slot0();
    virtual void release();
    Lock_275ca0 guard;
    char pad[12];
    int count;
};
struct Alloc_275ca0 {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void free(void*);
};
namespace core {
struct Request {
    virtual void vfunc_0();
};
}
namespace core {
struct DriveRequest : Request {
    int field4;
    Drive* drive;
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3_002743e0();
    virtual void vfunc_4_002743f0();
    virtual void vfunc_5();
    virtual void vfunc_6();
    DriveRequest(unsigned flags);
};
}


// 0x00275c80 FUN_00275c80 (30 B): matches/0x00275c80.cpp
// sym: ??0DriveCancelRequest@fn_f241e4e6@@QAE@H@Z
DriveCancelRequest::DriveCancelRequest(hulk_intptr arg) {
    Init_00275600(arg);
    value = ((hulk_intptr)DAT_0042bc80);
    Helper_002705f0();
}


// 0x00275ca0 core::DriveCancelRequest::vfunc_0 (102 B): matches/0x00275ca0.cpp
// sym: ??0DriveRequest@core@fn_f241e4e6@@QAE@I@Z
namespace core {
DriveRequest::DriveRequest(unsigned flags) {
    drive->guard.lock();
    --drive->count;
    drive->guard.unlock();
    drive->release();
    this->Request::Request();
    if (flags & 1) {
        FUN_0026d850(((char*)&DAT_0052a1c8));
        (*(Alloc_275ca0**)&DAT_0052a1e4)->free(this);
        FUN_0026d840(((char*)&DAT_0052a1c8));
    }
}
}

} // namespace fn_f241e4e6
