class Obj {
  public:
    char pad[0x20];
    int field;
    bool Fn(int x);
};
bool Obj::Fn(int x) {
    field = x;
    return true;
}
