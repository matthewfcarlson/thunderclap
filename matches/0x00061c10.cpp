struct Src {
    int a;
    int b;
    int c;
};

class Obj {
  public:
    char pad[0xa4];
    int m1;
    int m2;
    int m3;
    bool Set(Src* s);
};

bool Obj::Set(Src* s) {
    m1 = s->a;
    m2 = s->b;
    m3 = s->c;
    return true;
}
