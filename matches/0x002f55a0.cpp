// Same code shape as 0x00083d20 (propagated; names are from that function)
class Thing_2f55a0 {
    char pad[0x10];

  public:
    int value;
    void Set(int x);
};
void Thing_2f55a0::Set(int x) {
    value = x;
}