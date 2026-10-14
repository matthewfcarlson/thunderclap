class O {
  public:
    char pad[0xc];
    int m;
    bool Fn(int v);
};
bool O::Fn(int v) {
    m = v;
    return true;
}
