class X {
  public:
    char pad[0x34];
    int value;
    bool Set(int v);
};
bool X::Set(int v) {
    value = v;
    return true;
}
