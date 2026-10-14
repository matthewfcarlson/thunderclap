class C_e0300 {
  public:
    char pad[0x1800];
    int a;
    int b;
    int c;
    void Set(int x, int y, int z);
};
void C_e0300::Set(int x, int y, int z) {
    a = x;
    b = y;
    c = z;
}