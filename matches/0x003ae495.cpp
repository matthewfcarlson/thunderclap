// cl-flags: /O1
extern void* v_3ae495[];
class O_3ae495 {
  public:
    void* vptr;
    int pad;
    int a;
    int n;
    void Rm(int) throw();
    ~O_3ae495() throw();
};
O_3ae495::~O_3ae495() throw() {
    vptr = v_3ae495;
    while (n != 0)
        Rm(a);
}
