// cl-flags: /O1
extern void* vt[];
extern "C" void* malloc(unsigned n) throw();
class O {
  public:
    void* vptr;
    char* s;
    int owned;
    O(const O& o) throw();
};
O::O(const O& o) throw() {
    vptr = vt;
    owned = o.owned;
    if (owned) {
        const char* q = o.s;
        const char* r = q + 1;
        while (*q++) {
        }
        char* d = (char*)malloc((q - r) + 1);
        s = d;
        if (d) {
            const char* t = o.s;
            char c;
            do {
                c = *t++;
                *d++ = c;
            } while (c);
        }
    } else {
        s = o.s;
    }
}
