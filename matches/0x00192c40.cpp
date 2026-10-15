struct In {
    int a;
    int b;
    int c;
};
class Obj {
  public:
    char pad[0xd4];
    int x;
    int y;
    int z;
    bool Set(In* p);
};
bool Obj::Set(In* p) {
    x = p->a;
    y = p->b;
    z = p->c;
    return true;
}
