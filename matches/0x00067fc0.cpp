class O {
  public:
    char pad[0xc];
    int m;
    bool Fn(int x);
};
bool O::Fn(int x) {
    m = x;
    return true;
}
