class Obj {
  public:
    char pad[0x4c];
    int value;
    bool Set(int x);
};
bool Obj::Set(int x) {
    value = x;
    return true;
}
