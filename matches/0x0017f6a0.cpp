class C_17f6a0 {
  public:
    char pad[12];
    unsigned char mValue;
    bool Set(unsigned char x);
};

bool C_17f6a0::Set(unsigned char x) {
    mValue = x;
    return true;
}
