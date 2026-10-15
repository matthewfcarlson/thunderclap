struct Src {
    int a;
    int b;
    int c;
};

class Thing {
  public:
    char pad[0x9c];
    Src s;
    bool Set(const Src* p);
};

bool Thing::Set(const Src* p) {
    s.a = p->a;
    s.b = p->b;
    s.c = p->c;
    return true;
}
