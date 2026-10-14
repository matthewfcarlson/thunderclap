class X_11bac0 {
  public:
    bool Set(int value);
    char pad[0x38];
    int m38;
};

bool X_11bac0::Set(int value) {
    m38 = value;
    return true;
}
