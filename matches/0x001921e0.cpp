struct Src {
    int a, b, c;
};
class Obj {
  public:
    char pad[0x20];
    int m20, m24, m28;
    bool Set(Src* p);
};
bool Obj::Set(Src* p) {
    m20 = p->a;
    m24 = p->b;
    m28 = p->c;
    return true;
}
