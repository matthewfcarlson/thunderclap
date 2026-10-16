extern void FUN_0026d850(void*);
extern void FUN_0026d840(void*);
struct Manager_274b60 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e(void*);
};
extern Manager_274b60* g_manager_274b60;
extern char g_lock_274b60[1];
extern void* request_vftable[];
namespace core { struct Request {
    void** vt;
    Request* vfunc_0(unsigned char);
}; }
core::Request* core::Request::vfunc_0(unsigned char param) {
    vt = request_vftable;
    if (param & 1) {
        FUN_0026d850(g_lock_274b60);
        g_manager_274b60->e(this);
        FUN_0026d840(g_lock_274b60);
    }
    return this;
}