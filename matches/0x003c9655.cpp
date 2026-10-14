// cl-flags: /O1
extern void* v_3c9655[];
void __stdcall SetBufferData(void*, unsigned) throw();
class O_3c9655 {
  public:
    void* vptr;
    void Cl(int, int) throw();
    void Base() throw();
    ~O_3c9655() throw();
};
O_3c9655::~O_3c9655() throw() {
    vptr = v_3c9655;
    SetBufferData(0, 0);
    Cl(0, 0);
    Base();
}
