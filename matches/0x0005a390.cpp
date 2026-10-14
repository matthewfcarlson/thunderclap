struct S_5a390 {
    int a;
    int b;
    int c;
};
class O_5a390 {
  public:
    char pad[0x20];
    int x;
    int y;
    int z;
    bool Set(S_5a390* p);
};
bool O_5a390::Set(S_5a390* p) {
    x = p->a;
    y = p->b;
    z = p->c;
    return true;
}
