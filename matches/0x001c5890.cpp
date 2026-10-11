extern void* g_vtMgr[];
extern void* g_vtT[];
extern void* g_vtO[];
class Ref {
  public:
    virtual void F0();
    virtual void Release();
};
struct Store {
    void* vptr;
    char pad[4];
    unsigned m8;
    char padc[4];
    int m10;
    Ref** m14;
    char pad2[0x120 - 0x18];
    void A();
    void B();
};
struct Mgr {
    void* vptr;
    char pad[4];
    Store base;
    Store tmpl;
    ~Mgr();
};
Mgr::~Mgr() {
    int n = base.m10;
    vptr = g_vtMgr;
    for (int i = 0; i < n; i++) {
        if ((unsigned)i < base.m8) {
            Ref* r = base.m14[i];
            if (r)
                r->Release();
        }
    }
    tmpl.vptr = g_vtT;
    tmpl.A();
    tmpl.B();
    base.vptr = g_vtO;
    base.A();
    base.B();
}
