#include "decls/data/engine/core.h"
// data: gAlloc_274eb0 = DAT_0052a1e4

class Alloc_274eb0 {
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
class Sub_274eb0 {
  public:
    virtual void a();
    virtual void b();
};
class Holder_274eb0 {
  public:
    virtual void a();
    virtual void b();
    Sub_274eb0 mSub;
    char pad2[0x10];
    int mCount;
};
class FileRequest {
  public:
    void** vt;
    int pad;
    Holder_274eb0* mH;
    FileRequest* Dtor(unsigned char flag);
};
FileRequest* FileRequest::Dtor(unsigned char flag) {
    vt = FileReqVtbl;
    mH->mSub.a();
    mH->mCount--;
    mH->mSub.b();
    mH->b();
    vt = ReqVtbl;
    if (flag & 1) {
        FUN_0026d850(((char*)&DAT_0052a1c8));
        (*(Alloc_274eb0**)&DAT_0052a1e4)->Free(this);
        FUN_0026d840(((char*)&DAT_0052a1c8));
    }
    return this;
}
