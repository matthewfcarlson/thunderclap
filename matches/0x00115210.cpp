class Obj {
  public:
    char pad[0x14];
    int value;
    bool Set(int x);
};
bool Obj::Set(int x) {
    value = x;
    return true;
}