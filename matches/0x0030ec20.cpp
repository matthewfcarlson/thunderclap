// Same code shape as 0x00098e20 (propagated; names are from that function)
class A_30ec20 {
    char pad[12];
    int value;

  public:
    void Set(int x);
};
void A_30ec20::Set(int x) {
    value = x;
}