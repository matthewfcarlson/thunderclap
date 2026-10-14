// Same code shape as 0x00274b60 (propagated; names are from that function)
extern void FUN_0026d850(void*);
extern void FUN_0026d840(void*);
struct Manager_274c60 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e(void*);
};
extern Manager_274c60* g_manager_274c60;
extern char g_lock_274c60[1];
extern void* request_vftable[];
struct Request {
    void** vt;
    Request* vfunc_0(unsigned char);
};
Request* Request::vfunc_0(unsigned char param) {
    vt = request_vftable;
    if (param & 1) {
        FUN_0026d850(g_lock_274c60);
        g_manager_274c60->e(this);
        FUN_0026d840(g_lock_274c60);
    }
    return this;
}