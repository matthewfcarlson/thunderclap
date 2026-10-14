// cl-flags: /O1
extern void* vt_3ac57f[];
class O_3ac57f {
  public:
    void* vptr;
    O_3ac57f(int a) throw();
    void Init(int a) throw();
};
O_3ac57f::O_3ac57f(int a) throw() {
    vptr = vt_3ac57f;
    Init(a);
}
