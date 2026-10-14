// cl-flags: /O1
extern void* vt_34caee[];
class O_34caee {
  public:
    void* vptr;
    int a;
    int st;
    int b;
    O_34caee(int s) throw();
};
O_34caee::O_34caee(int s) throw() {
    a = 0;
    vptr = vt_34caee;
    st = s;
    b = (s == 2) ? 4 : 0;
}
