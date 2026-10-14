extern void* v_3cf5a2[];
class O_3cf5a2;
extern O_3cf5a2* g_3cf5a2;
class O_3cf5a2 {
  public:
    void* vptr;
    int a;
    void* l0;
    void* l1;
    void* m0;
    void* m1;
    O_3cf5a2() throw();
};
O_3cf5a2::O_3cf5a2() throw() {
    a = 1;
    vptr = v_3cf5a2;
    g_3cf5a2 = this;
    l1 = &l0;
    l0 = &l0;
    m1 = &m0;
    m0 = &m0;
}
