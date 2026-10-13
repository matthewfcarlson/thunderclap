class X {
  public:
    char pad[16];
    int m10;
    bool Set(int value);
};
bool X::Set(int value) {
    m10 = value;
    return true;
}