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
class SaveGameOpenRequest {
  public:
    void* vt;
    int pad;
    Inner* inner;
    SaveGameOpenRequest* vfunc_0(int flags);
};
SaveGameOpenRequest* SaveGameOpenRequest::vfunc_0(int flags) {
    Inner* p = inner;
    *(void**)this = (void*)0x42b99c;
    ((Inner*)((char*)p + 4))->a();
    --*(int*)((char*)inner + 0x18);
    ((Inner*)((char*)inner + 4))->b();
    ((Root*)inner)->b();
    *(void**)this = (void*)0x42b914;
    if (flags & 1) {
        FUN_0026d850((void*)0x52a1c8);
        g_mgr->add(this);
        FUN_0026d840((void*)0x52a1c8);
    }
    return this;
}