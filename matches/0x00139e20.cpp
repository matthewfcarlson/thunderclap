class O_139e20 {
  public:
    char pad[0x38];
    int value;
    bool Set(int x);
};
bool O_139e20::Set(int x) {
    value = x;
    return 1;
}
