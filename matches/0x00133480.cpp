class X_133480 {
  public:
    bool Set(int v);

  private:
    char pad[0x10];
    int m;
};
bool X_133480::Set(int v) {
    m = v;
    return true;
}