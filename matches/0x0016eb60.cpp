struct S {
    int a;
    int b;
    int c;
};
class C {
  public:
    char pad[0x24];
    int x;
    int y;
    int z;
    bool operator=(S* p);
};
bool C::operator=(S* p) {
    x = p->a;
    y = p->b;
    z = p->c;
    return true;
}
