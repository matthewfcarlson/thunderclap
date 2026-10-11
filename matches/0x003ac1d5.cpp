// cl-flags: /O1
extern void* vt[];
class O {
  public:
    void* vptr;
    int a;
    O* b;
    O* c;
    O(int x, O* y, O* z) throw();
};
O::O(int x, O* y, O* z) throw() {
    a = x;
    vptr = vt;
    b = y;
    c = z;
    if (y)
        y->c = this;
    if (z)
        z->b = this;
}
