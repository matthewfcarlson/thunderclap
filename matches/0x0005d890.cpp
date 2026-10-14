struct S {
    int a;
    int b;
    int c;
};
class O {
  public:
    char pad[0x18];
    int m18;
    int m1c;
    int m20;
    bool Set(const S* p);
};
bool O::Set(const S* p) {
    m18 = p->a;
    m1c = p->b;
    m20 = p->c;
    return true;
}