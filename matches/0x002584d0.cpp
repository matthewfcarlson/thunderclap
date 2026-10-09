class Type {
  public:
    virtual void f();
    int pad[9];
    int a, b, c, d, e, g;
    Type(int* p, int* q, int r, int s);
};
Type::Type(int* p, int* q, int r, int s) {
    a = p[0];
    b = p[1];
    c = q[0];
    d = q[1];
    e = r;
    g = s;
}