class Thing {
  public:
    char pad[0x64];
    int value;
    bool Set(int x);
};
bool Thing::Set(int x) {
    value = x;
    return true;
}