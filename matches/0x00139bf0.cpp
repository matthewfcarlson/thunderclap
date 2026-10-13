class Obj {
  public:
    char pad[0x24];
    int m24;
    bool Set(int v);
};
bool Obj::Set(int v) {
    m24 = v;
    return true;
}
