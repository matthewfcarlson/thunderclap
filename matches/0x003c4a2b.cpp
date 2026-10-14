extern void* v_3c4a2b[];
class O_3c4a2b;
extern O_3c4a2b* g_3c4a2b;
class O_3c4a2b {
  public:
    void* vptr;
    int a;
    int b;
    int c;
    void* l0;
    void* l1;
    O_3c4a2b() throw();
};
O_3c4a2b::O_3c4a2b() throw() {
    a = 2;
    vptr = v_3c4a2b;
    g_3c4a2b = this;
    l1 = &l0;
    l0 = &l0;
}
