// cl-flags: /O1
extern void* v[];
class O {
  public:
    void* vptr;
    int pad;
    int a;
    int n;
    void Rm(int) throw();
    ~O() throw();
};
O::~O() throw() {
    vptr = v;
    while (n != 0)
        Rm(a);
}
