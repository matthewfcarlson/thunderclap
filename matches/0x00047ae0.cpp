class O {
  public:
    char pad[0x18];
    int mValue;
    bool Fn(int x);
};

bool O::Fn(int x) {
    mValue = x;
    return true;
}
