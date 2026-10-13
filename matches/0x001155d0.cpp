class Obj {
  public:
    bool Set(int v);
    char pad[0x1c];
    int field;
};
bool Obj::Set(int v) {
    field = v;
    return true;
}
