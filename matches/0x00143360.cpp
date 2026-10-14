struct Src {
    int a;
    int b;
    int c;
};
class C {
  public:
    char pad[0x24];
    int m24;
    int m28;
    int m2c;
    bool Set(Src* p);
};
bool C::Set(Src* p) {
    m24 = p->a;
    m28 = p->b;
    m2c = p->c;
    return true;
}
