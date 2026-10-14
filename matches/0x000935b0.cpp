extern void* gG_935b0[];
extern void* gB_935b0[];
void operator delete(void*);
void operator delete[](void*);
struct S_935b0 {
    int a, b;
    void Fini();
};
class Gal {
  public:
    void* vptr;
    char pad[0x10 - 4];
    S_935b0 s10;
    void* m18;
    char pad2[0xa8 - 0x1c];
    S_935b0 sa8;
    Gal* f0(unsigned char flags);
};
Gal* Gal::f0(unsigned char flags) {
    vptr = gG_935b0;
    sa8.Fini();
    void* p = m18;
    vptr = gB_935b0;
    if (p) {
        operator delete[](p);
        m18 = 0;
    }
    s10.Fini();
    if (flags & 1)
        operator delete(this);
    return this;
}
