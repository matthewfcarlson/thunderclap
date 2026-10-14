class Obj {
  public:
    char pad[0xd4];
    int value;
    bool Set(int x);
};
bool Obj::Set(int x) {
    value = x;
    return true;
}
