// cl-flags: /O1
extern void* v_3cf355[];
void __stdcall Free(void*) throw();
class O_3cf355 {
  public:
    void* vptr;
    int a[4];
    void* m14;
    int pad;
    void** m1c;
    ~O_3cf355() throw();
};
O_3cf355::~O_3cf355() throw() {
    vptr = v_3cf355;
    if (m14) {
        Free(m14);
        m14 = 0;
    }
    *m1c = 0;
}
