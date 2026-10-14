class X_180230 {
  public:
    char pad[0x1c];
    int mValue;
    bool Set(int value);
};

bool X_180230::Set(int value) {
    mValue = value;
    return true;
}
