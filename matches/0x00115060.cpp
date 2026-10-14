class X_115060 {
  public:
    char pad[0x14];
    int m;
    bool Set(int x);
};

bool X_115060::Set(int x) {
    m = x;
    return true;
}
