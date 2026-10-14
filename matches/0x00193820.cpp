struct Src;
class Obj {
  public:
    char pad[0x1c];
    int m1c;
    int m20;
    int m24;
    bool Set(const struct Src* s);
};

struct Src {
    int a;
    int b;
    int c;
};

bool Obj::Set(const struct Src* s) {
    m1c = s->a;
    m20 = s->b;
    m24 = s->c;
    return true;
}
