class O_16f670 {
  public:
    char pad[0x20];
    int m20;
    bool Set(int);
};

bool O_16f670::Set(int x) {
    m20 = x;
    return true;
}