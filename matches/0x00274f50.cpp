#include "decls/data/engine/core.h"
// data: gAlloc_274f50 = DAT_0052a1e4

class Alloc_274f50 {
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
class Sub_274f50 {
  public:
    virtual void a();
    virtual void b();
};
class Holder_274f50 {
  public:
    virtual void a();
    virtual void b();
    Sub_274f50 mSub;
    char pad2[0x10];
    int mCount;
};
class FileOpenRequest_274f50 {
  public:
    void** vt;
    int pad;
    Holder_274f50* mH;
    FileOpenRequest_274f50* Dtor(unsigned char flag);
};
FileOpenRequest_274f50* FileOpenRequest_274f50::Dtor(unsigned char flag) {
    vt = FileReqVtbl;
    mH->mSub.a();
    mH->mCount--;
    mH->mSub.b();
    mH->b();
    vt = ReqVtbl;
    if (flag & 1) {
        Lock(((char*)&DAT_0052a1c8));
        (*(Alloc_274f50**)&DAT_0052a1e4)->Free(this);
        Unlock(((char*)&DAT_0052a1c8));
    }
    return this;
}
