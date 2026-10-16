class Obj {
  public:
    char pad[8];
    int a, b, c, d;
    void Get(int* x, int* y, int* z, int* w);
};
void Obj::Get(int* x, int* y, int* z, int* w) {
    *x = a;
    *y = b;
    *z = c;
    *w = d;
}