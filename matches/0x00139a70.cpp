class X_139a70 {
  public:
    char pad[0x20];
    int value;
    bool Set(int x);
};

bool X_139a70::Set(int x) {
    value = x;
    return true;
}
