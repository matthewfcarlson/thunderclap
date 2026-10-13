class O {
    char pad[0x14];
    int m14;

  public:
    bool Set(int x);
};
bool O::Set(int x) {
    m14 = x;
    return true;
}
