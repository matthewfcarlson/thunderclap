class Thing_16efd0 {
  public:
    char pad[0x44];
    int mValue;
    bool Set(int x);
};

bool Thing_16efd0::Set(int x) {
    mValue = x;
    return true;
}