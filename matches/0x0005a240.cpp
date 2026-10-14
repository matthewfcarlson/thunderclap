struct S {
    int a, b, c;
};
class C {
  public:
    char pad[0x24];
    S s;
    bool Set(const S* o);
};
bool C::Set(const S* o) {
    s.a = o->a;
    s.b = o->b;
    s.c = o->c;
    return true;
}
