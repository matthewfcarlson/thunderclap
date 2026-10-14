class A_686f0 {
  public:
    char pad[0x80];
    int m80;
    bool Set(int x);
};

bool A_686f0::Set(int x) {
    m80 = x;
    return true;
}
