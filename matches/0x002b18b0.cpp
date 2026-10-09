// Same code shape as 0x00083d50 (propagated; names are from that function)
class C {
    char pad[0x20];

  public:
    int value;
    void set(int x);
};
void C::set(int x) {
    value = x;
}