extern void* g_vftable[];
class Base {
  public:
    Base(int);
    virtual void f();
    char pad[0x0c];
};
class Derived : public Base {
  public:
    Derived(int a, int b);
    virtual void g();
    int m10;
};
Derived::Derived(int a, int b) : Base(a) {
    *(void**)this = g_vftable;
    m10 = b;
}
