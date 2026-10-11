// cl-flags: /O1
extern void* v[];
void __stdcall SetBufferData(void*, unsigned) throw();
class O {
  public:
    void* vptr;
    void Cl(int, int) throw();
    void Base() throw();
    ~O() throw();
};
O::~O() throw() {
    vptr = v;
    SetBufferData(0, 0);
    Cl(0, 0);
    Base();
}
