extern void* v[];
class O;
extern O* g;
class O {
  public:
    void* vptr;
    int a;
    void* l0;
    void* l1;
    void* m0;
    void* m1;
    O() throw();
};
O::O() throw() {
    a = 1;
    vptr = v;
    g = this;
    l1 = &l0;
    l0 = &l0;
    m1 = &m0;
    m0 = &m0;
}
