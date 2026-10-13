class O {
  public:
    bool Set(int x);
    char pad[12];
    int m;
};
bool O::Set(int x) {
    m = x;
    return true;
}