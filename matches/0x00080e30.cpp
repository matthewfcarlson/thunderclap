class C {
    char pad[0x64];
    int a, b, c;

  public:
    void f(int* p);
};
void C::f(int* p) {
    a = p[0];
    b = p[1];
    c = p[2];
}