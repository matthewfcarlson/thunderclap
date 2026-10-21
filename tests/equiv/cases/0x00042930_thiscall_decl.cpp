class C_42930 {
  public:
    char pad0[0x118];
    unsigned char flag;
    char pad1[0x314 - 0x119];
    float scale;
    char pad2[0x338 - 0x318];
    int field338;
    void target(int, float);
};
struct ThisCall_00042890 {
    void helper(int, float);
};
void C_42930::target(int a, float b) {
    if (!flag && field338 == 0)
        ((ThisCall_00042890*)(this))->helper(a, b * scale);
}