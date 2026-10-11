// cl-flags: /O1
extern void* v[];
void __stdcall Free(void*) throw();
class O {
  public:
    void* vptr;
    int a[4];
    void* m14;
    int pad;
    void** m1c;
    ~O() throw();
};
O::~O() throw() {
    vptr = v;
    if (m14) {
        Free(m14);
        m14 = 0;
    }
    *m1c = 0;
}
