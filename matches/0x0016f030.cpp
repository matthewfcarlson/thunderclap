class X_16f030 {
  public:
    char pad[0x50];
    int mValue;
    bool Set(int value);
};

bool X_16f030::Set(int value) {
    mValue = value;
    return true;
}
