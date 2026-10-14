struct Src_133830 {
    int a;
    int b;
    int c;
};
class T_133830 {
  public:
    char pad[0x14];
    int m14;
    int m18;
    int m1c;
    bool Set(const Src_133830* p);
};
bool T_133830::Set(const Src_133830* p) {
    m14 = p->a;
    m18 = p->b;
    m1c = p->c;
    return true;
}
