class Inner {
  public:
    void g(int, int);
};
class Obj {
    char p0[0x6e0];
    int n;
    char p1[0x56];

  public:
    struct Item {
        Inner in;
        char pad[0x57];
    } items[1];
    char p2[0x4d6];
    int lim;
    bool f(int a, int b, int x);
};
bool Obj::f(int a, int b, int x) {
    if (a < 0 || a >= lim)
        return false;
    if (b < 0 || b >= n)
        return false;
    items[a].in.g(b, x);
    return true;
}