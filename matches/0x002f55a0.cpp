// Same code shape as 0x00083d20 (propagated; names are from that function)
class Thing {
    char pad[0x10];

  public:
    int value;
    void Set(int x);
};
void Thing::Set(int x) {
    value = x;
}