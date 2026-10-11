class Alloc {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void Free(void* p);
};
extern Alloc* gAlloc;
extern char gCs[];
extern void* ReqVtbl[];
extern void* FileReqVtbl[];
void Lock(void*);
void Unlock(void*);
class Sub {
  public:
    virtual void a();
    virtual void b();
};
class Holder {
  public:
    virtual void a();
    virtual void b();
    Sub mSub;
    char pad2[0x10];
    int mCount;
};
class FileRequest {
  public:
    void** vt;
    int pad;
    Holder* mH;
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
        Lock(gCs);
        gAlloc->Free(this);
        Unlock(gCs);
    }
    return this;
}
