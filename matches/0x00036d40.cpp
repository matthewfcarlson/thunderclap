class C_36d40 {
    char pad[0x2144];
    int value;

  public:
    void f(int x);
};
void C_36d40::f(int x) {
    if (x >= 0 && x < 0xe)
        value = x;
}