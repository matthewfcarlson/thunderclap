// Same code shape as 0x00083d70 (propagated; names are from that function)
class C_3270a0 {
    char pad[0x28];
    int value;

  public:
    void Set(int x);
};
void C_3270a0::Set(int x) {
    value = x;
}