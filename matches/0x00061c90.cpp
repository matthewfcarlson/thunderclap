class Obj {
  public:
    char pad[0xc4];
    int m1c4;
    bool Set(int x);
};
bool Obj::Set(int x) {
    m1c4 = x;
    return true;
}
