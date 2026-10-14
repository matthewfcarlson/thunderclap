struct Src {
    int a, b, c;
};

class Obj {
  public:
    char Set(Src* p);
    char pad[18];
    int m14, m18, m1c;
};

char Obj::Set(Src* p) {
    m14 = p->a;
    m18 = p->b;
    m1c = p->c;
    return 1;
}