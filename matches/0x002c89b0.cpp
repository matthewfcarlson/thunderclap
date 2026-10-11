extern int vt1, vt2;
extern void Free(void*);
class Ref {
  public:
    virtual void f0();
    virtual void Release();
};
class D {
  public:
    void* vptr;
    int a4, a8, ac, a10;
    void *p14, *p18, *p1c, *p20, *p24, *p28, *p2c, *p30, *p34;
    void* q[4];
    void* r[2];
    void *p50, *p54;
    Ref* a58;
    ~D();
};
D::~D() {
    vptr = &vt1;
    Free(p14);
    Free(p18);
    Free(p1c);
    Free(p20);
    Free(p24);
    Free(p28);
    Free(p2c);
    Free(p30);
    Free(p34);
    for (int i = 0; i < 4; i++)
        Free(q[i]);
    for (int i = 0; i < 2; i++)
        Free(r[i]);
    Free(p50);
    Free(p54);
    if (a58) {
        a58->Release();
        a58 = 0;
    }
    vptr = &vt2;
}
