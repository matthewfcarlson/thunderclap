class O {
    char pad[0x10];
    int m;

  public:
    bool F(int x);
};
bool O::F(int x) {
    m = x;
    return true;
}
