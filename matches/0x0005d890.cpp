struct S_5d890 {
    int a;
    int b;
    int c;
};
class O_5d890 {
  public:
    char pad[0x18];
    int m18;
    int m1c;
    int m20;
    bool Set(const S_5d890* p);
};
bool O_5d890::Set(const S_5d890* p) {
    m18 = p->a;
    m1c = p->b;
    m20 = p->c;
    return true;
}