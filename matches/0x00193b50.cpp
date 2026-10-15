struct Src {
    int a, b, c;
};
class Obj {
  public:
    char pad[0x8c];
    int m8c;
    int m90;
    int m94;
    unsigned char Set(Src* s);
};
unsigned char Obj::Set(Src* s) {
    m8c = s->a;
    m90 = s->b;
    m94 = s->c;
    return 1;
}
