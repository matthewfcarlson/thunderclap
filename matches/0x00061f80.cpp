class A_61f80 {
  public:
    char pad[0x14];
    int value;
    bool Set(int x);
};
bool A_61f80::Set(int x) {
    value = x;
    return true;
}
