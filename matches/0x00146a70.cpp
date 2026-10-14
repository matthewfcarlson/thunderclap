struct Src {
    int a, b, c;
};

class Owner {
  public:
    char pad[0x10];
    int m10, m14, m18;
    char Set(Src* p);
};

char Owner::Set(Src* p) {
    m10 = p->a;
    m14 = p->b;
    m18 = p->c;
    return 1;
}