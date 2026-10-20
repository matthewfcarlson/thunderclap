class Alloc_274ff0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void Free(void* p);
};
extern Alloc_274ff0* gAlloc_274ff0;
extern char gCs[];
extern void* ReqVtbl[];
extern void* FileReqVtbl[];
void Lock(void*);
void Unlock(void*);
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
        Lock(gCs);
        gAlloc_274ff0->Free(this);
        Unlock(gCs);
    }
    return this;
}
