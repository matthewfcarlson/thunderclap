void* __cdecl Alloc(unsigned int) throw();
class Mem {
  public:
    void* Make(unsigned int, int) throw();
};
struct B {
    virtual void a();
    B(int, int) throw();
    int m4, m8;
    Mem* mc;
    int m10;
};
struct D : B {
    void* m14;
    void* m18;
    D(int x, int y) throw();
    virtual void a();
};
D::D(int x, int y) throw() : B(x, y) {
    m18 = 0;
    if (mc == 0)
        m18 = Alloc(m10 * 4);
    else
        m18 = mc->Make(m10 * 4, 3);
}
