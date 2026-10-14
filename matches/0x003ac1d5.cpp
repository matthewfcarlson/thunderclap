// cl-flags: /O1
extern void* vt_3ac1d5[];
class O_3ac1d5 {
  public:
    void* vptr;
    int a;
    O_3ac1d5* b;
    O_3ac1d5* c;
    O_3ac1d5(int x, O_3ac1d5* y, O_3ac1d5* z) throw();
};
O_3ac1d5::O_3ac1d5(int x, O_3ac1d5* y, O_3ac1d5* z) throw() {
    a = x;
    vptr = vt_3ac1d5;
    b = y;
    c = z;
    if (y)
        y->c = this;
    if (z)
        z->b = this;
}
