class Thing {
  public:
    char pad[12];
    int value;
    bool Set(int v);
};
bool Thing::Set(int v) {
    value = v;
    return true;
}