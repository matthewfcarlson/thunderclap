class O_18f0a0 {
  public:
    char pad[0x60];
    int value;
    bool Set(int x);
};

bool O_18f0a0::Set(int x) {
    value = x;
    return true;
}
