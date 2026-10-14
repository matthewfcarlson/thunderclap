struct D {
    char pad[0x1a4];
    int v;
};
class C_36270 {
  public:
    char pad[0x11c];
    D* p;
    char pad2[0x1f8];
    int a;
    int b;
    int f();
};
int C_36270::f() {
    int x = 0;
    if (p != 0)
        x = p->v;
    return b + a + x;
}