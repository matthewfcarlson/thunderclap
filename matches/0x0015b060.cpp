class C_15b060 {
  public:
    char pad[0x5c];
    int value;
    bool Set(int x);
};
bool C_15b060::Set(int x) {
    value = x;
    return true;
}