struct Src {
    int a;
    int b;
    int c;
};

class Obj {
  public:
    char pad[0x10c];
    int m10c;
    int m110;
    int m114;
    bool Set(Src* s);
};

bool Obj::Set(Src* s) {
    m10c = s->a;
    m110 = s->b;
    m114 = s->c;
    return true;
}
