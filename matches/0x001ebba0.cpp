class C_1ebba0 {
  public:
    C_1ebba0* Set(int x, int y);
    int a;
    int b;
};
C_1ebba0* g_1ebba0;
C_1ebba0* C_1ebba0::Set(int x, int y) {
    g_1ebba0 = this;
    a = x;
    b = y;
    return this;
}
