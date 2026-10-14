class Thing_302ef0 {
  public:
    char pad0[4];
    int a;
    int b;
    char pad10[0x30];
    int c;
    void Init();
    void Set(int x, int y, int z);
};
void Thing_302ef0::Set(int x, int y, int z) {
    c = z;
    a = x;
    b = y;
    Init();
}