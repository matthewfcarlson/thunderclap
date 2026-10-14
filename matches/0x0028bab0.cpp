void* __cdecl Alloc(unsigned int) throw();
class Mem_28bab0 {
  public:
    void* Make(unsigned int, int) throw();
};
struct B_28bab0 {
    virtual void a();
    B_28bab0(int, int) throw();
    int m4, m8;
    Mem_28bab0* mc;
    int m10;
};
struct D : B_28bab0 {
    void* m14;
    void* m18;
    D(int x, int y) throw();
    virtual void a();
};
D::D(int x, int y) throw() : B_28bab0(x, y) {
    m18 = 0;
    if (mc == 0)
        m18 = Alloc(m10 * 4);
    else
        m18 = mc->Make(m10 * 4, 3);
}
