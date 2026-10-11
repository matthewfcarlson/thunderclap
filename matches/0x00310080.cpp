extern void* g_vftable[];
void* operator new(unsigned);
void* operator new[](unsigned);
class Res {
  public:
    virtual void F0();
};
class Holder {
  public:
    virtual void F0();
    Holder* Init(Res* r);
};
class Obj {
  public:
    void* vptr;
    int m4;
    Res* m8;
    Holder* mc;
    int m10;
    int m14;
    int** m18;
    int** m1c;
    Obj* ctor(Res* a0, int a1, int a2);
};
Obj* Obj::ctor(Res* a0, int a1, int a2) {
    m4 = 0;
    vptr = g_vftable;
    m10 = a1;
    m14 = a2;
    Holder* h = (Holder*)operator new(0x10);
    if (h)
        h = h->Init(a0);
    else
        h = 0;
    mc = h;
    h->F0();
    m8 = a0;
    a0->F0();
    m18 = (int**)operator new[](m10 * 4);
    m1c = (int**)operator new[](m10 * 4);
    for (int i = 0; i < m10; i++) {
        m18[i] = 0;
        m1c[i] = (int*)operator new[](m14 * 4);
    }
    return this;
}
