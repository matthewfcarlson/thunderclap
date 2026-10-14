extern char DAT_0052a1c8;
void __cdecl FUN_0026d850(void*);
void __cdecl FUN_0026d840(void*);
struct Allocator {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void release(void*);
};
extern Allocator* DAT_0052a1e4;
struct Lock_2753c0 {
    virtual void enter();
    virtual void leave();
};
struct File {
    virtual void a();
    virtual void release();
    Lock_2753c0 lock;
    char pad[16];
    int count;
};
namespace core {
struct Request {
    virtual void* vfunc_0(unsigned);
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
};
struct FileRequest : Request {
    unsigned field4;
    File* file;
    virtual void* vfunc_0(unsigned);
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    FileRequest(unsigned flags);
};
} // namespace core
core::FileRequest::FileRequest(unsigned flags) {
    file->lock.enter();
    --file->count;
    file->lock.leave();
    file->release();
    this->Request::Request();
    if (flags & 1) {
        FUN_0026d850(&DAT_0052a1c8);
        DAT_0052a1e4->release(this);
        FUN_0026d840(&DAT_0052a1c8);
    }
}