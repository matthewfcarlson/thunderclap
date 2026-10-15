struct Src {
    int a;
    int b;
    int c;
};
class Tgt {
  public:
    char pad[0x11c];
    int x;
    int y;
    int z;
    bool Copy(Src* s);
};
bool Tgt::Copy(Src* s) {
    x = s->a;
    y = s->b;
    z = s->c;
    return true;
}