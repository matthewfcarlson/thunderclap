// cl-flags: /O1
extern void* vt[];
extern "C" void* malloc(unsigned n) throw();
class O {
  public:
    void* vptr;
    char* s;
    int owned;
    O(const char* const* p) throw();
};
O::O(const char* const* p) throw() {
    vptr = vt;
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
