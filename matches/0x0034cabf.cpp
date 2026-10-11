// cl-flags: /O1
extern void* vt[];
struct DName {
    int pad;
    int st : 4;
};
class O {
  public:
    void* vptr;
    int a;
    DName* n;
    O(DName* d) throw();
};
O::O(DName* d) throw() {
    a = 0;
    vptr = vt;
    if (d) {
        int s = d->st;
        if (s == 1 || s == 3)
            d = 0;
    }
    n = d;
}
