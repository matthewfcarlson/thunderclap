class O {
  public:
    char pad[0x30];
    int m30;
    bool Set(int x);
};
bool O::Set(int x) {
    m30 = x;
    return true;
}
