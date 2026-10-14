typedef unsigned int u32_1d4e00;
class C_1d4e00 {
  public:
    char pad[0xa8];
    u32_1d4e00 value;
    u32_1d4e00 f();
};
u32_1d4e00 C_1d4e00::f() {
    return value;
}