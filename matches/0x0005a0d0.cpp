class O {
  public:
    char pad[12];
    int m;
    bool Set(int x);
};
bool O::Set(int x) {
    m = x;
    return true;
}
