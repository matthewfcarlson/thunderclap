extern void* g_vtMgr[];
extern void* g_vtT[];
extern void* g_vtO[];
class Ref_1c5890 {
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
    Ref_1c5890** m14;
    char pad2[0x120 - 0x18];
    void A();
    void B();
};
struct ObjectManager_1c5890 {
    void* vptr;
    char pad[4];
    Store base;
    Store tmpl;
    ~ObjectManager_1c5890();
};
ObjectManager_1c5890::~ObjectManager_1c5890() {
    int n = base.m10;
    vptr = g_vtMgr;
    for (int i = 0; i < n; i++) {
        if ((unsigned)i < base.m8) {
            Ref_1c5890* r = base.m14[i];
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
