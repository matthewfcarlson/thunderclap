// cl-flags: /O1
extern void* vt_3496b8[];
extern "C" void* malloc(unsigned n) throw();
class O_3496b8 {
  public:
    void* vptr;
    char* s;
    int owned;
    O_3496b8(const char* const* p) throw();
};
O_3496b8::O_3496b8(const char* const* p) throw() {
    vptr = vt_3496b8;
    const char* q = *p;
    const char* r = q + 1;
    while (*q++) {
    }
    char* d = (char*)malloc((q - r) + 1);
    s = d;
    if (d) {
        const char* t = *p;
        char c;
        do {
            c = *t++;
            *d++ = c;
        } while (c);
    }
    owned = 1;
}
