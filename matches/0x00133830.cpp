struct Src {
    int a;
    int b;
    int c;
};
class T {
  public:
    char pad[0x14];
    int m14;
    int m18;
    int m1c;
    bool Set(const Src* p);
};
bool T::Set(const Src* p) {
    m14 = p->a;
    m18 = p->b;
    m1c = p->c;
    return true;
}
