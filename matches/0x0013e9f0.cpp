class O {
  public:
    char pad[0x54];
    int mValue;
    bool Set(int x);
};

bool O::Set(int x) {
    mValue = x;
    return true;
}