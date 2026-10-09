class First {
  public:
    virtual void A();
};
class Second {
  public:
    virtual void A();
    virtual void B();
};
class Obj {
  public:
    char pad[0x120];
    First* ptr;
    int a;
    int b;
    unsigned char c;
    void whatever(First*, int, int, unsigned char);
};
void Obj::whatever(First* p, int x, int y, unsigned char z) {
    if (p)
        p->A();
    Second* old = (Second*)ptr;
    if (old)
        old->B();
    ptr = p;
    b = y;
    a = x;
    c = z;
}