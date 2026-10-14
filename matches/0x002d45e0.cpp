// Same code shape as 0x001d4e00 (propagated; names are from that function)
typedef unsigned int u32_2d45e0;
class C_2d45e0 {
  public:
    char pad[0xa8];
    u32_2d45e0 value;
    u32_2d45e0 f();
};
u32_2d45e0 C_2d45e0::f() {
    return value;
}