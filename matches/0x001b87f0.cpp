class C {
    char pad[0x40];
    int a, b, c;

  public:
    void F(int x, int y, int z);
};
void C::F(int x, int y, int z) {
    a = x;
    b = y;
    c = z;
}