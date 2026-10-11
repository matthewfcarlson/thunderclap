// cl-flags: /O1
extern void* vt[];
class O {
  public:
    void* vptr;
    int a[4];
    O() throw();
};
O::O() throw() {
    *(void* volatile*)&vptr = vt;
    for (int i = 0; i <= 3; i++)
        a[i] = i;
}
