namespace core {

struct Inner {
    virtual void f0();
    virtual void f1();
};

struct Obj {
    virtual void g0();
    virtual void g1();
    Inner sub;
    char pad[0x14 - 4 - sizeof(Inner)];
    int count;
};

struct Alloc {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void Free(void* p);
};

extern Alloc* gAlloc;
extern int gLock;
void __cdecl Lock(void* p);
void __cdecl Unlock(void* p);

extern void* vtDrive[];
extern void* vtReq[];

class DriveFileDestroyRequest {
  public:
    int mA;
    Obj* mObj;
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
