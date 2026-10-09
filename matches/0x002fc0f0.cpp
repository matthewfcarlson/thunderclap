// Same code shape as 0x00284ad0 (propagated; names are from that function)
class C {
    char pad[0x10];

  public:
    unsigned char value;
    void Set(unsigned char x);
};
void C::Set(unsigned char x) {
    value = x;
}