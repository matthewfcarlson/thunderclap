class X_15b660 {
  public:
    char pad[0x5c];
    int m5c;
    bool Set(int v);
};

bool X_15b660::Set(int v) {
    m5c = v;
    return true;
}
