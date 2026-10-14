extern void* g_vftable_310080[];
void* operator new(unsigned);
void* operator new[](unsigned);
class Res_310080 {
  public:
    virtual void F0();
};
class Holder_310080 {
  public:
    virtual void F0();
    Holder_310080* Init(Res_310080* r);
};
class Obj_310080 {
  public:
    void* vptr;
    int m4;
    Res_310080* m8;
    Holder_310080* mc;
    int m10;
    int m14;
    int** m18;
    int** m1c;
    Obj_310080* ctor(Res_310080* a0, int a1, int a2);
};
Obj_310080* Obj_310080::ctor(Res_310080* a0, int a1, int a2) {
    m4 = 0;
    vptr = g_vftable_310080;
    m10 = a1;
    m14 = a2;
    Holder_310080* h = (Holder_310080*)operator new(0x10);
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
