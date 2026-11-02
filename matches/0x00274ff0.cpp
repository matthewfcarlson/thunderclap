#include "decls/data/engine/core.h"
// data: gAlloc_274ff0 = DAT_0052a1e4

class Alloc_274ff0 {
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
class Sub_274ff0 {
  public:
    virtual void a();
    virtual void b();
};
class Holder_274ff0 {
  public:
    virtual void a();
    virtual void b();
    Sub_274ff0 mSub;
    char pad2[0x10];
    int mCount;
};
class FileOpenByKeyRequest_274ff0 {
  public:
    void** vt;
    int pad;
    Holder_274ff0* mH;
    FileOpenByKeyRequest_274ff0* Dtor(unsigned char flag);
};
FileOpenByKeyRequest_274ff0* FileOpenByKeyRequest_274ff0::Dtor(unsigned char flag) {
    vt = FileReqVtbl;
    mH->mSub.a();
    mH->mCount--;
    mH->mSub.b();
    mH->b();
    vt = ReqVtbl;
    if (flag & 1) {
        FUN_0026d850(((char*)&DAT_0052a1c8));
        (*(Alloc_274ff0**)&DAT_0052a1e4)->Free(this);
        FUN_0026d840(((char*)&DAT_0052a1c8));
    }
    return this;
}
