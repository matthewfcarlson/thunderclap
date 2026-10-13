class X {
  public:
    char pad[12];
    int m12;
    bool Fn(int v);
};
bool X::Fn(int v) {
    m12 = v;
    return true;
}