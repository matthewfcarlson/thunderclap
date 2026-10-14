// cl-flags: /O1
extern void* va[];
class O_3ad7ae {
  public:
    void* vptr;
    int a;
    int b;
    int c;
    int d;
    int e;
    O_3ad7ae(int x, int y) throw();
};
O_3ad7ae::O_3ad7ae(int x, int y) throw() {
    c = 0;
    d = 0;
    a = x;
    vptr = va;
    b = y;
    e = 1;
}
