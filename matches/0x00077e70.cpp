class A_77e70 {
  public:
    char pad[0x24];
    int mField;
    bool Set(int x);
};

bool A_77e70::Set(int x) {
    mField = x;
    return true;
}
