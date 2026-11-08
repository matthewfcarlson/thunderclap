#include "decls/data/engine/core.h"
#include "decls/data/records.h"
// data: the "FileRequest" pool = DAT_0052a1e4, its lock = DAT_0052a1c8

struct Lock_2751c0 {
    virtual void lock();
    virtual void unlock();
};
struct Ref_2751c0 {
    virtual void v0();
    virtual void release();
};
struct Alloc_2751c0 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void free(void*);
};
extern "C" char DAT_0042b914[];
extern "C" char DAT_0042b99c[];
extern "C" void __cdecl FUN_0026d850(void*);
extern "C" void __cdecl FUN_0026d840(void*);
// core::FileCommitRequest's deleting destructor (records.h CoreRequest): core::FileRequest's part (one request less pending
// on the file, CoreFile field18, under its IMutable lock; the file's reference released), then core::Request's; the
// memory goes back to the "FileRequest" pool
class FileCommitRequest_2751c0 : public CoreRequest {
  public:
    FileCommitRequest_2751c0* f0(unsigned char flags);
};
FileCommitRequest_2751c0* FileCommitRequest_2751c0::f0(unsigned char flags) {
    vftable = DAT_0042b99c;
    ((Lock_2751c0*)&((CoreFile*)file)->vftableMutable)->lock();
    --((CoreFile*)file)->field18;
    ((Lock_2751c0*)&((CoreFile*)file)->vftableMutable)->unlock();
    ((Ref_2751c0*)file)->release();
    vftable = DAT_0042b914;
    if (flags & 1) {
        FUN_0026d850(((char*)&DAT_0052a1c8));
        (*(Alloc_2751c0**)&DAT_0052a1e4)->free(this);
        FUN_0026d840(((char*)&DAT_0052a1c8));
    }
    return this;
}
