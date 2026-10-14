struct Src_11b960 {
    int a, b, c;
};
class Obj_11b960 {
  public:
    char pad[0x20];
    int x;
    int y;
    int z;
    bool Set(Src_11b960* s);
};
bool Obj_11b960::Set(Src_11b960* s) {
    x = s->a;
    y = s->b;
    z = s->c;
    return true;
}
