struct S {
    int a;
    int b;
    int c;
};

class A {
  public:
    char pad[0x98];
    int m1;
    int m2;
    int m3;
    bool Set(const S* p);
};

bool A::Set(const S* p) {
    m1 = p->a;
    m2 = p->b;
    m3 = p->c;
    return true;
}
