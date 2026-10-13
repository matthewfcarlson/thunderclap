class O {
  public:
    char pad[0x14];
    int v;
    bool Set(int x);
};

bool O::Set(int x) {
    v = x;
    return true;
}
