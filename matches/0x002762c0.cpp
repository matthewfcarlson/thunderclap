#include "gen/core.h"

class IFile_2762c0 {
  public:
    virtual void a();
    virtual void b();
};
class IRefCount_2762c0 {
  public:
    virtual void c();
    virtual void d();
};
class IMutable_2762c0 {
  public:
    virtual void e();
    virtual void f();
};

void* core::File::vfunc_25() {
    return (void*)((core::File*)((char*)this + 0x1e));
}
