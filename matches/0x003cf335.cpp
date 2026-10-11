extern void* v[];
extern int g;
struct N {
    N* next;
    N* prev;
};
class O {
  public:
    void* vptr;
    N n0;
    N n1;
    int pad;
    int pad2;
    int* m1c;
    O() throw();
};
O::O() throw() {
    n0.prev = &n0;
    n0.next = &n0;
    vptr = v;
    m1c = &g;
    n1.prev = &n1;
    n1.next = &n1;
}
