class Obj {
  public:
    char pad[0x20];
    int m20;
    bool Set(int x);
};
bool Obj::Set(int x) {
    m20 = x;
    return true;
}
