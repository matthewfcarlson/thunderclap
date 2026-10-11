// cl-flags: /O1
extern void* v[];
int __stdcall Get(int) throw();
class O {
  public:
    void* vptr;
    int a;
    int b;
    int pad;
    int pad2;
    void* l0;
    void* l1;
    O(int x) throw();
};
O::O(int x) throw() {
    a = 1;
    vptr = v;
    l1 = &l0;
    l0 = &l0;
    b = Get(x);
}
