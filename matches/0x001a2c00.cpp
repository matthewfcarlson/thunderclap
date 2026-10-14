class C_1a2c00 {
  public:
    char pad[0x169];
    unsigned char mValue;
    bool Set(unsigned char value);
};

bool C_1a2c00::Set(unsigned char value) {
    mValue = value;
    return true;
}
