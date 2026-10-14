struct Src {
    int a;
    int b;
    int c;
};

class Obj {
  public:
    char pad[0x20];
    int m20;
    int m24;
    int m28;
    bool Set(Src* p);
};

bool Obj::Set(Src* p) {
    m20 = p->a;
    m24 = p->b;
    m28 = p->c;
    return true;
}
