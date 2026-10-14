extern void* g_vftable_510b0[];
class Base_510b0 {
  public:
    void* vptr;
    Base_510b0() { vptr = g_vftable_510b0; }
};
class Derived_510b0 : public Base_510b0 {
  public:
    virtual void Dummy();
    Derived_510b0();
};
Derived_510b0::Derived_510b0() {
    vptr = g_vftable_510b0;
}