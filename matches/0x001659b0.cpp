class X {
  public:
    char pad[0xc];
    int mValue;
    bool Set(int value);
};

bool X::Set(int value) {
    mValue = value;
    return true;
}
