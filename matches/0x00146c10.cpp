class X {
  public:
    char pad[0x14];
    int m;
    bool Fn(int a);
};
bool X::Fn(int a) {
    m = a;
    return true;
}
