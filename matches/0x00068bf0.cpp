class Obj {
  public:
    char pad[0x18];
    int field;
    bool Set(int v);
};
bool Obj::Set(int v) {
    field = v;
    return true;
}
