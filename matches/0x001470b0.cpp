class Target {
  public:
    char pad[0x10];
    int mField;
    bool Set(int x);
};

bool Target::Set(int x) {
    mField = x;
    return true;
}
