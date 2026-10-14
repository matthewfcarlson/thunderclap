struct Status_4a500 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
    virtual int get();
};
struct Entity {
    char pad[0x1ca0];
    Status_4a500* status;
};
class CAlertStatusCondition {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual bool v7(void*);
    virtual Entity* v8(void*);
    int pad[2];
    int mode;
    int value;
};
bool CAlertStatusCondition::v7(void* arg) {
    Entity* obj = v8(arg);
    if (obj == 0)
        return false;
    if (obj->status == 0)
        return false;
    int x = obj->status->get();
    switch (mode) {
    case 0:
        return x == value;
    case 1:
        return x != value;
    }
    return false;
}
