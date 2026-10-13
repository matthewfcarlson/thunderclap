class X {
  public:
    char pad[12];
    int m;
    bool F(int v);
};

bool X::F(int v) {
    m = v;
    return true;
}
