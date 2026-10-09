class C {
  public:
    char pad[0x1d54];
    int a;
    int b;
    int c;
    void f(int* p);
};
void C::f(int* p) {
    a = p[0];
    b = p[1];
    c = p[2];
}