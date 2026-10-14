// Same code shape as 0x00083d50 (propagated; names are from that function)
class C_2b18b0 {
    char pad[0x20];

  public:
    int value;
    void set(int x);
};
void C_2b18b0::set(int x) {
    value = x;
}