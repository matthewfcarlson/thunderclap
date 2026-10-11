// cl-flags: /O1
extern void* v[];
extern void* bv[];
void __stdcall Fn(int) throw();
void __stdcall Free(void*) throw();
class O {
  public:
    void* vptr;
    char pad[0xac];
    int mb0;
    void* mb4;
    void* mb8;
    ~O() throw();
};
O::~O() throw() {
    int t = mb0;
    *(void* volatile*)&vptr = v;
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
