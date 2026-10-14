namespace core {
struct Lock_2756e0 {
    virtual void acquire() throw();
    virtual void release() throw();
};
struct Drive {
    virtual void unused() throw();
    virtual void release() throw();
    Lock_2756e0 lock;
    char pad[12];
    int count;
};
struct Request {
    virtual Request* vfunc_0(unsigned);
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    __forceinline ~Request() throw() {}
};
struct DriveRequest {
    virtual DriveRequest* vfunc_0(unsigned);
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    int field4;
    Drive* drive;
    __forceinline ~DriveRequest() throw() {}
};
struct DriveOpenRequest : DriveRequest {
    virtual DriveOpenRequest* vfunc_0(unsigned);
    virtual void vfunc_1();
    virtual void vfunc_4();
    virtual void vfunc_6();
};
} // namespace core
struct Allocator {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void free(void*);
};
extern char DAT_0052a1c8;
extern Allocator* DAT_0052a1e4;
void __cdecl FUN_0026d850(void*);
void __cdecl FUN_0026d840(void*);
core::DriveOpenRequest* core::DriveOpenRequest::vfunc_0(unsigned flags) {
    this->DriveRequest::~DriveRequest();
    drive->lock.acquire();
    --drive->count;
    drive->lock.release();
    drive->release();
    reinterpret_cast<Request*>(this)->Request::~Request();
    if (flags & 1) {
        FUN_0026d850(&DAT_0052a1c8);
        DAT_0052a1e4->free(this);
        FUN_0026d840(&DAT_0052a1c8);
    }
    return this;
}
