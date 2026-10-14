// Same code shape as 0x00098e20 (propagated; names are from that function)
class A_d6f00 {
    char pad[12];
    int value;

  public:
    void Set(int x);
};
void A_d6f00::Set(int x) {
    value = x;
}