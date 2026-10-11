extern void* gG[];
extern void* gB[];
void operator delete(void*);
void operator delete[](void*);
struct S {
    int a, b;
    void Fini();
};
class Gal {
  public:
    void* vptr;
    char pad[0x10 - 4];
    S s10;
    void* m18;
    char pad2[0xa8 - 0x1c];
    S sa8;
    Gal* f0(unsigned char flags);
};
Gal* Gal::f0(unsigned char flags) {
    vptr = gG;
    sa8.Fini();
    void* p = m18;
    vptr = gB;
    if (p) {
        operator delete[](p);
        m18 = 0;
    }
    s10.Fini();
    if (flags & 1)
        operator delete(this);
    return this;
}
