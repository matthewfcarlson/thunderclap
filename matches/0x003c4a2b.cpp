extern void* v[];
class O;
extern O* g;
class O {
  public:
    void* vptr;
    int a;
    int b;
    int c;
    void* l0;
    void* l1;
    O() throw();
};
O::O() throw() {
    a = 2;
    vptr = v;
    g = this;
    l1 = &l0;
    l0 = &l0;
}
