class X {
  public:
    char pad[0x10];
    int value;
    bool Set(int value);
};

bool X::Set(int value) {
    this->value = value;
    return true;
}