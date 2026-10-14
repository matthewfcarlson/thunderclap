class X_16f8e0 {
  public:
    char pad[0x14];
    int m;
    bool Set(int x);
};

bool X_16f8e0::Set(int x) {
    m = x;
    return true;
}
