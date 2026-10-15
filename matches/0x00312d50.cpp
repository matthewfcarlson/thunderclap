class Obj {
  public:
    char pad[0x2004];
    char flag;
    char gap[15];
    int a, b, c, d, e, f, g;
    Obj();
};
Obj::Obj() {
    flag = 0;
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    e = 0;
    f = 0;
    g = 0;
}