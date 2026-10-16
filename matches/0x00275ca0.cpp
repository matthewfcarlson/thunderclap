#include "decls/data/engine/core.h"

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
void __cdecl FUN_0026d850(void*);
void __cdecl FUN_0026d840(void*);
namespace core {
struct Request {
    virtual void vfunc_0();
};
struct DriveRequest : Request {
    int field4;
    Drive* drive;
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    DriveRequest(unsigned flags);
};
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
} // namespace core