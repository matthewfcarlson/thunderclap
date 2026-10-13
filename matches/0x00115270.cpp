class Target {
  public:
    char pad[0x24];
    int mValue;
    bool Set(int x);
};

bool Target::Set(int x) {
    mValue = x;
    return true;
}
