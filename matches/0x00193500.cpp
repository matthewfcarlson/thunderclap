class X {
  public:
    char pad[0xd4];
    int mValue;
    bool Set(int a);
};

bool X::Set(int a) {
    mValue = a;
    return true;
}
