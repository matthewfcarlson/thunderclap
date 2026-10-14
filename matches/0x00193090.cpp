struct Src_193090 {
    int a;
    int b;
    int c;
};
class Obj_193090 {
  public:
    char pad[0x4c];
    int x;
    int y;
    int z;
    bool Set(Src_193090* s);
};
bool Obj_193090::Set(Src_193090* s) {
    x = s->a;
    y = s->b;
    z = s->c;
    return true;
}
