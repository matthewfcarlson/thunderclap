struct Src {
    int a, b, c;
};
class Obj {
  public:
    char pad[0x20];
    int x;
    int y;
    int z;
    bool Set(Src* s);
};
bool Obj::Set(Src* s) {
    x = s->a;
    y = s->b;
    z = s->c;
    return true;
}
