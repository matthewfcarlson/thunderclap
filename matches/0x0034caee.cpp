// cl-flags: /O1
extern void* vt[];
class O {
  public:
    void* vptr;
    int a;
    int st;
    int b;
    O(int s) throw();
};
O::O(int s) throw() {
    a = 0;
    vptr = vt;
    st = s;
    b = (s == 2) ? 4 : 0;
}
