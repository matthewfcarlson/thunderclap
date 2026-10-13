class X {
  public:
    bool Set(int v);

  private:
    char pad[0x20];
    int m20;
};
bool X::Set(int v) {
    m20 = v;
    return true;
}