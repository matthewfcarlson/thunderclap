class O {
  public:
    char pad[0xdc];
    int m;
    bool Set(int x);
};
bool O::Set(int x) {
    m = x;
    return true;
}
