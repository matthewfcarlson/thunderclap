struct Src {
    int a;
    int b;
    int c;
};

class Obj {
  public:
    char pad[0x14];
    int m14;
    int m18;
    int m1c;
    unsigned char Fn(Src* p);
};

unsigned char Obj::Fn(Src* p) {
    m14 = p->a;
    m18 = p->b;
    m1c = p->c;
    return 1;
}
