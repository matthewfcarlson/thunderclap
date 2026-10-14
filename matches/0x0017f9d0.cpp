class C_17f9d0 {
  public:
    char pad[0x2c];
    int mValue;
    bool Set(int value);
};

bool C_17f9d0::Set(int value) {
    mValue = value;
    return true;
}
