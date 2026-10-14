class X_139ee0 {
  public:
    char pad[0x28];
    int value;
    bool Set(int x);
};

bool X_139ee0::Set(int x) {
    value = x;
    return true;
}
