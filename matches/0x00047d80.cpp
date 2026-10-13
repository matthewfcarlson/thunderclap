class X {
  public:
    char pad[0x10];
    int m;
    bool Set(int v);
};
bool X::Set(int v) {
    m = v;
    return true;
}
