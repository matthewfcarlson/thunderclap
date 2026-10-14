class Handle_15c540 {
  public:
    void set(int, int, int);
    void act(int);
};
class Ref_15c540 {
  public:
    Handle_15c540* first();
    Handle_15c540* second();
};
class Manager_15c540 {
  public:
    Ref_15c540* get();
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
    Manager_15c540* p20;
    int p24;
};
void LocomotionSprintAction::vfunc_4() {
    if (p24) {
        Ref_15c540* x = p20->get();
        Handle_15c540* h = x->first();
        if (h) {
            h->set(p24, 0, (int)0xbf800000);
            h = x->second();
            if (h)
                h->act(0);
        }
    }
}