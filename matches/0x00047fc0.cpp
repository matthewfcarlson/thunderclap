class X {
  public:
    char pad[12];
    int m;
    bool Set(int v);
};

bool X::Set(int v) {
    m = v;
    return true;
}
