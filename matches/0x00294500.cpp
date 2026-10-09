struct Buf {
    char pad[12];
    void put(void* p, unsigned int v);
};
struct Sub {
    unsigned int getval();
};
struct Mgr {
    Sub* sub;
};
extern Mgr* gmgr;
struct Obj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual unsigned int get();
};
class Target {
  public:
    char pad[0x18];
    Obj* obj;
    void run(int a, int b, int c, Buf* out);
};
void Target::run(int a, int b, int c, Buf* out) {
    Buf local;
    local.put(&a, gmgr->sub->getval());
    if (obj) {
        unsigned int v = obj->get();
        out->put(&local, v);
    }
}
