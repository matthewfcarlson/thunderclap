#include "decls/data/engine/core.h"
// data: gAlloc_275590 = DAT_0052a1e4

class Alloc_275590 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void Free(void* p);
};
extern void* ReqVtbl[];
extern void* FileReqVtbl[];
extern "C" void FUN_0026d850(void*);
extern "C" void FUN_0026d840(void*);
class Sub_275590 {
  public:
    virtual void a();
    virtual void b();
};
class Holder_275590 {
  public:
    virtual void a();
    virtual void b();
    Sub_275590 mSub;
    char pad2[0x10];
    int mCount;
};
class FileCancelRequest_275590 {
  public:
    void** vt;
    int pad;
    Holder_275590* mH;
    FileCancelRequest_275590* Dtor(unsigned char flag);
};
FileCancelRequest_275590* FileCancelRequest_275590::Dtor(unsigned char flag) {
    vt = FileReqVtbl;
    mH->mSub.a();
    mH->mCount--;
    mH->mSub.b();
    mH->b();
    vt = ReqVtbl;
    if (flag & 1) {
        FUN_0026d850(((char*)&DAT_0052a1c8));
        (*(Alloc_275590**)&DAT_0052a1e4)->Free(this);
        FUN_0026d840(((char*)&DAT_0052a1c8));
    }
    return this;
}
