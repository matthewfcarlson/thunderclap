class X {
  public:
    bool Set(int value);
    char pad[0x38];
    int m38;
};

bool X::Set(int value) {
    m38 = value;
    return true;
}
