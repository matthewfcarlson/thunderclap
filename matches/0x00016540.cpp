struct A {
    A* get();
    int find(void*);
    int remove(void*, int);
};
struct B {
    A* get();
};
struct Manager {
    char pad[0xc];
    A* obj;
};
extern Manager* volatile gManager;
struct CSmartPropRemoveInstanceAction {
    char pad[0x18];
    B* owner;
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
    A* a = owner->get();
    a = a->get();
    int x = a->find(instance);
    if (x)
        gManager->obj->remove((void*)x, 1);
    return false;
}
