class X_14d060 {
  public:
    char pad[0x24];
    int value;
    bool Set(int x);
};

bool X_14d060::Set(int x) {
    value = x;
    return true;
}
