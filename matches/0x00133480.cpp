class X {
  public:
    bool Set(int v);

  private:
    char pad[0x10];
    int m;
};
bool X::Set(int v) {
    m = v;
    return true;
}