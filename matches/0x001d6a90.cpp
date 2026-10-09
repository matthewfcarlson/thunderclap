class Target {
  public:
    char pad[0x1e0];
    unsigned char value;
    unsigned char GetValue();
};
unsigned char Target::GetValue() {
    return value;
}