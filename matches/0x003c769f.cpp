// cl-flags: /O1
extern void* v_3c769f[];
int __stdcall Get(int) throw();
class O_3c769f {
  public:
    void* vptr;
    int a;
    int b;
    int pad;
    int pad2;
    void* l0;
    void* l1;
    O_3c769f(int x) throw();
};
O_3c769f::O_3c769f(int x) throw() {
    a = 1;
    vptr = v_3c769f;
    l1 = &l0;
    l0 = &l0;
    b = Get(x);
}
