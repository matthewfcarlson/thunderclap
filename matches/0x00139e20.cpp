class O {
  public:
    char pad[0x38];
    int value;
    bool Set(int x);
};
bool O::Set(int x) {
    value = x;
    return 1;
}
