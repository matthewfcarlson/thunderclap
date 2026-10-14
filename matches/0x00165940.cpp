class X {
    char pad[12];
    int m;

  public:
    bool Set(int v);
};
bool X::Set(int v) {
    m = v;
    return true;
}
