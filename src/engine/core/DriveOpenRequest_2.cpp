// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002756e0..0x00275750 (kind game, layer engine, confidence medium), dominant class core::DriveOpenRequest
#include "tree_prelude.h"
#include "decls/data/engine/core.h"
#define TREE_TU_BEGIN namespace fn_f0fe475a {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f0fe475a {} using namespace fn_f0fe475a;
#include "engine/core.h"

// ---- declarations shared by the functions below
namespace fn_f0fe475a {
namespace core {
struct Lock_2756e0 {
    virtual void acquire() throw();
    virtual void release() throw();
};
}
namespace core {
struct Drive {
    virtual void unused() throw();
    virtual void release() throw();
    Lock_2756e0 lock;
    char pad[12];
    int count;
};
}
namespace core {
struct Request {
    virtual Request* vfunc_0(unsigned);
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    __forceinline ~Request() throw() {}
};
}
namespace core {
struct DriveRequest {
    virtual DriveRequest* vfunc_0(unsigned);
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    int field4;
    Drive* drive;
    __forceinline ~DriveRequest() throw() {}
};
}
namespace core {
struct DriveOpenRequest : DriveRequest {
    virtual DriveOpenRequest* vfunc_0(unsigned);
    virtual void vfunc_1();
    virtual void vfunc_4();
    virtual void vfunc_6();
};
}
struct Allocator {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void free(void*);
};


// 0x002756e0 core::DriveOpenRequest::vfunc_0 (102 B): matches/0x002756e0.cpp
// sym: ?vfunc_0@DriveOpenRequest@core@fn_f0fe475a@@UAEPAU123@I@Z
core::DriveOpenRequest* core::DriveOpenRequest::vfunc_0(unsigned flags) {
    this->DriveRequest::~DriveRequest();
    drive->lock.acquire();
    --drive->count;
    drive->lock.release();
    drive->release();
    reinterpret_cast<Request*>(this)->Request::~Request();
    if (flags & 1) {
        FUN_0026d850(((char*)&DAT_0052a1c8));
        (*(Allocator**)&DAT_0052a1e4)->free(this);
        FUN_0026d840(((char*)&DAT_0052a1c8));
    }
    return this;
}

} // namespace fn_f0fe475a
