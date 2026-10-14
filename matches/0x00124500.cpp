class X_124500 {
  public:
    char pad[0x1d54];
    int a;
    int b;
    int c;
    void f(int* out);
};
void X_124500::f(int* out) {
    out[0] = a;
    out[1] = b;
    out[2] = c;
}