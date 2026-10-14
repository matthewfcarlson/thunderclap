// cl-flags: /O1
extern void* vb[];
class O_3ad92c {
  public:
    void* vptr;
    int a;
    int b;
    int c;
    int d;
    int e;
    O_3ad92c(int x, int y) throw();
};
O_3ad92c::O_3ad92c(int x, int y) throw() {
    c = 0;
    d = 0;
    a = x;
    vptr = vb;
    b = y;
    e = 1;
}
