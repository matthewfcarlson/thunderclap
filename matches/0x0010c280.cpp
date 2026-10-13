class O {
  public:
    char pad[0xc];
    int m;
    bool F(int x);
};
bool O::F(int x) {
    m = x;
    return true;
}
