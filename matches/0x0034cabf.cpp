// cl-flags: /O1
extern void* vt_34cabf[];
struct DName {
    int pad;
    int st : 4;
};
class O_34cabf {
  public:
    void* vptr;
    int a;
    DName* n;
    O_34cabf(DName* d) throw();
};
O_34cabf::O_34cabf(DName* d) throw() {
    a = 0;
    vptr = vt_34cabf;
    if (d) {
        int s = d->st;
        if (s == 1 || s == 3)
            d = 0;
    }
    n = d;
}
