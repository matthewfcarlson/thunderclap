class C_80e30 {
    char pad[0x64];
    int a, b, c;

  public:
    void f(int* p);
};
void C_80e30::f(int* p) {
    a = p[0];
    b = p[1];
    c = p[2];
}