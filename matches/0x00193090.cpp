struct Src {
    int a;
    int b;
    int c;
};
class Obj {
  public:
    char pad[0x4c];
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
