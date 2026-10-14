extern void* g_vftable[];
extern void* g_vftable2[];
class Base {
  public:
    void* vptr;
    Base(int a);
};
class Derived : public Base {
  public:
    char pad[12];
    int m10;
    Derived(int a, int b);
};
Derived::Derived(int a, int b) : Base(a) {
    vptr = g_vftable;
    m10 = b;
}
