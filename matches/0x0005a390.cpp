struct S {
    int a;
    int b;
    int c;
};
class O {
  public:
    char pad[0x20];
    int x;
    int y;
    int z;
    bool Set(S* p);
};
bool O::Set(S* p) {
    x = p->a;
    y = p->b;
    z = p->c;
    return true;
}
