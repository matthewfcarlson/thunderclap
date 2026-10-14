struct Src {
    int a;
    int b;
    int c;
};
class Obj {
  public:
    char pad[0x18];
    int m18;
    int m1c;
    int m20;
    bool Set(Src* s);
};
bool Obj::Set(Src* s) {
    m18 = s->a;
    m1c = s->b;
    m20 = s->c;
    return true;
}
