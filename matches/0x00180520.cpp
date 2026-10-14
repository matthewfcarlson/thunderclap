struct S_180520 {
    int a, b, c;
};
class O_180520 {
    char pad[0x38];
    int x, y, z;

  public:
    bool Set(S_180520* p);
};
bool O_180520::Set(S_180520* p) {
    x = p->a;
    y = p->b;
    z = p->c;
    return true;
}
