struct Src_143360 {
    int a;
    int b;
    int c;
};
class C_143360 {
  public:
    char pad[0x24];
    int m24;
    int m28;
    int m2c;
    bool Set(Src_143360* p);
};
bool C_143360::Set(Src_143360* p) {
    m24 = p->a;
    m28 = p->b;
    m2c = p->c;
    return true;
}
