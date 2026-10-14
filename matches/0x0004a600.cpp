typedef unsigned char u8;
struct A_4a600 {
    void* f();
};
struct B_4a600 {
    void* f();
};
struct Manager_4a600 {
    char pad[0x1b28];
    int field;
};
struct CRageModeCondition {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual bool vfunc_7(void* arg);
    char pad[8];
    bool value;
};
bool CRageModeCondition::vfunc_7(void* arg) {
    A_4a600* a = (A_4a600*)arg;
    void* p = a->f();
    B_4a600* b = (B_4a600*)p;
    Manager_4a600* q = (Manager_4a600*)b->f();
    bool r = q->field != 0;
    return r == value;
}
