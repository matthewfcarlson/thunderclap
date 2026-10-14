struct S {
    int a;
    int b;
    int c;
};

class T {
  public:
    char pad0[0x18];
    int m18;
    int m1c;
    int m20;
    char Fn(const S* p);
};

char T::Fn(const S* p) {
    m18 = p->a;
    m1c = p->b;
    m20 = p->c;
    return 1;
}
