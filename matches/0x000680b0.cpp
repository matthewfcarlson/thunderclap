class X {
  public:
    char pad[0x4c];
    int m;
    bool Set(int v);
};
bool X::Set(int v) {
    m = v;
    return true;
}
