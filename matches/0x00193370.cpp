class X {
  public:
    char pad[0x96];
    unsigned char GetValue();
};
unsigned char X::GetValue() {
    return pad[0x96];
}
