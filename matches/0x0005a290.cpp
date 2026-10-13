class Obj {
  public:
    char pad[0x38];
    int m38;
    bool Set(int v);
};
bool Obj::Set(int v) {
    m38 = v;
    return true;
}
