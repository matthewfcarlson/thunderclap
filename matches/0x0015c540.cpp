class Handle {
  public:
    void set(int, int, int);
    void act(int);
};
class Ref {
  public:
    Handle* first();
    Handle* second();
};
class Manager {
  public:
    Ref* get();
};
class LocomotionSprintAction {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void vfunc_4();
    virtual void f5();
    char pad[0x1c];
    Manager* p20;
    int p24;
};
void LocomotionSprintAction::vfunc_4() {
    if (p24) {
        Ref* x = p20->get();
        Handle* h = x->first();
        if (h) {
            h->set(p24, 0, (int)0xbf800000);
            h = x->second();
            if (h)
                h->act(0);
        }
    }
}