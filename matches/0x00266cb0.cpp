class Stream {
  public:
    virtual void f0();
    char pad[0xb];
    char m0f;
    void Read(void* p, int a, int b, int c);
};
class Obj_266cb0 {
  public:
    Obj_266cb0* Init(Stream* s);
    void Next(unsigned int v);
    char m0;
    char pad[0x27f];
    int m280;
    Stream* m284;
};
Obj_266cb0* Obj_266cb0::Init(Stream* s) {
    unsigned int v;
    m280 = -1;
    m284 = s;
    m0 = 0;
    s->f0();
    m284->Read(&v, 4, 1, 1);
    if (v == 0x503344ff) {
        m284->m0f = (m284->m0f == 0);
        v = 0xff443350;
    }
    Next(v);
    return this;
}
