class X_123900 {
  public:
    char pad[16];
    int m10;
    bool Set(int value);
};
bool X_123900::Set(int value) {
    m10 = value;
    return true;
}