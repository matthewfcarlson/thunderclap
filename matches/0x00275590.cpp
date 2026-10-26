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
void Lock(void*);
void Unlock(void*);
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
        Lock(((char*)&DAT_0052a1c8));
        (*(Alloc_275590**)&DAT_0052a1e4)->Free(this);
        Unlock(((char*)&DAT_0052a1c8));
    }
    return this;
}
