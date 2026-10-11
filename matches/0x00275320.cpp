extern void* g_vftableA[];
extern void* g_vftableB[];
class Inner {
  public:
    virtual void a();
    virtual void b();
};
class Root {
  public:
    virtual void a();
    virtual void b();
};
extern void __cdecl FUN_0026d850(void*);
extern void __cdecl FUN_0026d840(void*);
struct Manager {
    virtual void x();
    virtual void y();
    virtual void z();
    virtual void q();
    virtual void add(void*);
};
extern Manager* g_mgr;
extern char g_lock[];
class Req {
  public:
    void* vt;
    int pad;
    Inner* inner;
    Req* vfunc_0(int flags);
};
Req* Req::vfunc_0(int flags) {
    Inner* p = inner;
    vt = g_vftableA;
    ((Inner*)((char*)p + 4))->a();
    --*(int*)((char*)inner + 0x18);
    ((Inner*)((char*)inner + 4))->b();
    ((Root*)inner)->b();
    vt = g_vftableB;
    if (flags & 1) {
        FUN_0026d850(g_lock);
        g_mgr->add(this);
        FUN_0026d840(g_lock);
    }
    return this;
}
