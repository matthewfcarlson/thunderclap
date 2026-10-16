class Thing {
  public:
    char pad[16];
    int value;
    bool Set(int x);
};
bool Thing::Set(int x) {
    value = x;
    return true;
}