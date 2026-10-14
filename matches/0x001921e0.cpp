struct Src_1921e0 {
    int a, b, c;
};
class Obj_1921e0 {
  public:
    char pad[0x20];
    int m20, m24, m28;
    bool Set(Src_1921e0* p);
};
bool Obj_1921e0::Set(Src_1921e0* p) {
    m20 = p->a;
    m24 = p->b;
    m28 = p->c;
    return true;
}
