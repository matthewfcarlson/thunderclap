struct Src_16ef80 {
    int a;
    int b;
    int c;
};
class Obj_16ef80 {
  public:
    char pad[0x34];
    int x;
    int y;
    int z;
    bool Set(Src_16ef80* s);
};
bool Obj_16ef80::Set(Src_16ef80* s) {
    x = s->a;
    y = s->b;
    z = s->c;
    return true;
}