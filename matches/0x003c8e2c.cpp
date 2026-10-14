// cl-flags: /O1
extern void* v_3c8e2c[];
extern void* bv[];
void __stdcall Fn(int) throw();
void __stdcall Free(void*) throw();
class O_3c8e2c {
  public:
    void* vptr;
    char pad[0xac];
    int mb0;
    void* mb4;
    void* mb8;
    ~O_3c8e2c() throw();
};
O_3c8e2c::~O_3c8e2c() throw() {
    int t = mb0;
    *(void* volatile*)&vptr = v_3c8e2c;
    if (t)
        Fn(0);
    if (mb4) {
        Free(mb4);
        mb4 = 0;
    }
    if (mb8) {
        Free(mb8);
        mb8 = 0;
    }
    vptr = bv;
}
