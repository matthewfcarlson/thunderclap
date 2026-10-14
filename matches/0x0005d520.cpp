class X_5d520 {
  public:
    char pad[0x34];
    int value;
    bool Set(int v);
};

bool X_5d520::Set(int v) {
    value = v;
    return true;
}