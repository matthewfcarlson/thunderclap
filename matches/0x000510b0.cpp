extern void* g_vftable[];
class Base {
  public:
    void* vptr;
    Base() { vptr = g_vftable; }
};
class Derived : public Base {
  public:
    virtual void Dummy();
    Derived();
};
Derived::Derived() {
    vptr = g_vftable;
}