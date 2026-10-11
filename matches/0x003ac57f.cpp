// cl-flags: /O1
extern void* vt[];
class O {
  public:
    void* vptr;
    O(int a) throw();
    void Init(int a) throw();
};
O::O(int a) throw() {
    vptr = vt;
    Init(a);
}
