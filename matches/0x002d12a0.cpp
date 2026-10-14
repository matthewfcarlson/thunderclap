class C_2d12a0 {
    char pad0[0x10];
    int a;
    char pad1[0x0c];
    int b;

  public:
    void Set(int x, int y);
};
void C_2d12a0::Set(int x, int y) {
    a = x;
    b = y;
}