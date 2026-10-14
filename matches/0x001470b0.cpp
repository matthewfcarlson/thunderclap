class Target_1470b0 {
  public:
    char pad[0x10];
    int mField;
    bool Set(int x);
};

bool Target_1470b0::Set(int x) {
    mField = x;
    return true;
}
