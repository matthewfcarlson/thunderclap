namespace core {

struct Inner_275c10 {
    virtual void f0();
    virtual void f1();
};

struct Obj_275c10 {
    virtual void g0();
    virtual void g1();
    Inner_275c10 sub;
    char pad[0x14 - 4 - sizeof(Inner_275c10)];
    int count;
};

struct Alloc_275c10 {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void Free(void* p);
};

extern Alloc_275c10* gAlloc;
extern int gLock;
void __cdecl Lock(void* p);
void __cdecl Unlock(void* p);

extern void* vtDrive[];
extern void* vtReq[];

class DriveFileDestroyRequest {
  public:
    int mA;
    Obj_275c10* mObj;
    virtual void* vfunc_0(unsigned flags);
    virtual void vfunc_1();
};

void* DriveFileDestroyRequest::vfunc_0(unsigned flags) {
    *(void***)this = vtDrive;
    mObj->sub.f0();
    mObj->count--;
    mObj->sub.f1();
    mObj->g1();
    *(void***)this = vtReq;
    if (flags & 1) {
        Lock(&gLock);
        gAlloc->Free(this);
        Unlock(&gLock);
    }
    return this;
}

} // namespace core
