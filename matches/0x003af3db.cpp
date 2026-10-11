// cl-flags: /O1
extern void* v0[];
extern void* v1[];
extern void* v2[];
class O {
  public:
    void* vptr;
    int pad;
    void* a;
    void* b;
    void* vptr2;
    O() throw();
};
O::O() throw() {
    a = 0;
    b = 0;
    *(void* volatile*)&vptr2 = v0;
    vptr = v1;
    vptr2 = v2;
}
