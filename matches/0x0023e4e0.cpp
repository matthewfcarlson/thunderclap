class X_23e4e0 {
  public:
    char pad[0x10];
    int value;
    bool Set(int value);
};

bool X_23e4e0::Set(int value) {
    this->value = value;
    return true;
}