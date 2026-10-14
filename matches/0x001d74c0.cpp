class First_1d74c0 {
  public:
    virtual void A();
};
class Second_1d74c0 {
  public:
    virtual void A();
    virtual void B();
};
class Obj_1d74c0 {
  public:
    char pad[0x120];
    First_1d74c0* ptr;
    int a;
    int b;
    unsigned char c;
    void whatever(First_1d74c0*, int, int, unsigned char);
};
void Obj_1d74c0::whatever(First_1d74c0* p, int x, int y, unsigned char z) {
    if (p)
        p->A();
    Second_1d74c0* old = (Second_1d74c0*)ptr;
    if (old)
        old->B();
    ptr = p;
    b = y;
    a = x;
    c = z;
}