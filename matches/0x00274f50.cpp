class Alloc_274f50 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void Free(void* p);
};
extern Alloc_274f50* gAlloc_274f50;
extern char gCs[];
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
class FileRequest {
  public:
    void** vt;
    int pad;
    Holder_274f50* mH;
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
        gAlloc_274f50->Free(this);
        Unlock(gCs);
    }
    return this;
}
