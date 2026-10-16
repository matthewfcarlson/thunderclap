extern "C" char DAT_0042b914[];
extern "C" char DAT_0042b9bc[];
extern "C" char DAT_0052a1c8[];
typedef unsigned char byte_275970;
struct O_275970 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e(void*);
    virtual void f();
    virtual void g();
};
struct T_275970 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    char pad[0x10];
    int count;
};
namespace core { struct DriveDestroyDirectoryRequest {
    virtual DriveDestroyDirectoryRequest* vfunc_0(byte_275970);
    char pad[4];
    T_275970* field8;
}; }
extern void FUN_0026d850(void*);
extern void FUN_0026d840(void*);
extern O_275970* glob_275970;
core::DriveDestroyDirectoryRequest* core::DriveDestroyDirectoryRequest::vfunc_0(byte_275970 flag) {
    *(void**)this = (void*)((int)DAT_0042b9bc);
    ((O_275970*)((char*)field8 + 4))->a();
    field8->count--;
    ((O_275970*)((char*)field8 + 4))->b();
    ((O_275970*)field8)->b();
    *(void**)this = (void*)((int)DAT_0042b914);
    if (flag & 1) {
        FUN_0026d850((void*)((int)DAT_0052a1c8));
        glob_275970->e(this);
        FUN_0026d840((void*)((int)DAT_0052a1c8));
    }
    return this;
}
