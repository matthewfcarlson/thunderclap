// Same code shape as 0x00083d20 (propagated; names are from that function)
class Thing_1c3770 {
    char pad[0x10];

  public:
    int value;
    void Set(int x);
};
void Thing_1c3770::Set(int x) {
    value = x;
}