class X {
  public:
    bool Set(int v);
    char pad[12];
    int m;
};
bool X::Set(int v) {
    m = v;
    return true;
}
