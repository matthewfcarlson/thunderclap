class Obj {
  public:
    int F(int a, int b);
    int G(int a, int b);
};
int __stdcall lookup(int);
int Obj::F(int a, int b) {
    int n = lookup(a);
    if (n >= 0)
        return G(n, b);
    return -1;
}