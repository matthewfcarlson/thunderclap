struct S {
    int a, b, c;
};
class O {
    char pad[0x38];
    int x, y, z;

  public:
    bool Set(S* p);
};
bool O::Set(S* p) {
    x = p->a;
    y = p->b;
    z = p->c;
    return true;
}
