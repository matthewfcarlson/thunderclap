class C_ada30 {
    char pad[0x5c];
    int a[13];

  public:
    void f(int);
};
void C_ada30::f(int i) {
    if (i >= 0 && i < 13)
        a[i] = 0;
}