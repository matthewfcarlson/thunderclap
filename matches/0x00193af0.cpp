class Src {
  public:
    int a;
    int b;
    int c;
};

class Target {
  public:
    char pad[0x80];
    int m80;
    int m84;
    int m88;
    char Fn(Src* p);
};

char Target::Fn(Src* p) {
    m80 = p->a;
    m84 = p->b;
    m88 = p->c;
    return 1;
}
