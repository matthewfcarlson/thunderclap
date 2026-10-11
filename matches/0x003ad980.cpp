// cl-flags: /O1
extern void* va[];
class O {
  public:
    void* vptr;
    int a;
    int b;
    int c;
    int d;
    int e;
    O(int x, int y) throw();
};
O::O(int x, int y) throw() {
    c = 0;
    d = 0;
    a = x;
    vptr = va;
    b = y;
    e = 1;
}
