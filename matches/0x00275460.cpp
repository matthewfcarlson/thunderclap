extern void* g_vfFile[];
extern void* g_vfReq[];
class Sub {
  public:
    virtual void f0();
    virtual void f1();
};
class Obj {
  public:
    virtual void f0();
    virtual void f1();
    Sub sub;
    char pad[0x18 - 8];
    int cnt;
};
class Holder {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e(void*);
};
extern Holder* g_holder;
extern char g_buf;
void Init(void*);
void Fini(void*);
class Req {
  public:
    void* vptr;
    int pad;
    Obj* file;
    Req* f0(unsigned char flags);
};
Req* Req::f0(unsigned char flags) {
    vptr = g_vfFile;
    file->sub.f0();
    --file->cnt;
    file->sub.f1();
    ((Sub*)file)->f1();
    vptr = g_vfReq;
    if (flags & 1) {
        Init(&g_buf);
        g_holder->e(this);
        Fini(&g_buf);
    }
    return this;
}
