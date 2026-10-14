// cl-flags: /O1
extern void* vt_3496fd[];
extern "C" void* malloc(unsigned n) throw();
class O_3496fd {
  public:
    void* vptr;
    char* s;
    int owned;
    O_3496fd(const O_3496fd& o) throw();
};
O_3496fd::O_3496fd(const O_3496fd& o) throw() {
    vptr = vt_3496fd;
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
