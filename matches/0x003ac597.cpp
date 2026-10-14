// cl-flags: /O1
extern void* vt_3ac597[];
class O_3ac597 {
  public:
    void* vptr;
    O_3ac597(int a) throw();
    void Init(int a) throw();
};
O_3ac597::O_3ac597(int a) throw() {
    vptr = vt_3ac597;
    Init(8 >> a);
}
