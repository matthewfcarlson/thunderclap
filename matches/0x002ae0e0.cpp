// Same code shape as 0x00083d70 (propagated; names are from that function)
class C {
    char pad[0x28];
    int value;

  public:
    void Set(int x);
};
void C::Set(int x) {
    value = x;
}