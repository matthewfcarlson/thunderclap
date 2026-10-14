struct A_16540 {
    A_16540* get();
    int find(void*);
    int remove(void*, int);
};
struct B_16540 {
    A_16540* get();
};
struct Manager_16540 {
    char pad[0xc];
    A_16540* obj;
};
extern Manager_16540* volatile gManager_16540;
struct CSmartPropRemoveInstanceAction {
    char pad[0x18];
    B_16540* owner;
    void* instance;
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual bool vfunc_6(int);
};
bool CSmartPropRemoveInstanceAction::vfunc_6(int) {
    A_16540* a = owner->get();
    a = a->get();
    int x = a->find(instance);
    if (x)
        gManager_16540->obj->remove((void*)x, 1);
    return false;
}
