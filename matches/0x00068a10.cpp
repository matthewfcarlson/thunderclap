struct In {
    int a;
    int b;
    int c;
};
class Obj {
  public:
    char pad[0x2c];
    int m1;
    int m2;
    int m3;
    bool Set(In* p);
};
bool Obj::Set(In* p) {
    m1 = p->a;
    m2 = p->b;
    m3 = p->c;
    return true;
}
