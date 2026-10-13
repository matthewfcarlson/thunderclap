class Obj {
  public:
    char pad[0xc];
    int value;
    bool Set(int x);
};
bool Obj::Set(int x) {
    value = x;
    return true;
}
