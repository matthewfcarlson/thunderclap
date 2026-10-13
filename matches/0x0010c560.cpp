class O {
  public:
    bool Set(int v);
    char pad[0xc];
    int m;
};

bool O::Set(int v) {
    m = v;
    return true;
}
