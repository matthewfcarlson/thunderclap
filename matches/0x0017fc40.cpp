class T {
  public:
    char pad[0x10];
    int value;
    bool Set(int x);
};
bool T::Set(int x) {
    value = x;
    return true;
}
