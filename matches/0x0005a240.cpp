struct S_5a240 {
    int a, b, c;
};
class C_5a240 {
  public:
    char pad[0x24];
    S_5a240 s;
    bool Set(const S_5a240* o);
};
bool C_5a240::Set(const S_5a240* o) {
    s.a = o->a;
    s.b = o->b;
    s.c = o->c;
    return true;
}
