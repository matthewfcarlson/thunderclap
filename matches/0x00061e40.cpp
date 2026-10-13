class O {
  public:
    char pad[0x10];
    int m;
    bool Set(int v);
};
bool O::Set(int v) {
    m = v;
    return true;
}
