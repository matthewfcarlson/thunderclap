class Obj {
  public:
    int F(int a, int b);
    int G(int a, int b);
};
struct This_lookup {
    int lookup(int);
};
int Obj::F(int a, int b) {
    int n = ((This_lookup*)this)->lookup(a);
    if (n >= 0)
        return G(n, b);
    return -1;
}