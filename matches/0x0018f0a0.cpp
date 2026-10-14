class O {
  public:
    char pad[0x60];
    int value;
    bool Set(int x);
};

bool O::Set(int x) {
    value = x;
    return true;
}
