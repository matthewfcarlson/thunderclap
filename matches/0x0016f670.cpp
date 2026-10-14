class O {
  public:
    char pad[0x20];
    int m20;
    bool Set(int);
};

bool O::Set(int x) {
    m20 = x;
    return true;
}