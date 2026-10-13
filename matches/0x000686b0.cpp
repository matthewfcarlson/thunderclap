class Obj {
  public:
    char pad[0x70];
    int field;
    bool Set(int x);
};
bool Obj::Set(int x) {
    field = x;
    return true;
}
