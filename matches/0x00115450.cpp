struct S_115450 {
    int a;
    int b;
    int c;
};

class T_115450 {
  public:
    char pad0[0x18];
    int m18;
    int m1c;
    int m20;
    char Fn(const S_115450* p);
};

char T_115450::Fn(const S_115450* p) {
    m18 = p->a;
    m1c = p->b;
    m20 = p->c;
    return 1;
}
