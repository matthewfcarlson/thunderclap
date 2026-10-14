class C {
  public:
    char pad[0x5c];
    int value;
    bool Set(int x);
};
bool C::Set(int x) {
    value = x;
    return true;
}