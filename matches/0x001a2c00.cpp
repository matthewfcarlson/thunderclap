class C {
  public:
    char pad[0x169];
    unsigned char mValue;
    bool Set(unsigned char value);
};

bool C::Set(unsigned char value) {
    mValue = value;
    return true;
}
