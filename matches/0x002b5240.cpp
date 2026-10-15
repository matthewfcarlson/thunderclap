class Ref {
  public:
    virtual void AddRef();
    virtual void Release();
};
extern Ref* gRef;
class Base {
  public:
    virtual void v0();
    char pad[0x0c];
    int n;
    char rest[0x2c];
    Base();
};
struct Handle {
    Ref* ptr;
    Handle() : ptr(0) {}
    void operator=(Ref* p) {
        if (p)
            p->AddRef();
        if (ptr)
            ptr->Release();
        ptr = p;
    }
};
class ShadowMeshImpl : public Base {
  public:
    virtual void v0();
    Handle handle;
    void* a;
    void* b;
    void* c;
    void* d;
    ShadowMeshImpl();
};
ShadowMeshImpl::ShadowMeshImpl() : Base(), handle(), a(0), b(0), c(0), d(0) {
    n = 2;
    handle = gRef;
}